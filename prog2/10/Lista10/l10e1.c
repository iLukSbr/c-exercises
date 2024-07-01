#include <stdio.h>

int arredonda (double x);

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%d", arredonda(x));
    return 0;
}

int arredonda (double x)
{
    if(x >= 0)
        return ((int)(x+0.5));
    else
        return ((int)(x-0.5));
}
