#include <stdio.h>

int main ()
{
    int ap1, ap2, pl1, pl2;
    printf("Aposta = ");
    scanf("%dx%d", &ap1, &ap2);
    printf("\nPlacar = ");
    scanf("%dx%d", &pl1, &pl2);
    if(ap1 == pl1 && ap2 == pl2)
        printf("\n%d pontos.\n", 20);
    else if((ap1 == pl1 || ap2 == pl2) && ap1 > ap2)
        printf("\n%d pontos.\n", 15);
    else if(ap1 == pl1 || ap2 == pl2)
        printf("\n%d pontos.\n", 5);
    else if(ap1 > ap2)
        printf("\n%d pontos.\n", 10);
    else
        printf("\n%d pontos.\n", 0);
    return 0;
}
