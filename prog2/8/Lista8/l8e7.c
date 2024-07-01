#include <stdio.h>

int main()
{
    int i, n, ant, atual, consec1=1, consec2=1;
    printf("Numero de valores sorteados = ");
    scanf("%d", &n);
    printf("Valores =\n");
    scanf("%d", &ant);
    for(i=1; i<n; i++)
    {
        scanf("%d", &atual);
        if(atual == ant)
            consec1++;
        else
        {
            if(consec1 > consec2)
                consec2 = consec1;
            consec1 = 1;
        }
        ant = atual;
    }
    printf("%d pontos", consec2);
    return 0;
}
