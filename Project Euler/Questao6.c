/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    int soma_quad = 0, quad_soma = 0, i;
    
    for(i = 1; i <= 100; i++){
        soma_quad += pow(i, 2);
        printf("A soma dos quadrados é: %i\n", soma_quad);
    }
    
    for(i = 1; i <= 100; i++){
        quad_soma += i;
        printf("A soma é: %i\n", quad_soma);
    }
    
    quad_soma = pow(quad_soma, 2);
    
    printf("A diferença entra o quadrado da soma e a soma dos quadrados é: %i", quad_soma - soma_quad);

    return 0;
}
