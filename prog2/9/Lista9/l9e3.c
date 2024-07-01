#include <stdio.h>

int main()
{
    unsigned int i, n, num=1;
    printf("n = ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        if(num%i != 0)
        {
            i = 1;
            num++;
        }
    }
    printf("Menor divisivel geral = %d", num);
    return 0;
}
