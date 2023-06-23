/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main()
{
    int casa1, casa2, casa3, casa4, casa5, casa6;
    int palindromo = 0, n, n1, n2;

for(n1 = 100; n1 <= 999; n1++){
    
    for(n2 = 100; n2 <= 999; n2++){
        
        n = n1 * n2;
        
        if(n < 99999){
            casa1 = n/10000;
            
            casa2 = (n % 10000)/1000;
            
            casa3 = (n % 1000)/100;
            
            casa4 = (n % 100)/10;
            
            casa5 = n % 10;
            
            
            if(casa1 == casa5 && casa2 == casa4){
                if(n > palindromo){
                    palindromo = n;
                }
            }   
        }
        
       else{
            casa1 = n/100000;
            
            casa2 = (n % 100000)/10000;
            
            casa3 = (n % 10000)/1000;
            
            casa4 = (n % 1000)/100;
          
            casa5 = (n % 100)/10;
            
            casa6 = n % 10;
           
            
            if(casa1 == casa6 && casa2 == casa5 && casa3 == casa4){
                if(n > palindromo){
                    palindromo = n;
                }
            }
        }
    }
}

printf("O último palindromo(3digitos * 3digitos) é: %i\n", palindromo);

    return 0;
}
