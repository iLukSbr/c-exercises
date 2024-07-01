#include <stdio.h>

int main()
{
    float precoalc, precogasol, kmlalc, kmlgasol, comparagasol, comparaalc;
    printf("Qual o preco do litro do alcool?\n");
    scanf("%f",&precoalc);
    printf("Qual o preco do litro da gasolina?\n");
    scanf("%f",&precogasol);
    printf("Qual a quilometragem por litro com alcool?\n");
    scanf("%f",&kmlalc);
    printf("Qual a quilometragem por litro com gasolina?\n");
    scanf("%f",&kmlgasol);
    comparagasol = precogasol/kmlgasol;
    comparaalc = precoalc/kmlalc;
    if (comparagasol > comparaalc)
        printf("E mais economico abastecer com alcool.");
    else
        printf("E mais economico abastecer com gasolina.");
    return 0;
}
