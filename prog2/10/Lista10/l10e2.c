#include <stdio.h>

double casasDecimais (double x);

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%lf", casasDecimais(x));
    return 0;
}

double casasDecimais (double x)
{
    return (x - (int)x);
}
