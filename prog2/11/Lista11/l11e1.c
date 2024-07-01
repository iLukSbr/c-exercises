#include <stdio.h>

#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */
#define TOTAL_LINHAS 50

void pontoRolo1 (), pontoRolo2 (), moveAgulha (), rolaTecido();

void main ()
{
    int i, j;
    /* Funciona até desligar ou o tecido acabar. */
    for(j=1; j<=TOTAL_LINHAS; j++)
    {
        for (i = 0; i < LARGURA_FAIXA; i++)
        {
            if (i == 1)
                pontoRolo1 ();
            else if (i == LARGURA_FAIXA-2)
                pontoRolo2 ();
            else
                moveAgulha ();
        }
        rolaTecido ();
    }
}

void pontoRolo1 ()
{
    printf("v");
}

void pontoRolo2 ()
{
    printf("a");
}

void moveAgulha ()
{
    printf(" ");
}

void rolaTecido ()
{
    printf("\n");
}
