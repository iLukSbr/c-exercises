#include <stdio.h>
#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */
#define TOTAL_LINHAS 50

void pontoRolo1 (), pontoRolo2 (), moveAgulha (), rolaTecido();

void main ()
{
    int i, a, v, linha, move;
    move = LARGURA_FAIXA-1;
    a = 1;
    v = 0;
    /* Funciona até desligar ou o tecido acabar. */
    for(linha = 1; linha <= TOTAL_LINHAS; linha++)
    {
        for (i = 0; i < move; i++)
        {
            moveAgulha();
        }
        for (i = 0; i < a; i++)
        {
            pontoRolo2();
        }
        for (i = 0; i < v; i++)
        {
            pontoRolo1();
        }
        if(a>0)
            a++;
        else if(v>0)
            v++;
        if(a > LARGURA_FAIXA)
        {
            a = 0;
            v = 1;
        }
        else if(v > LARGURA_FAIXA)
        {
            a = 1;
            v = 0;
        }
        move--;
        if(move == -1)
            move = LARGURA_FAIXA-1;
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

