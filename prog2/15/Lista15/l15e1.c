#include <stdio.h>
#include <stdlib.h>
#define MAX_PEDRAS 100

int main()
{
    int pedras, sapos, i, j, inicio, pulo, pos[MAX_PEDRAS];
    printf("Pedras no rio = ");
    scanf("%d", &pedras);
    printf("\nSapos = ");
    scanf("%d", &sapos);
    printf("\n");
    for(i=0; i<pedras; i++)
        pos[i] = 0;
    for(i=0; i<sapos; i++)
    {
        scanf("%d %d", &inicio, &pulo);
        for(j=inicio; j<pedras; j+=pulo)
            pos[j] = 1;
        for(j=inicio-pulo; j>=0; j-=pulo)
            pos[j] = 1;
    }
    printf("\n");
    for(i=0; i<pedras; i++)
        printf("%d",pos[i]);
    printf("\n");
    return 0;
}
