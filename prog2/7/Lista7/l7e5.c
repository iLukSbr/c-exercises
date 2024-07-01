#include <stdio.h>

int main()
{
    int n, ant, i=1, s_atual=1, s_maior=1;
    printf("n%d = ", i);
    scanf("%d", &n);
    ant = n;
    while(n>0){
        printf("n%d = ", i);
        scanf("%d", &n);
        if(n>ant)
            s_atual++;
            if(s_atual > s_maior)
                s_maior = s_atual;
        else
            s_atual = 1;
        i++;
        ant = n;
    }
    printf("Maior sequencia crescente = %d", s_maior);
    return 0;
}
