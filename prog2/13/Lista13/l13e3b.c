#include <stdio.h>

int ehParDeFoolano (unsigned int n1, unsigned int n2);

int contaDigito (unsigned int n, unsigned int dig);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("\n%d\n", ehParDeFoolano(n1, n2));
    return 0;
}

int ehParDeFoolano (unsigned int n1, unsigned int n2)
{
    int i;
    for(i=0; i<10; i++)
        if(contaDigito(n1, i) != contaDigito(n2, i))
            return 0;
    return 1;
}

int contaDigito (unsigned int n, unsigned int dig)
{
    int cont=0;
    while(n > 0)
    {
        if(n%10 == dig)
            cont++;
        n /= 10;
    }
    return cont;
}
