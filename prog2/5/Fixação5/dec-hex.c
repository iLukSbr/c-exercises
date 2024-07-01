#include <stdio.h>
#include <math.h>

int main()
{
    int i, decimal, aux, pot = 0, exp = 0, hex = 0;
    printf("Decimal = ");
    scanf("%d", &decimal);
    printf("\nHexadecimal = 0x");
    while (pot < decimal)
    {
        exp++;
        pot = pow(16, exp);
    }
    if (pot > decimal)
    {
        exp--;
        pot = pow(16, exp);
    }
    aux = (exp + 1)/4;
    if ((exp + 1)%4 != 0 || exp == 0)
        aux++;
    if ((exp + 1) < 4*aux)
        for (i = 4*aux; i > exp + 1; i--)
            printf("0");
    while (exp >= 0)
        {
            aux = decimal/pot;
            if (decimal < 16)
                aux = decimal;
            if (aux == 10)
                printf("A");
            else if (aux == 11)
                printf("B");
            else if (aux == 12)
                printf("C");
            else if (aux == 13)
                printf("D");
            else if (aux == 14)
                printf("E");
            else if (aux == 15)
                printf("F");
            else
                printf("%d", aux);
            decimal %= pot;
            exp--;
            pot = pow(16, exp);
        }
    return 0;
}
