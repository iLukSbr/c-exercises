/*
Lucas Yukio Fukuda Matsumoto - 2516977
*/

#include <stdio.h>
#define N 11

int ehValido(unsigned char *cpf);

int main()
{
    int validade=1, i;
    unsigned char cpf[N+1];
    scanf("%s", cpf);
    for(i=0; i<N; i++)
    {
        if(cpf[i]<'0' || cpf[i]>'9')
        {
            validade = 0;
            break;
        }
    }
    if(validade)
        validade = ehValido(cpf);
    if(validade)
        printf("\nEh valido");
    else
        printf("\nNao eh valido");
    return 0;
}

int ehValido(unsigned char *cpf)
{
    int i, j, controle[2];
    for(i=0; i<=1; i++)
    {
        controle[i] = 0;
        for(j=i; j<(N-2+i); j++)
            controle[i] += (j+1-i)*((int)cpf[j]-'0');
        controle[i] = (controle[i]%N)%(N-1);
        if(controle[i] != (int)cpf[N-2+i]-'0')
            return 0;
    }
    return 1;
}
