#include <stdio.h>

int main()
{
    int n1, n2, q=0;
    printf("N1 = ");
    scanf("%d", &n1);
    printf("N2 = ");
    scanf("%d", &n2);
    while(n1>=n2){
        q++;
        n1 -= n2;
    }
    printf("Quociente = %d\n", q);
    printf("Resto = %d", n1);
    return 0;
}
