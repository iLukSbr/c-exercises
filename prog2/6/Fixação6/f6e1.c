#include <stdio.h>
#define N 10

int main()
{
    int i = 0;
    printf("while:\n");
    while(i <= N)
    {
        printf("%d ", i);
        i++;
    }
    printf("\n\nfor:\n");
    for(i = 0; i <= N; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
