#include <stdio.h>

#define N_TERMOS 99999999

int main()
{
    int i, j=3;
    float pi=1;
    for(i=1; i<N_TERMOS; i++){
        if(i%2 == 0)
            pi += 1.0/j;
        else
            pi -= 1.0/j;
        j += 2;
    }
    pi = 4*pi;
    printf("Pi = %f", pi);
    return 0;
}
