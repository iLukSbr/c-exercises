#include <stdio.h>

int main()
{
    int i, j, k, flag;
    printf("2 dados:\n");
    for(i=1; i<=6; i++)
    {
        for(j=1; j<=6; j++)
            printf("%d %d\n", i, j);
    }
    printf("\n3 dados:\n");
    for(i=1; i<=6; i++)
    {
        for(j=1; j<=6; j++)
        {
            for(k=1; k<=6; k++)
                printf("%d %d %d\n", i, j, k);
        }
    }
    printf("3 dados nao importando a ordem:\n");
    j=1;
    k=1;
    for(i=1; i<=6; i++)
    {
        if(j<6)
        {
            for(j=1; j<=6; j++)
            {
                if(k<6)
                {
                    for(k=1; k<=6; k++)
                        printf("%d %d %d\n", i, j, k);
                }
                else
                    printf("%d %d %d\n", i, j, 6);
            }
        }
        else
            printf("%d %d %d\n", i, 6, 6);
    }
    return 0;
}
