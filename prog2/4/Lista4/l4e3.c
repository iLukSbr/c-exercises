#include <stdio.h>

int main()
{
    float D;
    printf("Distancia (cm)?\n");
    scanf("%f", &D);
    if (D <= 800)
        printf("1 ponto");
    else if( D > 800 && D <= 1400)
        printf("2 pontos");
    else if (D > 1400 && D <= 2000)
        printf("3 pontos");
    else
        printf("0 pontos");
    return 0;
}
