<H2>Falling_Port<H2
'
                                   7                                  
                                    72981                             
                                    148867                            
                   7711                72627                          
                  58021                  213317                       
                  758597                 7353557                      
                    738867                778963       371537         
                      766257               731267     321225427       
                       755542     777577   773767    3124594665       
                         7499537196632817 7377157   7235255356557     
                           1657 71265372179723497  75352243313662     
       725524317  7         752311172913716317391  1154452353356417   
      1555244426217          74992351425777717 72776544455323324641   
     1454236654622337       726698089542377  72772478949253351524947  
    7452556466544455221     768695608000945377 731546466542234523427  
   752469899898656625225377  54906290008643777   3908964531966435527  
  724646696966988964456625546499969900884217577  7600895524422222527  
  749626452944499689686896980880000800000411813177308695644222242667  
  195925423346455166968989999688000000000043133177398694644444692661  
  79529688892265665222564550888900800000000446242220865322977   7721  
  766666988899662666666945696599968988000067726471924577       7 731  
  75545446996668654965665424656949698088041  77676217        77   757 
  7424555569944645224444544255454645434847  723968337                 
  74225234494422652557172177777777  768577  778053417                 
  7655522121543777                 72847  73378673377 7               
  7555245517                       1057  163 79423777                 
  75477                           792 71097   1822777         7       
  757                       7     3823097     786471                  
                        77      74920877   77772857                   
                   77          742683   72275664452                   
                       77     753417 7788456864665                    
                             762614066998943317                       
                            759827892777 77                           
                            2927 401         7                        
                           461  799                                   
                          4337   77                                   
                         241                                          
                         17       
                                       
                                                                                                                                                                            
Descrição:

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

