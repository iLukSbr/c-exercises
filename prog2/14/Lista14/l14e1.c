#include <stdio.h>
#define MAX_RESPOSTAS 81

int main()
{
    int n, i, acertos=0;
    unsigned char gabarito[MAX_RESPOSTAS], marcadas[MAX_RESPOSTAS];
    scanf("%d", &n);
    scanf("%s", gabarito);
    scanf("%s", marcadas);
    for(i=0; i<n; i++)
        if(gabarito[i] == marcadas[i])
            acertos++;
    printf("%d", acertos);
    return 0;
}
