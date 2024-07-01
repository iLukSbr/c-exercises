#include <stdio.h>
#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */
#define TOTAL_LINHAS 50

void pontoRolo1 (), pontoRolo2 (), moveAgulha (), rolaTecido();

void main ()
{
    int i, a, v, linha;
    a = LARGURA_FAIXA;
    v = 0;
    /* Funciona até desligar ou o tecido acabar. */
    for(linha = 1; linha <= TOTAL_LINHAS; linha++)
    {
        for (i = 0; i < a; i++)
        {
            pontoRolo2 ();
        }
        for (i = 0; i < v; i++)
        {
            pontoRolo1 ();
        }
        a--;
        v++;
        if(a == -1)
        {
            a = LARGURA_FAIXA;
            v = 0;
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

