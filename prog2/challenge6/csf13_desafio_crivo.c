/*
Desafio 08
Desenvolvido por: Lucas Yukio Fukuda Matsumoto - 2516977
*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int* crivoDeEratostenes(int tamanho);

int main()
{
    int valorMax, num, *crivo, i;
    printf("Deseja verificar ate qual valor maximo? ");
    scanf("%d", &valorMax);
    crivo = crivoDeEratostenes(valorMax);
    printf("\nTabela = ");
    for(i=0; i<=valorMax; i++)
        printf("%d", crivo[i]);
    printf("\n\nPesquisa por primos entre 1 e %d...\n", valorMax);
    printf("Digite -1 para sair.\n");
    scanf("%d", &num);
    while(num >= 0 && num <= valorMax)
    {
        if(crivo[num])
            printf ("Eh primo!\n\n");
        else
            printf ("Nao eh primo!\n\n");
        scanf("%d", &num);
    }
    free(crivo);
    return 0;
}

int* crivoDeEratostenes(int tamanho)
{
    int i, j, *crivo;
    crivo = (int*) malloc((tamanho+1)*sizeof(int));

    // seta que 0 e 1 nao sao primos
    crivo[0] = FALSE;
    crivo[1] = FALSE;

    // se que todos os demais sao primos
    for(i = 2; i <= tamanho; i++)
        crivo[i] = TRUE;

    /* Agora, analisa cada número a partir de 2. Se o número ainda
       não foi desmarcado, ele é primo e precisa "eliminar"
       todos os seus múltiplos.*/
    for(i = 2; i <= tamanho; i++)
        if(crivo[i])
            for(j = i + i; j <= tamanho; j += i)
                crivo[j] = FALSE;
    return crivo;
}
