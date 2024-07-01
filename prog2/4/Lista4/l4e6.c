#include <stdio.h>

int main()
{
    int conta, inv, soma;
    printf("Conta = ");
    scanf("%d", &conta);
    inv = 100*(conta%10) + (conta%100 - conta%10) + conta/100;
    soma = conta + inv;
    if (soma >= 1000)
        soma -= 1000*(soma/1000);
    soma = soma/100 + 2*(soma%100 - soma%10)/10 + 3*(soma%10);
    printf("Digito verificador = %d", soma%10);
    return 0;
}
