#include <stdio.h>

int main()
{
    int i, num, soma=0;
    printf("Numero = ");
    scanf("%d", &num);
    for(i=1; i<num && soma<=num; i++){
        if(num%i == 0)
            soma += i;
    }
    if(soma != num)
        printf("Nao e perfeito.");
    else
        printf("E perfeito.");
    return 0;
}
