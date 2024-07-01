/* Aluno: Lucas Yukio Fukuda Matsumoto */
/* Disciplina: Estruturas de Dados 2 */
/* Profa. Juliana de Santi */
/* Lista Implementação de AVL */

#include "avl.h"

int main(){
   Arvore *AVL = NULL;
   #ifdef LETRAS
        AVL = inserir(AVL, 'Q');
        AVL = inserir(AVL, 'Z');
        AVL = inserir(AVL, 'B');
        AVL = inserir(AVL, 'Y');
        AVL = inserir(AVL, 'T');
        AVL = inserir(AVL, 'M');
        AVL = inserir(AVL, 'E');
        AVL = inserir(AVL, 'W');
        AVL = inserir(AVL, 'X');
        AVL = inserir(AVL, 'S');
        AVL = inserir(AVL, 'F');
        AVL = inserir(AVL, 'G');
        AVL = inserir(AVL, 'A');
        AVL = inserir(AVL, 'H');
        AVL = inserir(AVL, 'N');
        AVL = inserir(AVL, 'O');
        AVL = inserir(AVL, 'P');
        AVL = inserir(AVL, 'R');
        printf("Letras inseridas\n");
    #elif defined(NOMES)
        AVL = inserir(AVL, "Pedro");
        AVL = inserir(AVL, "Joaquim");
        AVL = inserir(AVL, "Sandra");
        AVL = inserir(AVL, "Daniele");
        AVL = inserir(AVL, "Jhony");
        AVL = inserir(AVL, "Bruna");
        AVL = inserir(AVL, "Roberto");
        AVL = inserir(AVL, "Ricardo");
        AVL = inserir(AVL, "Rafael");
        AVL = inserir(AVL, "Hayana");
        AVL = inserir(AVL, "Lorena");
        AVL = inserir(AVL, "Mariana");
        AVL = inserir(AVL, "Marina");
        AVL = inserir(AVL, "Roberta");
        AVL = inserir(AVL, "Chayene");
        AVL = inserir(AVL, "Edmundo");
        printf("Nomes inseridos\n");
    #elif defined(NUMEROS)
        int i;
        for(i=0; i<9; i++)
            AVL = inserir(AVL, i);
        for(i=10; i<17; i++)
            AVL = inserir(AVL, i);
        for(i=18; i<23; i++)
            AVL = inserir(AVL, i);
        for(i=28; i<41; i++)
            AVL = inserir(AVL, i);
        printf("Numeros inseridos\n");
        imprimir_in_order(AVL, 0);
        AVL = remover(AVL, 1);
    #endif
    imprimir_in_order(AVL, 0);
    return 0;
}
