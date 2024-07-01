#include <stdio.h>

int main()
{
    int n, dig, aux=10, flag=0;
    printf("Numero = ");
    scanf("%d", &n);
    printf("Digito = ");
    scanf("%d", &dig);
    while(n>0 && flag==0)
    {
        if(n%aux == dig)
            flag = 1;
        n /= 10;
    }
    if(n<0 || dig<0)
        printf("Invalido.");
    else if(flag || n==0 && dig==0)
        printf("Presente.");
    else
        printf("Nao presente.");
    return 0;
}
