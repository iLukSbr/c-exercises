#include <stdio.h>

#define ASEGB 1
#define BSEGA 2
#define AMBOS 3

int segmento(int a, int b);

int main()
{
    int a, b, a_aux, b_aux, resultado;
    printf("a b =\n");
    scanf ("%d %d", &a, &b);
    resultado = segmento(a, b);
    if(resultado == ASEGB)
        printf("ASEGB");
    else if(resultado == BSEGA)
        printf("BSEGA");
    else if(resultado == AMBOS)
        printf("ASEGB/BSEGA");
    else
        printf("0");
    return 0;
}

int segmento(int a, int b)
{
    int a_aux, b_aux, a_n=0, b_n=0, i, seg=0, resultado=0;
    a_aux = a;
    b_aux = b;
    while(a_aux > 0)
    {
        a_n++;
        a_aux /= 10;
    }
    while(b_aux > 0)
    {
        b_n++;
        b_aux /= 10;
    }
    a_aux = a;
    b_aux = b;
    if(a > b)
    {
        for(i=1; i<=a_n; i++)
        {
            if(a_aux%10 == b_aux%10)
            {
                b_aux /= 10;
                seg++;
            }
            else
            {
                b_aux = b;
                seg = 0;
            }
            a_aux /= 10;
            if(seg == b_n)
            {
                resultado = BSEGA;
                break;
            }
            else if(a_n - i < b_n && seg == 0)
                break;
        }
    }
    else if(b > a)
    {
        for(i=1; i<=b_n; i++)
        {
            if(b_aux%10 == a_aux%10)
            {
                a_aux /= 10;
                seg++;
            }
            else
            {
                a_aux = a;
                seg = 0;
            }
            b_aux /= 10;
            if(seg == a_n)
            {
                resultado = ASEGB;
                break;
            }
            else if(b_n - i < a_n && seg == 0)
                break;
        }
    }
    else
        resultado = AMBOS;
    return resultado;
}
