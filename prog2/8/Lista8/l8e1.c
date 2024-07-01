#include <stdio.h>

int main()
{
    int a, i=1;
    printf("a0 = ");
    scanf("%d", &a);
    printf("\nSequencia de Collatz:\n%d\n", a);
    while(a>1){
        if(a%2 == 0)
            a /= 2;
        else
            a = 3*a + 1;
        printf("%d\n", a);
        i++;
    }
    printf("\nForam gerados %d elementos.", i);
    return 0;
}
