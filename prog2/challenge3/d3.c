#include <stdio.h>
#define N 10
#define MENOR 1
#define IGUAL 2
#define MAIOR 3

int main()
{
    unsigned int i=0, aux, informe, n, lim_sup=N, lim_inf=0;
    n = N/2;
    printf("1=menor; 2=igual; 3=maior.\n");
    if(informe == IGUAL)
        i = 1;
    while(informe != IGUAL)
    {
        printf("%d? ", n);
        if(lim_inf < lim_sup)
            scanf("%d", &informe);
        if(informe == MENOR && lim_inf < lim_sup)
        {
            if(n == 0)
            {
                i++;
                break;
            }
            lim_sup = n-1;
        }
        else if(informe == MAIOR && lim_inf < lim_sup)
        {
            if(n == N)
            {
                i++;
                break;
            }
            lim_inf = n+1;
        }
        aux = n;
        n = (lim_inf + lim_sup)/2;
        i++;
        if(n == aux)
            break;
        printf("%d %d\n",lim_inf,lim_sup);
    }
    printf("\nForam necessarios %d palpites.", i);
    return 0;
}
