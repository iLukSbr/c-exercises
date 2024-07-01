#include <stdio.h>

unsigned short pegaCampo (unsigned short seq, int pos, int nbits);

int main()
{
    unsigned short seq=12569, resultado;
    int pos=15, nbits=1;
    resultado = pegaCampo(seq, pos, nbits);
    printf("%d\n", resultado);
    return 0;
}

unsigned short pegaCampo (unsigned short seq, int pos, int nbits)
{
    unsigned short copia_seq, decimal=0;
    int i, pot2, bits_seq, exp;
    bits_seq = 8*sizeof(unsigned short);
    for(i=nbits; i>=1; i--)
    {
        pot2 = 1;
        copia_seq = seq;
        printf("%d\n", pos);
        printf("%d\n", nbits);
        printf("%d\n", i);
        printf("%d\n", pos+nbits-i);
        copia_seq <<= pos + nbits - i;
        printf("%hu\n", copia_seq);
        copia_seq >>= bits_seq - 1;
        printf("%hu\n", copia_seq);
        if(copia_seq)
        {
            for(exp=1; exp<i; exp++)
                pot2 *= 2;
            decimal += pot2;
        }
        printf("%d\n", pot2);
        printf("%d\n", decimal);
    }
    return decimal;
}
