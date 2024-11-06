Falling_Port - Port Scanner

                                      .&x                               
                                     &&&&+                              
                      :                  &+                             
                   X&&.                   .x;&                         
                    &.&                    :.X                         
                      &&&                   &X&&        +.. .          
                       &&;&                  & X       .&.&. +         
                        :&.X.               .  $&        &&X&;:        
                          &.&&    &;& &     X  .&     ; .:.&&&&x       
                            &&   ;& &+  $  & : .&    & &  & . $&:      
         ::x                 &+;    .& .  &x+ :&&     &&&&&.X  &$.     
       ++.:+&&&+$             . &;;.:&&x:X.:+    .  &.X:x &;x.&.&+:    
      ;$.X&..x&.x&.          &&:&&&&X &.+     . .& & &&&X&:.. &;;& :   
     &x.&.&X&..X.&;&.&        &&&+&&&&&&;;. $..:  &.&&& ;&;$  .&:.+;   
    &:$:&&&&x&&&&&.&..$:      &&X&x:&&&&&+;. .    &&&X$&;. & $&&$ :.   
    &:&&&&&X&x&&$$&+. &+:&&    &x&&x&&&&&:.. x     &&&&&.:+x&+ ;.&+&   
   ..&&&.&Xx:&&;&&&$.&&&&&&& &;&&&&&&&&&&&.&.;.  . &&&X:&.xx&+&&& .$   
   &.& &:. &&&.&:X&&&&.+&;&&X&&&&&&&&&&&&& : $ ..+ X&&::$;..x& &&..&   
   & &&.X&..+.+.+ &.+&&:.&&:.&&&&&&&&&&&&&&&...    &&&&&+&x.&X&: &..   
   &:X&&&X&x&&&.&&.&:&&x& X:&$&:&&&x;&&&&&&&.: ;.. $.& &x          +   
   $;;X$&&$&&&&&.&X.X+&$;&&:;&&&&$&&&&&&&&X.  & & &.               &   
   $&&+ :.&&.X&X.&&&$.+&:.&$&x$&&&.&&x$&&xX   & &.& .                  
   x&+.+X.&&&. &&;+&&&.&:&.&& ;&&&.   &&::   . .&&+:                   
   .:&..&..;...& &.                  +$&.    .&&&.X+                   
   &x&.x& ; :                        &x    .x .X.+&                    
   XX.&                             &X    &x   &&x$ :                  
   ;X                              .&  .&&     x&:.                    
                                   &&&&&        &+.                    
                                 $:&+&        X&$&                     
                                $.&$x    +&x:&X&.X$                    
                               & .;    &&&&$&&$&x.                     
                              &;&.$&;$;&&&+                            
                             .&&; &&:                                  
                             &$   &&                                    
                           .$;    &                                    
                           X.                                           
                          &.                                            
                          .                                             
                                                                       
                           Falling_Port                                 
                                                                       
                 By: https://github.com/Marlon009      


Descrição

O Falling_Port é um scanner de portas simples, escrito em C, que permite aos usuários verificar o estado (aberta/fechada) de portas em um IP ou domínio especificado. Este projeto é útil para realizar análises de rede e segurança, facilitando a verificação do status de portas em um determinado intervalo.
Funcionalidades

    Recebe como entrada um IP ou domínio e um intervalo de portas a serem escaneadas.
    Retorna o status das portas (aberta ou fechada) dentro do intervalo especificado.
    Compatível com sistemas Windows e Linux.
Receberá atualizações em breve(como opção de fazer ataque DoS)


Como Usar

    Compilação: Compile o programa com o seguinte comando:

gcc scanner.c -o scanner -lcurl

Execução: Execute o programa com:

./scanner

Em seguida, insira o IP/domínio e o intervalo de portas que deseja escanear.

