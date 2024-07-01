#include <stdio.h>
int main ()
{
    float x1 = 5.0, x2 = 2.0;
    int x3 = 1;

    printf ("%f\n", x1 / x2);
    printf ("%f\n", x1);
    x1 = x2;
    printf ("%d\n", x3);
    x2 = 10;
    x1 = x1 + 10.0;
    x3 = 39;

    return 0;
}
