#include <stdio.h>

#define TAM 100

int main()
{
    int n, a[TAM], i, soma=0, media;
    printf("N = ");
    scanf("%d", &n);
    if(n<2 || n>TAM)
        return 0;
    printf("\nTamanho =\n");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(i=0; i<n; i++)
    {
        soma += a[i];
    }
    media = soma/2;
    soma = 0;
    for(i=0; soma<media; i++)
    {
        soma += a[i];
    }
    printf("\nDivisao em %d.\n", i);
    return 0;
}
