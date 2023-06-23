/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int soma3 = 0, soma5 = 0;
    int i;
    
    for(i = 0; i < 100; i+=3){
        soma3 += i;
        printf("soma 3 = %i\n", soma3);
    }
    
    for(i = 0; i < 100; i+=5){
        soma5 += i;
        printf("soma 5 = %i\n", soma5);
    }
    
    printf("Soma total = %i", soma3 + soma5);

    return 0;
}
