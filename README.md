# Falling Port v2

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)

Ferramenta avançada para análise de rede, incluindo scanner de portas SYN e ataque DoS básico, com suporte para IPv4 e IPv6.

![port](https://github.com/user-attachments/assets/ad68b371-73db-4a15-97a8-8daa486e5149)


## 🚀 Recursos
- Scanner de portas SYN (IPv4 e IPv6)
- Ataque DoS básico (IPv4 e IPv6)
- Resolução de DNS automática
- Checksum TCP calculado manualmente
- Interface simples e intuitiva
- Cross-platform (Windows/Linux)

## 📦 Instalação

### Pré-requisitos
bash
# Linux
sudo apt install build-essential

# Windows
# Instale o MinGW ou WSL
Compilação
bash
Copy
# Linux
gcc -o falling_port falling.c -lpthread -O3

# Windows (MinGW)
gcc -o falling_port.exe falling.c -lws2_32 -O3
🛠 Como Usar
Modo Scanner
bash
Copy
./falling_port
1. Scan IPv4
Alvo: example.com
Porta inicial: 1
Porta final: 1024
Modo DoS
bash
Copy
./falling_port
3. Ataque DoS IPv4
Alvo: 192.168.1.1
Porta: 80
🧩 Funcionalidades
Scanner de Portas
Característica	Descrição
Protocolo	TCP SYN
Suporte IP	IPv4 e IPv6
Resolução DNS	Automática
Checksum	Calculado manualmente
Ataque DoS
Característica	Descrição
Método	Flood SYN
Suporte IP	IPv4 e IPv6
Intensidade	Máximo possível
⚠️ Aviso Legal
Este software destina-se exclusivamente para:

Testes de segurança autorizados

Pesquisa em redes próprias

Estudos acadêmicos

É estritamente proibido utilizar esta ferramenta para quaisquer atividades ilegais ou não autorizadas.

📄 Licença
Distribuído sob licença GPL-3.0. Veja o arquivo LICENSE para mais detalhes.

👨💻 Desenvolvedor
Marlon - GitHub

🙌 Contribuição
Contribuições são bem-vindas! Abra um issue ou pull request para:

Reportar bugs

Sugerir melhorias

Adicionar novas funcionalidades

Nota: Mantenha sempre autorização por escrita para qualquer teste em redes de terceiros.
