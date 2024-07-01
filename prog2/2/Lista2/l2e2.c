#include <stdio.h>
#include <math.h>

int main ()
{
    float raio;
    printf("Raio = ");
    scanf("%f", &raio);
    printf("Volume da esfera = %f", (4./3)*M_PI*pow(raio,3));
    return 0;
}
