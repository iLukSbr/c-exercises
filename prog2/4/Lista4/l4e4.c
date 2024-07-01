#include <stdio.h>

int main()
{
    int ced1, ced2, ced5, ced10, ced20, ced50, ced100, val;
    printf("Valor = R$ ");
    scanf("%d", &val);
    ced100 = val/100;
    val %= 100;
    ced50 = val/50;
    val %= 50;
    ced20 = val/20;
    val %= 20;
    ced10 = val/10;
    val %= 10;
    ced5 = val/5;
    val %= 5;
    ced2 = val/2;
    ced1 = val%2;
    printf("%d cedulas de R$ 100, %d de R$ 50, %d de R$ 20, %d de R$ 10, %d de R$ 5, %d de R$ 2 e %d de R$ 1.", ced100, ced50, ced20, ced10, ced5, ced2, ced1);
    return 0;
}
