#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 30
#define MIN -40
#define MAX 40

int main()
{
    int i, pos=0, media=0, maior=0, menor=0, igual=0;
    float num[N];
    srand(time(NULL));
    for(i=0; i<N; i++)
    {
        num[i] = (rand()/(float)RAND_MAX)*(MAX - MIN) + MIN;
        if(num[i] > 0)
        {
            media += num[i];
            pos++;
        }
        else
            num[i] = -1;
    }
    if(pos > 0)
        media /= pos;
    for(i=0; i<N; i++)
    {
        if(num[i] >= 0)
        {
            if(num[i] > media)
            {
                maior++;
                printf("%f maior\n", num[i]);
            }
            else if(num[i] < media)
            {
                menor++;
                printf("%f menor\n", num[i]);
            }
            else
            {
                igual++;
                printf("%f igual\n", num[i]);
            }
        }
    }
    printf("\n%d maiores, %d iguais e %d menores\n", maior, igual, menor);
    return 0;
}
