#include <stdio.h>

int main()
{
    int n, f=1;
    printf("Numero = ");
    scanf("%d", &n);
    while(n>1){
        f = f*n;
        n--;
    }
    if(n >= 0)
        printf("Fatorial = %d", f);
    else
        printf("Número inválido.");
    return 0;
}
