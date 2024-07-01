#include <stdio.h>

int main()
{
    int n, i;
    char c = 'A';
    printf("n = ");
    scanf("%d", &n);
    printf("\n");
    for(i = 0; i < n; i++)
        printf("%c", c + i);
    printf("\n");
    return 0;
}
