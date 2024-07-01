#include <stdio.h>

int main()
{
    float n1, n2, n3;
    printf("N1, N2 e N3?\n");
    scanf("%f %f %f", &n1, &n2, &n3);
    if (n1 <= n2 && n1 <= n3)
    {
        printf("%f ", n1);
        if (n2 <= n3)
            printf("%f %f", n2, n3);
        else
            printf("%f %f", n3, n2);
    }
    else if (n2 <= n1 && n2 <= n3)
    {
        printf("%f ", n2);
        if (n1 <= n3)
            printf("%f %f", n1, n3);
        else
            printf("%f %f", n3, n1);
    }
    else
    {
        printf("%f ", n3);
        if (n2 <= n1)
            printf("%f %f", n2, n1);
        else
            printf("%f %f", n1, n2);
    }
    return 0;
}

