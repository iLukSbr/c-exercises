#include <stdio.h>

int main()
{
    int horai, horaf, durou;
    printf("Qual a hora inicial e a final do jogo?\n");
    scanf("%d %d", &horai, &horaf);
    if (horai >= horaf)
        durou = 24 - horai + horaf;
    else
        durou = horaf - horai;
    printf("O jogo durou %d hora(s).", durou);
    return 0;
}
