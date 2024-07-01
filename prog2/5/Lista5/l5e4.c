#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    if (n & 0x01)
        printf("Impar.");
    else
        printf("Par.");
    return 0;
}
