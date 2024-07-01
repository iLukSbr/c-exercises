#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    while(x >= 10 && x <= 20)
    {
        printf("ECO %d\n", x);
        scanf("%d", &x);
    }
    return 0;
}
