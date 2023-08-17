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
