#include <stdio.h>

int func (int x)
{
    int i, n;
    n = 0;
    for (i = 1; i < x; i++)
        n += i;
    return (n);
}

int main ()
{
    int i, n;
    for (i = 1; i <= 4; i++)
    {
        n = 3*i;
        printf ("%d\n", func (n));
    }
    return (0);
}
