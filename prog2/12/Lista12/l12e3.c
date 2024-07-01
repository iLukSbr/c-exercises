//Lucas Yukio Fukuda Matsumoto - 2516977
#include <stdio.h>

unsigned int kAlternante(unsigned int n, unsigned int *k);

int main()
{
    unsigned int n, k=0, alternante;
    printf("n = ");
    scanf("%u", &n);
    if(n <= 1)
        return 0;
    alternante = kAlternante(n, &k);
    if(k)
        printf("\n%d-Alternante.\n", k);
    else
        printf("Nao e alternante.");
    return 0;
}

unsigned int kAlternante(unsigned int n, unsigned int *k)
{
    unsigned int num, i, par=0, impar=0, seq=0;
    for(i=0; i<n; i++)
    {
        scanf("%u", &num);
        if(num%2 == 0)
        {
            par++;
            if(seq && par > seq)
                return 0;
            if(impar)
            {
                if(!seq)
                    seq = impar;
                else if(seq != impar)
                    return 0;
                impar = 0;
                par = 1;
            }
        }
        else
        {
            impar++;
            if(seq && impar > seq)
                return 0;
            if(par)
            {
                if(!seq)
                    seq = par;
                else if(seq != par)
                    return 0;
                par = 0;
                impar = 1;
            }
            else if(par && seq != par)
                return 0;
        }
    }
    if(!seq && par)
        *k = par;
    else if(!seq && impar)
        *k = impar;
    else
        *k = seq;
    return 1;
}
