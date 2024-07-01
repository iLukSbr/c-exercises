/*===========================================================================*/
/* LABIRINTO                                                                 */
/*===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================================*/

#define FILENAME "../teste1.txt"
#define CLEAR "cls" // Mude para "clear" no Linux.

#define BUFLEN 1024 // Altura/largura máxima do labirinto + 2

#define PAREDE -2
#define CAMINHO -1

/*===========================================================================*/
/* TIPOS                                                                     */
/*===========================================================================*/

typedef struct
{
    int** mat;
    int w;
    int h;

} Labirinto;

/*---------------------------------------------------------------------------*/

typedef struct
{
    int x;
    int y;

} Coordenada2D;

/*===========================================================================*/
/* FUNÇÕES                                                                   */
/*===========================================================================*/

Labirinto* carregaLabirinto (char* filename, Coordenada2D* rato, Coordenada2D* queijo);
void destroiLabirinto (Labirinto* lab);
void mostraLabirinto (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D pos_queijo);
void preencheMatrizCusto (Labirinto* lab, Coordenada2D pos_queijo);
void imprimeMatriz (int** m, int w, int h);
int calculaCaminho (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D** caminho);
void mostraCaminho (Labirinto* lab, Coordenada2D pos_queijo, Coordenada2D* caminho, int tam);

/*===========================================================================*/

int main ()
{
    Labirinto* lab; // Um labirinto.
    Coordenada2D* caminho; // Vetor de coordenadas.
    int tam_caminho; // Tamanho do caminho.
    Coordenada2D pos_rato; // Posição do rato.
    Coordenada2D pos_queijo; // Posição do queijo.

    lab = carregaLabirinto (FILENAME, &pos_rato, &pos_queijo);
    if (!lab)
    {
        printf ("Erro abrindo %s\n", FILENAME);
        return 1;
    }

    preencheMatrizCusto (lab, pos_queijo);
    tam_caminho = calculaCaminho (lab, pos_rato, &caminho);
    mostraCaminho (lab, pos_queijo, caminho, tam_caminho);

    // Desaloca tudo.
    destroiLabirinto (lab);
    free (caminho);

    return 0;
}

/*---------------------------------------------------------------------------*/
/** Lê o labirinto de um arquivo txt. Supõe que está tudo mais ou menos ok,
 * de acordo com a especificação (i.e. não estou testando muita coisa...).
 *
 * Parâmetros: char* filename: arquivo para abrir.
 *             Coordenada2D* rato: parâmetro de saída para a posição do rato.
 *             Coordenada2D* queijo: idem para a posição do queijo.
 *
 * Valor de retorno: ponteiro para uma nova instância de Labirinto, com a
                     matriz preenchida como explicado na especificação. */

Labirinto* carregaLabirinto (char* filename, Coordenada2D* rato, Coordenada2D* queijo)
{
    int i, j;
    char foostring [BUFLEN];
    FILE* f;
    Labirinto* lab;

    f = fopen (filename, "r");
    if (!f)
        return NULL;

    // Inicializa o rato e o queijo.
    rato->x = -1;
    rato->y = -1;
    queijo->x = -1;
    queijo->y = -1;

    // Lê a primeira linha.
    if (!fgets (foostring, BUFLEN, f))
        return NULL;

    lab = (Labirinto*) malloc (sizeof (Labirinto)); // Cria o labirinto.
    lab->w = strlen (foostring)-1;
    foostring [lab->w] = 0;

    // Aloca a matriz com um número temporário de linhas.
    lab->mat = (int**) malloc (sizeof (int*) * BUFLEN);

    // Enquanto tiver linhas para ler, vai lendo!
    for (i = 0; foostring [0]; i++)
    {
        // Coloca a linha lida na matriz.
        lab->mat [i] = (int*) malloc (sizeof (int) * lab->w);
        for (j = 0; j < lab->w; j++)
        {
            // Rato? (não estou verificando se tem mais que 1 rato!)
            if (foostring [j] == 'r' || foostring [j] == 'R')
            {
                rato->y = i;
                rato->x = j;
                foostring [j] = ' ';
            }
            // Queijo? (não estou verificando se tem mais que 1 queijo!)
            else if (foostring [j] == 'q' || foostring [j] == 'Q')
            {
                queijo->y = i;
                queijo->x = j;
                foostring [j] = ' ';
            }

            if (foostring [j] == ' ')
                lab->mat [i][j] = CAMINHO;
            else
                lab->mat [i][j] = PAREDE;
        }

        // Lê outra linha. Não estou testando se está do tamanho certo!
        if (!fgets (foostring, lab->w + 2, f))
            foostring [0] = 0; // Acabou.
        foostring [lab->w] = 0;
    }

    // Mantém somente as linhas válidas.
    lab->h = i;
    lab->mat = realloc (lab->mat, sizeof (int*) * (lab->h));

    fclose (f);

    return (lab);
}

/*---------------------------------------------------------------------------*/
/** Destruidor para o tipo Labirinto. Desaloca tudo!
 *
 * Parâmetros: Labirinto* lab: Labirinto para destruir.
 *
 * Valor de retorno: nenhum. */

