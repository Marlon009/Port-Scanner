<H2>Falling_Port<H2>
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

git clone https://github.com/seu-usuario/Falling_Port.git

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
