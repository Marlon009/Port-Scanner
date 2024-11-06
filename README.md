<H2>Falling_Port<H2
                                                                                                              
                                                                                       
                                       772667                                
                                       7380047                               
                       77                7139917                             
                    73927                   742337                           
                   760845                    7413337                         
                     186647                   745525         7777            
                       769957                  728667       7372331          
                         282527                 147547     7221225457        
                          144261      773177    377267    723244966647       
                           7249957 726963267   1377347    2152544249457      
                             7645771287647751 73117567   31123343112642      
         711177               73447   7567177305716007   334546332313442     
       7442254645177            76455296699937137  731  15126422232359641    
      744444646654257          72988892271117   777 7677626946333212526557   
     756425465452623223        7344698089854577  762 741394496251315533492   
    7255245666946926222237     768994480600086427  71234566644242536523262   
   735546989888889664252355177  5468924000086427 77   290899563239665321657  
   1564449999669689664424655456669986668088863773777  790089452454252535227  
  7456434665654499990669969889996980080880000412932771710888664264523552357  
  7694453632264592549989964989698698000000000023741313718899462454425645267  
  7456463466566545252664565996988980880008000006523117738866952544333116257  
   45469888899952224424644564698888880000000000213542515996544177    7  727  
   564466989998942559645949942962899699998000067 71447261277            727  
   22444464994644996466546556444549996699890851  731878211               717 
   2154544466646436422545442542454566953218847   775989231                   
   2352553469525534425271777177777777   788577  7130023437                   
   22524233236641777                   788477  73568473277 77                
   325352414177                        38277 72517285227 1  7                
   15327                              7847  2047   6423 71                   
   357                         7      55772087     2045727                   
   7                      77        73068097       706277                    
                                  73645981 7  77735698377                    
                                  1525847  7742126644563                     
                          7      7515271 72886468994652                      
                                7934338899999962337                          
                               7248619983177 77                              
                       7       2991 7897         77                          
                             7292  7502                                      
                             2451   747                                      
                            3637                                             
                           7917                                              
                            77                                               
                                                                                                                             
                                                                                                                 
                                                                                                          
                                                              
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
