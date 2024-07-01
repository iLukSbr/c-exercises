#include <stdio.h>
#define N 6

int eliminaRepetidos(int *entrada, int *saida);

int main()
{
    int entrada[]={0, 1, 2, 4, 0, 1}, saida[N], i, unicos;
    unicos = eliminaRepetidos(entrada, saida);
    printf("\nElementos da saida = %d\n", unicos);
    for(i=0; i<unicos; i++)
        printf("%d", saida[i]);
    return 0;
}

int eliminaRepetidos(int *entrada, int *saida)
{
    int unicos=0, i, j, tem=0, tem_0=0;
    for(i=0; i<N; i++)
    {
        tem=0;
        for(j=0; j<unicos; j++)
            if(saida[j] == entrada[i])
                tem = 1;
        if(!tem)
            saida[unicos++] = entrada[i];
    }
    return unicos;
}
