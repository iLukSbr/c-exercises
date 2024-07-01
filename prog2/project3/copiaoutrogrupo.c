#include <stdlib.h>
#include "trabalho3.h"

void tiraRuido(Imagem1C* img)
{
    int i, j;

    for(i = 0; i < img->altura ; i++) // loop de linha
    {
        for(j = 0; j < img->largura ; j++) // loop de coluna
        {
            if(img->dados[i][j] > 160) // se o pixel for consideravelmente branco
            {
                img->dados[i][j] = 255; // torna o pixel branco
            }
            else
                img->dados[i][j] = 0; // senao, torna pixel preto
        }
    }
}

unsigned char** criaCopia( Imagem1C* img ) // cria uma cópia da imagem
{
    int i;
    unsigned char** matriz;
    matriz = (unsigned char**) malloc (sizeof (unsigned char*) * img->altura);
    for (i = 0; i < img->altura; i++)
        matriz [i] = (unsigned char*) malloc (sizeof (unsigned char) * img->largura);// alocação dinamica da matriz
    return matriz;
}

void destroiMatriz ( unsigned char** matriz, int altura ) // destroi a alocação da matriz
{
    int i;
    for ( i = 0; i < altura; i++ )
        free ( matriz[i] );
	free ( matriz );
}

int criaMedia( Imagem1C* img, unsigned char** matriz, int i, int j ) // faz a media dos 2 vizinhos mais proximos em cada lado
{
    int media = 0, m = 0;

    if ( j + 1 < img->largura )
    {
        media += matriz[i][j + 1];
        m++;
    }
    if ( j > 0 )
    {
        media += matriz[i][j - 1];
        m++;
    }
    if ( i + 1 < img->altura )
    {
        media += matriz[i + 1][j];
        m++;
    }
    if ( i > 0 )
    {
        media += matriz[i - 1][j];
        m++;
    }
    if ( j + 2 < img->largura )
    {
        media += matriz[i][j + 2];
        m++;
    }
    if ( j > 1 )
    {
        media += matriz[i][j - 2];
        m++;
    }
    if ( i + 2 < img->altura )
    {
        media += matriz[i + 2][j];
        m++;
    }
    if ( i > 1 )
    {
        media += matriz[i - 2][j];
        m++;
    }

    return media/m;
}

void refinaImg(Imagem1C* img, unsigned char** matriz)
{
    int i, j, media;

    for(i = 0; i < img->altura ; i++) // loop de linha
    {
        for(j = 0; j < img->largura ; j++) // loop de coluna
        {
            media = criaMedia( img, matriz, i, j );

            if( media > 126) // se o pixel for consideravelmente branco
            {
                img->dados[i][j] = 255; // torna o pixel branco
            }
            else
                img->dados[i][j] = 0; // senao, torna pixel preto
        }
    }
}


void binarizar(Imagem1C* img)
{
    int i, j;

    unsigned char** matriz;

    matriz = criaCopia(img);


    tiraRuido(img);

    for(i = 0; i < img->altura ; i++) // loop de linha
    {
        for(j = 0; j < img->largura ; j++) // loop de coluna
        {
            matriz[i][j] = img->dados[i][j]; // matriz recebe a imagem com ruído diminuido
        }
    }

    refinaImg(img, matriz);

    salvaImagem1C( img , "saida.bmp");
    destroiMatriz( matriz, img->altura);
}




void contaIngredientes (Imagem1C* img, int* n_circulos, int* n_retangulos)
{
    int i, j;
    binarizar(img);

    for(i = 0; i < img->altura ; i++)
    {
        for(j = 0; j < img->largura ; j++)
        {

        }
    }

}















