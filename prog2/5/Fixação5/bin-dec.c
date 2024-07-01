#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int i, aux, bin, pot = 0, exp = 0, decimal = 0;
    printf("Binario = ");
    scanf("%d", &bin);
    aux = bin;
    while (aux > 1)
    {
        aux /= 10;
        exp++;
    }
    decimal += pow(2, exp);
    bin -= pow(10, exp);
    while (bin > 1)
    {
        aux = bin;
        exp = 0;
        while (aux > 1)
        {
            aux /= 10;
            exp++;
        }
        decimal += pow(2, exp);
        bin -= pow(10, exp);
    }
    if (bin == 1)
        decimal++;
    printf("Decimal = %d", decimal);
    return 0;
}
