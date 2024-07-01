#include <stdio.h>

int main()
{
    int n, i = 1;
    printf("n = ");
    scanf("%d", &n);
    printf("\nwhile:\n");
    while(i <= 10)
    {
        printf("%d ", n+i);
        i++;
    }
    printf("\n\nfor:\n");
    for(i = 1; i <= 10; i++)
        printf("%d ", n+i);
    printf("\n");
    return 0;
}
