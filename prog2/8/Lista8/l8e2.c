#include <stdio.h>

#define META 1000000

int main()
{
    int acessos, n, total, i, dias=-1;
    printf("Dias = ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        printf("Acessos no dia %d = ", i);
        scanf("%d", &acessos);
        total += acessos;
        if(total>=META && dias==-1)
            dias = i;
    }
    if(dias!=-1)
        printf("%d", dias);
    else
        printf("-1");
    return 0;
}
