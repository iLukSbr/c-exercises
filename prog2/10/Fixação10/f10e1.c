#include <stdio.h>

int ehBissexto(int ano);

int main()
{
    int ano;
    printf("Ano = ");
    scanf("%d", &ano);
    if(ehBissexto(ano))
        printf("\nE bissexto.\n");
    else
        printf("\nNao e bissexto.\n");
    return 0;
}

int ehBissexto(int ano)
{
    if((ano%400 == 0) || (ano%4 == 0 && ano%100 != 0))
        return 1;
    else
        return 0;
}
