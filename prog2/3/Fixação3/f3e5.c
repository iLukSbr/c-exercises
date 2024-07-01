#include <stdio.h>
#include <math.h>

int main ()
{
    int vmax, vmot, dif;
    printf("Velocidade maxima = ");
    scanf("%d", &vmax);
    printf("Velocidade dirigindo = ");
    scanf("%d", &vmot);
    if(vmot > vmax)
        printf("Multa de R$ %d,00", 50*(vmot-vmax));
    else
        printf("Nao ha multa.");
    return 0;
}
