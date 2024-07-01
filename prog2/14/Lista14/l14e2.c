#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define NUM_MAX 10

int main()
{
    int pos, vet[N], tamanho, i;
    tamanho = N;
    srand(time(NULL));
    for(i=0; i<N; i++)
        vet[i] = rand()%(NUM_MAX + 1);
    for(i=0; i<tamanho; i++)
            printf("%d  ", vet[i]);
    printf("\n");
    scanf("%d", &pos);
    while(pos>=0 && pos<tamanho && tamanho>0)
    {
        for(i=pos; i<tamanho-1; i++)
            vet[i] = vet[i+1];
        tamanho--;
        for(i=0; i<tamanho; i++)
            printf("%d  ", vet[i]);
        printf("\n");
        if(tamanho > 0)
            scanf("%d", &pos);
    }
    return 0;
}
