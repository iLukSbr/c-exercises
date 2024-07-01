#include <stdio.h>

int ehProgressaoAritmetica(int n1, int n2, int n3, int n4);

int main()
{
    int ano, pa, n1, n2, n3, n4;
    printf("Sequencia = ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    pa = ehProgressaoAritmetica(n1, n2, n3, n4);
    if(pa)
        printf("\nE PA, razao = %d.\n", pa);
    else
        printf("\nNao e PA.\n");
    return 0;
}

int ehProgressaoAritmetica(int n1, int n2, int n3, int n4)
{
    if(((n2 - n1) == (n3 - n2)) && ((n4 - n3) == (n3 - n2)) && ((n2 - n1) != 0))
        return n2 - n1;
    else
        return 0;
}
