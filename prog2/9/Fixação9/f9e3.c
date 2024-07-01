#include <stdio.h>

int main()
{
    int n, i, j;
    printf("n = ");
    scanf("%d", &n);
    for(i = n; i > 0; i--)
    {
        for(j = i; j > 0; j--)
            printf("A");
        printf("\n");
    }
    return 0;
}
