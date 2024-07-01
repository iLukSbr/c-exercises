#include <stdio.h>

int main()
{
    int c, pista, termino;
    printf("C = ");
    scanf("%d", &c);
    printf("\nPista = ");
    scanf("%d", &pista);
    printf("\nTermino = %d\n", c%pista);
    return 0;
}
