#include <stdio.h>
#include <math.h>

int main()
{
    int i, aux, decimal, pot = 0, exp = 0, bin = 0;
    printf("Decimal = ");
    scanf("%d", &decimal);
    while (pot < decimal)
    {
        exp++;
        pot = pow(2, exp);
    }
    if (pot > decimal)
    {
        exp--;
        pot = pow(2, exp);
    }
    while (exp >= 0)
        {
            if (decimal >= pot)
            {
                bin += pow(10, exp);
                decimal -= pot;
            }
            exp--;
            pot = pow(2, exp);
        }
    printf("Binario = %d", bin);
    return 0;
}
