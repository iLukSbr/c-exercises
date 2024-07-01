#include <stdio.h>

int main ()
{
    float media = 0, n1, n2, n3, n4, n5;
    printf("n1 = ");
    scanf("%f", &n1);
    printf("n2 = ");
    scanf("%f", &n2);
    printf("n3 = ");
    scanf("%f", &n3);
    printf("n4 = ");
    scanf("%f", &n4);
    printf("n5 = ");
    scanf("%f", &n5);
    printf("Medias:\n");
    media = (n1 + n2)/2;
    printf("%f\n", media);
    media = (n1 + n2 + n3)/3;
    printf("%f\n", media);
    media = (n1 + n2 + n3 + n4)/4;
    printf("%f\n", media);
    media = (n1 + n2 + n3 + n4 + n5)/5;
    printf("%f\n", media);
    return 0;
}
