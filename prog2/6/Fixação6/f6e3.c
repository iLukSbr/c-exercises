#include <stdio.h>

int main()
{
    int n, i = 1;
    printf("n = ");
    scanf("%d", &n);
    printf("\nwhile:\n");
    while(i <= 10)
    {
        printf("%d ", i*n);
        i++;
    }
    printf("\n\nfor:\n");
    for(i = 1; i <= 10; i++)
        printf("%d ", i*n);
    printf("\n");
    return 0;
}
