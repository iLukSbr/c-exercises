#include <stdio.h>

int main()
{
    int min, max, val, faixa = 0, min_lido, max_lido;
    printf("min = ");
    scanf("%d", &min);
    if(min < 0)
        return 0;
    printf("max = ");
    scanf("%d", &max);
    if(max < 0)
        return 0;
    printf("\n");
    scanf("valor:\n");
    scanf("%d", &val);
    min_lido = max_lido = val;
    while(val >= 0)
    {
        if(val >= min && val <= max)
        {
            faixa++;
            if(val < min_lido)
                min_lido = val;
            if(val > max_lido)
                max_lido = val;
        }
        scanf("%d", &val);
    }
    if(!faixa)
        printf("\nErro.");
    else
        printf("%d valores na faixa. Minimo = %d. Maximo = %d.", faixa, min_lido, max_lido);
    return 0;
}
