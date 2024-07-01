#include <stdio.h>

int main()
{
    int n, num, i, num_ant=0, num_ant2=0, picos=0;
    printf("Tamanho da sequencia = ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &num);
        if(num_ant2>num_ant && num>num_ant)
            picos = 1;
        num_ant2 = num_ant;
        num_ant = num;
    }
    printf("Tem apenas um pico = ");
    if(picos)
        printf("N");
    else
        printf("S");
    return 0;
}
