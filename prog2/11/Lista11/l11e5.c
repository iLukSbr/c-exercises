#include <stdio.h>

#define PICO 1
#define VALE 2
#define SUBIDA 3
#define DESCIDA 4

void registraPadrao (int posicao, int tipo);

int leProximoDado ();

int main()
{
    int ant, atual, prox = 0, i = 1;
    ant = leProximoDado ();
    if(ant > -1)
        atual = leProximoDado ();
    if(atual > -1)
    {
        prox = leProximoDado ();
        while (prox > -1)
        {
            i++;
            if (atual > ant && atual > prox)
                registraPadrao (i, PICO);
            else if (atual < ant && atual < prox)
                registraPadrao (i, VALE);
            else if (atual > ant && atual < prox)
                registraPadrao (i, SUBIDA);
            else if (atual < ant && atual > prox)
                registraPadrao (i, DESCIDA);
            ant = atual;
            atual = prox;
            prox = leProximoDado ();
        }
    }
    return 0;
}

void registraPadrao (int posicao, int tipo)
{
    //definida
}

int leProximoDado ()
{
    //definida
}
