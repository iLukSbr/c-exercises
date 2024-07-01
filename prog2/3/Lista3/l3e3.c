#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("Primeiro numero = ");
    scanf("%d",&n1);
    printf("Segundo numero = ");
    scanf("%d",&n2);
    printf("Terceiro numero = ");
    scanf("%d",&n3);
    if (n1 > n2 && n1 > n3)
        printf("Maior = %d", n1);
    else if (n2 > n1 && n2 > n3)
        printf("Maior = %d", n2);
    else
        printf("Maior = %d", n3);
    return 0;
}
