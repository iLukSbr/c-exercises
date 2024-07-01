#include <stdio.h>

int main()
{
    int n, i, j, k;
    char letra='A';
    printf("n = ");
    scanf("%d", &n);
    letra += n-1;
    k = n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=k; j++)
            printf("%c ", letra);
        k--;
        printf("\n");
        letra--;
    }
    return 0;
}
