#include <stdio.h>

int main()
{
    int atual, nasc, contr_0, contr_tot, idade;
    printf("Ano atual = ");
    scanf("%d", &atual);
    printf("Ano de nascimento = ");
    scanf("%d", &nasc);
    printf("Ano que comecou a contribuir = ");
    scanf("%d", &contr_0);
    idade = atual - nasc;
    contr_tot = atual - contr_0;
    printf("Idade do empregado ao final do ano atual = %d\n", idade);
    if (idade >= 65 || contr_tot >= 30 || idade >= 60 && contr_tot >= 25)
        printf("Podera se aposentar.");
    else
        printf("Nao podera se aposentar.");
    return 0;
}
