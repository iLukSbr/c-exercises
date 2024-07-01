#include <stdio.h>

unsigned int inverteNum (unsigned int n);

int main()
{
    unsigned int n;
    printf("N = ");
    scanf("%d", &n);
    printf("%d", inverteNum(n));
    return 0;
}

unsigned int inverteNum (unsigned int n)
{
    unsigned int inv;
    while(n>0)
    {
        inv = inv*10 + n%10;
        n = n/10;
    }
    return inv;
}
