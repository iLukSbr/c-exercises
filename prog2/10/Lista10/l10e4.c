#include <stdio.h>

unsigned long long potencia (unsigned int base, unsigned int expoente);

int main()
{
    unsigned int b, e;
    printf("Base = ");
    scanf("%d", &b);
    printf("Expoente = ");
    scanf("%d", &e);
    printf("%ld", potencia(b, e));
    return 0;
}

unsigned long long potencia (unsigned int base, unsigned int expoente)
{
    int potencia = 1;
    while(expoente>0)
    {
        potencia *= base;
        expoente--;
    }
    return potencia;
}
