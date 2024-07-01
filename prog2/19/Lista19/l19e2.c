#include <stdlib.h>
#include <time.h>

#define N 100

int avaliaDado (int* rolagens, int n);

int analisa (int*** in, int largura, int altura, int** out);

int main()
{
    int largura, altura;
    analisa(in, largura, altura, out);
    return 0;
}

int avaliaDado (int* rolagens, int n)
{
    int i, cont[6]={0};
    for(i = 0; i < n; i++)
        cont[rolagens[i] - 1]++;
    for(i = 0; i < 6; i++)
        if(cont[j] > 18 || cont[j] < 15)
            return 0;
    return 1;
}

int analisa (int*** in, int largura, int altura, int** out)
{
    int i, n_erros;
    for(i = 0; i < altura; i++)
        for(j = 0; j < largura; j++)
            out[i][j] = avaliaDado(in[i][j], N);
    for(i = 0; i < altura; i++)
    {
        n_erros = 0;
        for(j = 0; j < largura; j++)
            if(!out[i][j])
            {
                n_erros++;
                if(n_erros > largura/2)
                    return 1;
            }
    for(j = 0; j < largura; j++)
    {
        n_erros = 0;
        for(i = 0; i< altura; i++)
            if(!out[i][j])
            {
                n_erros++;
                if(n_erros > altura/2)
                    return 1;
            }
    }
    return 0;
}
