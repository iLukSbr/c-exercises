#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 30
#define MIN 20
#define MAX 80

int main()
{
    int i, maior=0, menor=0, igual=0, num[N];
    float media=0;
    srand(time(NULL));
    for(i=0; i<N; i++)
    {
        num[i] = MIN + rand()%(MAX - MIN + 1);
        media += num[i];
    }
    if(N > 0)
        media /= N;
    for(i=0; i<N; i++)
    {
        if(num[i] > media)
        {
            maior++;
            printf("%d maior\n", num[i]);
        }
        else if(num[i] < media)
        {
            menor++;
            printf("%d menor\n", num[i]);
        }
        else
        {
            igual++;
            printf("%d igual\n", num[i]);
        }
    }
    printf("\n%d maiores, %d iguais e %d menores\n", maior, igual, menor);
    return 0;
}
