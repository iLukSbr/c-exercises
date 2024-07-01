#include <stdio.h>

#define N_TERMOS 10

int ultimosDigitos(int a, int b);

int main ()
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("\n%d\n", ultimosDigitos(a, b));
    return 0;
}

int ultimosDigitos(int a, int b)
{
    int dig_a, dig_b;
    if(a < b)
        return 0;
    while(b)
    {
        dig_a = a%10;
        dig_b = b%10;
        if(dig_a != dig_b)
            return 0;
        a /= 10;
        b /= 10;
    }
    return 1;
}
