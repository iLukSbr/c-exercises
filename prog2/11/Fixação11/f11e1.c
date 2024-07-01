#include <stdio.h>

#define N_TERMOS 10

int ehPrimo (int numero)
{
    int i, metade = numero/2;
    if (numero == 2)
        return (1);

    if (!(numero % 2))
        return (0);

    for (i = 3; i <= metade; i += 2)
        if (!(numero % i))
            return (0);

    return (1);
}

int main ()
{
    int n_encontrados = 0;
    int n = 2;

    while (n_encontrados < N_TERMOS)
    {
        if (ehPrimo (n))
        {
            printf ("%d\n", n);
            n_encontrados++;
        }
        n++;
    }
    return (0);
}
