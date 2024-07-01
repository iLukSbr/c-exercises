#include <stdio.h>

int main()
{
    int n, ingresso, i, ganhador = 0;
    printf("Participantes = ");
    scanf("%d", &n);
    printf("\nIngressos:\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &ingresso);
        if(ingresso == i && !ganhador)
            ganhador = ingresso;
    }
    if(ganhador)
        printf("\nGanhador = %d\n", ganhador);
    else
        printf("\nNinguem ganhou.\n");
    return 0;
}
