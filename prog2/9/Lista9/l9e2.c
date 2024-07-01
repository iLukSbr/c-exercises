#include <stdio.h>
#define N 5

int main(){
    int i=1, j=0, n=3, flag=0, soma=0;
    if(N >= 1)
    {
        printf("2 ");
        soma += 2;
        j++;
    }
    while(j < N)
    {
        for(i=3; i<n; i+=2)
        {
            if(n%i == 0 || n%2 == 0)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            printf("%d ", n);
            soma += n;
            j++;
        }
        n++;
        flag = 0;
    }
    printf("\n\nSoma = %d\n", soma);
    return 0;
}
