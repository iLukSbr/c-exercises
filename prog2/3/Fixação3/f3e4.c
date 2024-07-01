#include <stdio.h>
#include <math.h>

int main ()
{
    int nasc, atual, idade;
    printf("Ano de nascimento? ");
    scanf("%d", &nasc);
    printf("Ano atual? ");
    scanf("%d", &atual);
    idade = atual - nasc;
    if (idade < 16)
        printf("Nao eleitor.");
    else if (idade >= 18 && idade < 65)
        printf("Eleitor obrigatorio.");
    else
        printf("Eleitor facultativo.");
    return 0;
}
