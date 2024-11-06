<H2>Falling_Port<H2
                                                   :=:                                      
                                              -+@@#:                                     
                                              ..:=*#-                                    
                        ::::                       -+=:.                                 
                      .*%@=:                        -:.::.                               
                      .-#%=*:                        -=.---                              
                         :=+#*:                       .+##*+          ....:.             
                            +#**-                       +:-*.        .:.:-:-=:           
                             =#=:-:                    ..: ==       ..:=++*+=*=          
                              :===*+       .:--=.      :   -=      .:--===*=#*+=         
                                :+##+:...+*#+--.*-     :   :=      -.=--===:-+++=        
                                  -++-  ..=-=*-. :-  =- ..:*+     -.:=--+=:::.=*+=       
          :-:::.                    ==-.    .=+-..  -#=. :+#@    :::++===::-::.++==      
        -======+*++:                 :+=+===+-+#*+:. ...    ::   +--+=*==--:-::+**+-     
       -=++=====*=-+==:             :*####**== -:::      .   +  --+*+*+=--::::=--*+=-    
      -++==--++++=+==-==-:          .+*+**#@@#%#*#=-     :+.  ----#+***+--..:----:+**    
     -+===+-+****+++==+==:-.        :#%##++*%@#@@@@#+=:.     ::=+******=-==-:-+=::-+-.   
    -===+**#%%#%###**#==--:-=-.      +*#%#+=#@@@@@#*+-.       :*@%%#*++=::-+#+++:-.+-:   
   :=+***#*%##**#####****+=+++++-::-:-+%%#**#@@@@%*=:.  :      =@@@%#*====-+==:------:   
  .==*+=*=#+=+=#*+#%%%%#**##***********#%%%@%%%%%@@*-.:*: :     #@@%*#*+==+*=-=-=-=--:   
  :**+#:*-#=-+=**+#=*+##%####*####*%%%%%%@@@@@@@@@@@*:..+::: .  *@#***+-*+====--*---+:   
  :*=*++==-*-=+=+++==:++*#+*##*#####%%%%@@@@@@@@@@@@@#=-:- :  . +@%#+#+#==+===+=+:+++-   
  :*-*-%+##%###==*-=-+=#-++===+++##%%%%#%%@@%@@@@@@@@@+-:==-=-:.*%#+++-:-::       ..-:   
  .+*+***#%#%#%#**+=-++*+=+*+***++#**######%#%%@@%@@@#:  :=*:  #+==-:.:             :-   
   =+==++***#****#*++=****=*=*++*-*+=*+#*#*#*%#%%%@@*:   ..+= -#-:                  .=   
   *-=++-**=#**#=+*=#*+++*+**+*=+*=+==**##*+*++#+%%+.    : -#:@* :                       
   +:=--===+***#-=*-*===:=====-+-=-=--=----... -%%=.     ..###+=:.                       
   +=--+--:--:---:.                          .@#=.     .::.%#-..+  .                      
   -=:-==-:::                                ##-    :+=.  +#--.: .                       
   -+:..                                    =#:   -##:     %=-:  .                       
   =:                                       #=  =%%=       +%++. .                       
                                          :*#+*@*:         .@*+ .                        
                                        :+=*=##:        .-=+#%- .                        
                                       :+--#%=     :+=.-++#+++=-                         
                                      .+:-+-.   .=##+=+*##**+=:.                         
                                      +:== -#*+#%###*#+---:.                             
                                     ==##:*@**+=--:.                                     
                                    +#%=  *%#.                                           
                                   +*-   .%%.                                            
                                 .**=    .@+                                             
                                 *::.     .                                              
                                *-:                                                      
                                +.                                                       
                                                                                                          
                                                              
Descrição

Falling_Port é um scanner de portas simples desenvolvido em C. Ele permite que você verifique se determinadas portas de um host estão abertas ou fechadas. A ferramenta foi projetada para ser rápida e eficiente, com a capacidade de escanear múltiplas portas simultaneamente.
Funcionalidades

    Verifica portas específicas em um host.
    Exibe se as portas estão abertas ou fechadas.
    Interface simples de linha de comando.

Requisitos

    Sistema operacional baseado em Linux.
    GCC (Compilador de C).
    Acesso ao terminal com permissões para executar o programa.

Como Compilar

    Clone o repositório:

git clone https://github.com/Marlon009/Falling_Port.git

Acesse a pasta do projeto:

cd Falling_Port

Compile o código com o GCC:

    gcc -o scanner scanner.c

Como Usar

    Após compilar o código, execute o scanner com:

./scanner <endereco IP> <porta_inicial> <porta_final>

Exemplo:

    ./scanner 192.168.1.1 80 90

    O scanner irá verificar as portas no intervalo entre a porta inicial e a final fornecida e mostrará os resultados.

Contribuindo

    Faça o fork do repositório.
    Crie uma branch para a sua feature:

git checkout -b nova-feature

Comite suas alterações:

git commit -am 'Adiciona nova feature'

Faça o push para a branch:

    git push origin nova-feature

    Abra um pull request.

Licença

Este projeto está sob a licença MIT - veja o arquivo LICENSE para mais detalhes.
