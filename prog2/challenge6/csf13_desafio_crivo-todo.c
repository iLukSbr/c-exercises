/*
Desafio 08
Desenvolvido por:
*/


#define FALSE 0
#define TRUE 1

#define N_MAX 50


int main()
{
    int num, // variavel que armazena os valores de teste
        crivo[N_MAX+1], /* vetor que armazena em cada elemento
                           crivo[i] se i é primo (1) ou nao (0)*/
        i, j;

    // seta que 0 e 1 nao sao primos
    crivo [0] = FALSE;
    crivo [1] = FALSE;
    // se que todos os demais sao primos
    for (i = 2; i <= N_MAX; i++)
        crivo [i] = TRUE;

    /* Agora, analisa cada número a partir de 2. Se o número ainda
       não foi desmarcado, ele é primo e precisa "eliminar"
       todos os seus múltiplos.*/
    for (i = 2; i <= N_MAX; i++)
        if (crivo [i])
            for (j = i + i; j <= N_MAX; j += i)
                crivo [j] = FALSE;

    /* Loop para pesquisar se valores entre 1 a N_MAX são primos*/
    printf("\n\nPesquisa por primos entre 1 e %d...\n", N_MAX);
    printf("Digite -1 para sair.\n");
    scanf("%d", &num);
    while(num != -1)
    {
        if(crivo[num])
            printf("Eh primo!\n");
        else
            printf("Nao eh primo!\n");

        scanf("%d", &num);
    }

    return 0;
}
