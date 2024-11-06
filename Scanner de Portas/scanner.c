#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <curl/curl.h>


#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket close
    typedef int SOCKET;
#endif

// Função para escanear uma porta específica
int scan_port(const char *ip, int port) {
    SOCKET sock;
    struct sockaddr_in server;

    // Cria um socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("Não foi possível criar o socket\n");
        return 0;
    }

    // Configurações do servidor
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Tenta conectar na porta
    int connect_status = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (connect_status == 0) {
        // Porta está aberta
        closesocket(sock);  // Fecha o socket após a conexão bem-sucedida
        return 1;  // Retorna 1 se a porta estiver aberta
    } else {
        // Porta está fechada
         #ifdef _WIN32
            printf("Houve um erro ao se conectar na porta %d: %d\n", port, WSAGetLastError());
        #else
            printf("Houve um erro ao se conectar na porta %d: %s\n", port, strerror(errno));
        #endif
        closesocket(sock);
        return 0;  // Retorna 0 se a porta estiver fechada
    }
}

int main() {
    char host[100];
    int initial_port, final_port, port;
    struct hostent *he;
    struct in_addr **addr_list;

    #ifdef _WIN32
        WSADATA wsa;
        // Inicializa o Winsock
        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
            printf("Falha ao inicializar o Winsock. Código de erro: %d\n", WSAGetLastError());
            return 1;
        }
        printf("Winsock inicializado.\n");
    #endif
        printf(
        "\n"
        "                                      .&x                               \n"
        "                                     &&&&+                              \n"
        "                      :                  &+                            \n"
        "                   X&&.                   .x;&                         \n"
        "                    &.&                    :.X                         \n"
        "                      &&&                   &X&&        +.. .          \n"
        "                       &&;&                  & X       .&.&. +         \n"
        "                        :&.X.               .  $&        &&X&;:        \n"
        "                          &.&&    &;& &     X  .&     ; .:.&&&&x       \n"
        "                            &&   ;& &+  $  & : .&    & &  & . $&:      \n"
        "         ::x                 &+;    .& .  &x+ :&&     &&&&&.X  &$.     \n"
        "       ++.:+&&&+$             . &;;.:&&x:X.:+    .  &.X:x &;x.&.&+:    \n"
        "      ;$.X&..x&.x&.          &&:&&&&X &.+     . .& & &&&X&:.. &;;& :   \n"
        "     &x.&.&X&..X.&;&.&        &&&+&&&&&&;;. $..:  &.&&& ;&;$  .&:.+;   \n"
        "    &:$:&&&&x&&&&&.&..$:      &&X&x:&&&&&+;. .    &&&X$&;. & $&&$ :.   \n"
        "    &:&&&&&X&x&&$$&+. &+:&&    &x&&x&&&&&:.. x     &&&&&.:+x&+ ;.&+&   \n"
        "   ..&&&.&Xx:&&;&&&$.&&&&&&& &;&&&&&&&&&&&.&.;.  . &&&X:&.xx&+&&& .$   \n"
        "   &.& &:. &&&.&:X&&&&.+&;&&X&&&&&&&&&&&&& : $ ..+ X&&::$;..x& &&..&   \n"
        "   & &&.X&..+.+.+ &.+&&:.&&:.&&&&&&&&&&&&&&&...    &&&&&+&x.&X&: &..   \n"
        "   &:X&&&X&x&&&.&&.&:&&x& X:&$&:&&&x;&&&&&&&.: ;.. $.& &x          +   \n"
        "   $;;X$&&$&&&&&.&X.X+&$;&&:;&&&&$&&&&&&&&X.  & & &.               &   \n"
        "   $&&+ :.&&.X&X.&&&$.+&:.&$&x$&&&.&&x$&&xX   & &.& .                  \n"
        "   x&+.+X.&&&. &&;+&&&.&:&.&& ;&&&.   &&::   . .&&+:                   \n"
        "   .:&..&..;...& &.                  +$&.    .&&&.X+                   \n"
        "   &x&.x& ; :                        &x    .x .X.+&                    \n"
        "   XX.&                             &X    &x   &&x$ :                  \n"
        "   ;X                              .&  .&&     x&:.                    \n"
        "                                   &&&&&        &+.                    \n"
        "                                 $:&+&        X&$&                     \n"
        "                                $.&$x    +&x:&X&.X$                    \n"
        "                               & .;    &&&&$&&$&x.                     \n"
        "                              &;&.$&;$;&&&+                            \n"
        "                             .&&; &&:                                  \n"
        "                             &$   &&                                    \n"
        "                           .$;    &                                    \n"
        "                           X.                                           \n"
        "                          &.                                            \n"
        "                          .                                             \n"
        "                                                                         \n"
        "                           Falling_Port                                  \n"
        "                                                                         \n"
        "                 By: https://github.com/Marlon009\n"  
         "                                                                         \n" );
    // Entrada do usuário
    printf("Digite o endereço IP ou o domínio a ser escaneado: ");
    scanf("%s", host);

    // Resolve o nome do host para obter o IP
    if ((he = gethostbyname(host)) == NULL) {
        printf("Erro ao resolver o nome do host\n");
        #ifdef _WIN32
            WSACleanup();
        #endif
        return 1;
    }

    addr_list = (struct in_addr **)he->h_addr_list;
    char *ip = inet_ntoa(*addr_list[0]);
    printf("Escaneando IP: %s\n", ip);

    // Intervalo de portas para escanear
    printf("Digite a porta inicial: ");
    scanf("%d", &initial_port);
    printf("Digite a porta final: ");
    scanf("%d", &final_port);

    // Escaneia portas no intervalo especificado
    for (port = initial_port; port <= final_port; port++) {
        if (scan_port(ip, port)) {
            printf("Porta %d está aberta\n", port);
        } else {
            printf("Porta %d está fechada\n", port);
        }
    }

    #ifdef _WIN32
        // Finaliza o Winsock
        WSACleanup();
    #endif

    return 0;
}
