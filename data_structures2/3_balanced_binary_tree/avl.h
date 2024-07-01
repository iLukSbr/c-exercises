/* Aluno: Lucas Yukio Fukuda Matsumoto */
/* Disciplina: Estruturas de Dados 2 */
/* Profa. Juliana de Santi */
/* Lista Implementação de AVL */

#ifndef _AVL_H
    #define _AVL_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

//    #define LETRAS
    #define NOMES
//    #define NUMEROS

    typedef struct node{
        #ifdef LETRAS
            char chave;
        #elif defined(NOMES)
            char chave[8];
        #elif defined(NUMEROS)
            int chave;
        #endif
        int altura;
        struct node* esq;
        struct node* dir;
    }No, Arvore;

    int maior(int esq, int dir);

    int altura(Arvore* a);

    int atualizar_altura(Arvore *a);

    int balanceamento(Arvore *a);

    Arvore* rotacao_simples_esq(Arvore* a);

    Arvore* rotacao_simples_dir(Arvore* a);

    Arvore* rotacao_dupla_esq(Arvore* a);

    Arvore* rotacao_dupla_dir(Arvore* a);

    Arvore* atualizar_fb_dir(Arvore *a);

    Arvore* atualizar_fb_esq(Arvore *a);

    #if defined(NUMEROS)
        Arvore* inserir(Arvore *a, int chave);

        Arvore* remover(Arvore *a, int chave);
    #elif defined(LETRAS)
        Arvore* inserir(Arvore *a, char chave);

        Arvore* remover(Arvore *a, char chave);
    #elif defined(NOMES)
        Arvore* inserir(Arvore *a, char* chave);

        Arvore* remover(Arvore *a, char* chave);
    #endif

    void imprimir_in_order(Arvore* a, int nivel);
#endif
