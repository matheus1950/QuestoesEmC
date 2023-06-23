/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main(){

long i = 1, j = 2;
long sum = 0;


while(4000000 >= i && 4000000 >= j){
    if(i % 2 == 0){
        sum += i;
    }

    if(j % 2 == 0){
        sum+=j;
        
    }

    i= i+j;
    j= j+i;
    printf("soma: %li", sum);
}

return 0;
}



