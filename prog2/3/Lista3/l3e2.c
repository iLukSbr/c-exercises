#include <stdio.h>

int main()
{
    int n;
    printf("Numero inteiro 100-999 = ");
    scanf("%d", &n);
    printf("Invertido = %d", 100*(n%10) + (n-n%10)%100 + n/100);
    return 0;
}
