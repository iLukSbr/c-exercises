#include <stdio.h>

int main()
{
    float l1, l2, l3;
    printf("Lados = ");
    scanf("%f %f %f", &l1, &l2, &l3);
    if ((l1 + l2) > l3 && (l2 + l3) > l1 && (l1 + l3) > l2)
    {
        if (l1 == l2 && l2 == l3)
            printf("Triangulo equilatero.");
        else if (l1 == l2 || l2 == l3 || l1 == l3 )
            printf("Triangulo isosceles.");
        else
            printf("Triangulo escaleno.");
    }
    else
        printf("Nao e triangulo.");
    return 0;
}
