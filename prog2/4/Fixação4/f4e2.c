#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n%2 == 0 && n > 10 || n%2 == 1 && n < 50)
        printf("SIM");
    else
        printf("NAO");
    return 0;
}
