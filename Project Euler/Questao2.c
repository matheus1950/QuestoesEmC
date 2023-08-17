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



