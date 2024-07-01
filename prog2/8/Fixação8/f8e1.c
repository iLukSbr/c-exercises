#include <stdio.h>

int main ()
{
    unsigned int base, expoente;
    unsigned long long total = 1;

    scanf ("%u", &base);
    scanf ("%u", &expoente);

    while (expoente > 0)
    {
        total *= base;
        expoente--;
    }

    printf ("%llu\n", total);

    return (0);
}