void destroiLabirinto (Labirinto* lab)
{
    free(lab);
    // TODO: escreva esta função!
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto de um jeito "bonitinho".
 *
 * Parâmetros: Labirinto* lab: labirinto.
 *             Coordenada2D pos_rato: coordenadas do rato.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. */

void mostraLabirinto (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D pos_queijo)
{
    int i, j;

    for (i = 0; i < lab->h; i++)
    {
        for (j = 0; j < lab->w; j++)
        {
            if (i == pos_rato.y && j == pos_rato.x)
                printf ("R");
            else if (i == pos_queijo.y && j == pos_queijo.x)
                printf ("Q");
            else if (lab->mat [i][j] == PAREDE)
                printf ("|");
            else
                printf (" ");
        }

        printf ("\n");
    }
}

/*---------------------------------------------------------------------------*/
/** Transforma a matriz do labirinto dado em uma matriz de custo. Inicialmente,
 * a matriz contém somente os valores definidos pelas constantes PAREDE e
 * CAMINHO, que são negativos. A função deve substituir as posições contendo o
 * valor para o CAMINHO pela distância L1 até a posição do queijo.
 *
 * Parâmetros: Labirinto* lab: labirinto para atualizar.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *
 * Valor de retorno: nenhum. A matriz do labirinto é modificada. */

void preencheMatrizCusto (Labirinto* lab, Coordenada2D pos_queijo)
{
    int i, j, dist = 0, caminhou = 1;
    lab->mat[pos_queijo.x][pos_queijo.y] = dist;
    for(dist = 1; caminhou; dist++)
    {
        caminhou = 0;
        for(i = 0; i < lab->h; i++)
        {
            for(j = 0; j < lab->w; j++)
            {
                if(lab->mat[i][j] == dist-1)
                {
                    if(i > 0)
                        if(lab->mat[i - dist][j] == CAMINHO)
                            lab->mat[i - dist][j] = dist;
                    if(j < lab->w - 1)
                        if(lab->mat[i][j + dist] == CAMINHO)
                            lab->mat[i][j + dist] = dist;
                    if(j > 0)
                        if(lab->mat[i][j - dist] == CAMINHO)
                            lab->mat[i][j - dist] = dist;
                    if(i < lab->h - 1)
                        if(lab->mat[i + dist][j] == CAMINHO)
                            lab->mat[i + dist][j] = dist;
                    caminhou = 1;
                }
            }
        }
    }
    // TODO: escreva esta função!
}

/*---------------------------------------------------------------------------*/
/** Imprime uma matriz de inteiros na tela.
 *
 * Parâmetros: int** m: matriz para mostrar.
 *             int w, int h: largura/altura da matriz.
 *
 * Valor de retorno: nenhum. */

// TODO: apenas leia: esta função pode ser útil para testar alguma coisa. Se precisar, pode mudar o 3 do printf para ver valores maiores.

void imprimeMatriz (int** m, int w, int h)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
            printf ("%3d ", m[i][j]);
        printf ("\n");
    }
    printf("\n");
}

/*---------------------------------------------------------------------------*/
/** Gera um vetor que armazena o caminho do rato até o queijo, com base em uma
 * matriz de custo já preenchida corretamente. O vetor é gerado com alocação
 * dinâmica, e deve ser desalocado pelo chamador.
 *
 * Parâmetros: Labirinto* lab: labirinto com a matriz de custo já preenchida.
 *             Coordenada2D pos_rato: coordenadas do rato.
 *             Coordenada2D** caminho: ponteiro para o vetores de saída. Ele
 *               será alocado nesta função, e vai conter as coordenadas de
 *               cada posição do caminho, começando com a posição do rato e
 *               terminando com a posição do queijo.
 *
 * Valor de retorno: o tamanho do caminho (= número de valores no vetor caminho). */

int calculaCaminho (Labirinto* lab, Coordenada2D pos_rato, Coordenada2D** caminho)
{
    int tam, dist, k = 0;
    if(lab->mat[pos_rato.x][pos_rato.y] >= 0)
        tam = lab->mat[pos_rato.x][pos_rato.y] + 1;
    else
        return 0;
    caminho->x = (Coordenada2D*) malloc(tam*sizeof(int));
    caminho->y = (Coordenada2D*) malloc(tam*sizeof(int));
    caminho->x[k] = pos_rato.x;
    caminho->y[k] = pos_rato.y;
    for(dist = tam, k = 1; dist; dist--, k++)
    {
        if(i > 0)
            if(lab->mat[i - dist][j] == dist)
            {
                caminho->x[k] = i - dist;
                caminho->y[k] = j;
                caminhou = 1;
            }
        if(j < lab->w - 1 && !caminhou)
            if(lab->mat[i][j + dist] == dist)
            {
                caminho->x[k] = i;
                caminho->y[k] = j + dist;
                caminhou = 1;
            }
        if(j > 0 && !caminhou)
            if(lab->mat[i][j - dist] == dist)
            {
                caminho->x[k] = i;
                caminho->y[k] = j - dist;
                caminhou = 1;
            }
        if(i < lab->h - 1 && !caminhou)
            if(lab->mat[i + dist][j] == dist)
            {
                caminho->x[k] = i + dist;
                caminho->y[k] = j;
            }
        caminhou = 0;
    }
    return tam;
    // TODO: escreva esta função!
}

/*---------------------------------------------------------------------------*/
/** Mostra o labirinto várias vezes, percorrendo o caminho.
 *
 * Parâmetros: Labirinto* lab: labirinto para mostrar.
 *             Coordenada2D pos_queijo: coordenadas do queijo.
 *             Coordenada2D* caminho: vetor do caminho.
 *             int tam: tamanho do vetor do caminho.
 *
 * Valor de retorno: nenhum. */

void mostraCaminho (Labirinto* lab, Coordenada2D pos_queijo, Coordenada2D* caminho, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        system (CLEAR);
        mostraLabirinto (lab, caminho [i], pos_queijo);
        system ("pause");
    }
}

/*===========================================================================*/
