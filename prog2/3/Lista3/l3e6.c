#include <stdio.h>

int main()
{
    float x, y;
    printf("x e y?\n");
    scanf("%f %f", &x, &y);
    if(x==0 && y==0)
        printf("Origem");
    else if(x == 0 && y != 0)
        printf("Eixo y");
    else if(x != 0 && y == 0)
        printf("Eixo x");
    else if(x > 0 && y > 0)
        printf("Q1");
    else if(x > 0 && y < 0)
        printf("Q4");
    else if(x < 0 && y < 0)
        printf("Q3");
    else
        printf("Q2");
    return 0;
}
