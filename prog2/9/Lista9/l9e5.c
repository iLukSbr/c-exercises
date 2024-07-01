#include <stdio.h>

int main()
{
    char c;
    int i, j, k, n;
    printf("c = ");
    scanf("%c", &c);
    printf("n = ");
    scanf("%d", &n);
    for(i=0; i<=n; i++)
    {
        for(j=0; j<n-i; j++)
            printf(" ");
        for(k=0; k<=2*i; k++)
            printf("%c", c);
        printf("\n");
    }
    for(i=n; i>0; i--)
    {
        for(j=n-i+1; j>0; j--)
            printf(" ");
        for(k=2*i-2; k>=0; k--)
            printf("%c", c);
        if(i > 1)
            printf("\n");
    }
    return 0;
}
