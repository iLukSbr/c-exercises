#include <stdio.h>

int main ()
{
    int dias, horas, minutos, segundos;
    printf("Segundos? ");
    scanf("%d", &segundos);
    dias = segundos/86400;
    horas = (segundos%86400)/3600;
    minutos = (segundos%3600)/60;
    segundos = (segundos%3600)%60;
    printf("%d:%d:%d:%d", dias, horas, minutos, segundos);
}
