#include <stdio.h>
#define INICIO_FOOLANO 150
#define INICIO_BARANO 110
#define FOOLANO_CRESCE 2
#define BARANO_CRESCE 3

int main()
{
    int foolano = INICIO_FOOLANO, barano = INICIO_BARANO, i;
    for(i = 0; barano < foolano; i++)
    {
        foolano += FOOLANO_CRESCE;
        barano += BARANO_CRESCE;
    }
    printf("%d anos.\nFoolano tem %d cm, e Barano tem %d cm.\n", i, foolano, barano);
    return 0;
}
