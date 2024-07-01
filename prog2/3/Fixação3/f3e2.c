#include <stdio.h>
#include <math.h>

int main ()
{
    float n;
    printf("Valor = ");
    scanf("%f", &n);
    if(n >= 0)
        printf("Raiz quadrada = %f", sqrt(n));
    else
        printf("Nao foi possivel calcular.");
    return 0;
}
