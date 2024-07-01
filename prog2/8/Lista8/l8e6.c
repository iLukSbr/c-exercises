#include <stdio.h>
#include <math.h>

int main()
{
    int n, inv=0, cont=1, i=10, j, aux, flag=0;
    printf("Numero = ");
    scanf("%d", &n);
    while(n/i != 0){
        cont++;
        i *= 10;
    }
    aux = n;
    j = cont-1;
    for(i=1; i<=cont; i++)
    {
        inv += (aux%10)*pow(10, j);
        aux /= 10;
        j--;
    }
    printf("%d\n",inv);
    for(i=1; i<=cont; i++)
    {
        printf("%d %d\n",inv%10,n%10);
        if(inv%10 != n%10)
        {
            flag = 1;
            break;
        }
        inv /= 10;
        n /= 10;
    }
    if(flag)
        printf("Nao e palindromo.");
    else
        printf("E palindromo.");
    return 0;
}
