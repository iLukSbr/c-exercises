#include <stdio.h>

int main()
{
    int n, i, j, k;
    char letra='A';
    printf("n = ");
    scanf("%d", &n);
    k = n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=k; j++)
        {
            printf("%c ", letra);
            letra++;
        }
        k--;
        printf("\n");
        letra = 'A';
    }
    return 0;
}
