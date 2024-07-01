#include <stdio.h>

int main()
{
    int n, i, a, a_ant2=1, a_ant=1;
    printf("Termos = ");
    scanf("%d", &n);
    printf("\nSequencia de Fibonacci:\n");
    printf("0\n%d\n%d\n", a_ant2, a_ant);
    for(i=4; i<=n; i++){
        a = a_ant2 + a_ant;
        a_ant2 = a_ant;
        a_ant = a;
        printf("%d\n", a);
    }
    return 0;
}
