/* Aluno: Lucas Yukio Fukuda Matsumoto */
/* Disciplina: Estruturas de Dados 2 */
/* Profa. Juliana de Santi */
/* Lista Implementação de AVL */

#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir){
    printf("maior\n");
    return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura(Arvore* a){
    printf("altura\n");
    return !a ? -1 : a->altura;
}

int atualizar_altura(Arvore *a){
    printf("atualizar_altura\n");
    return maior(altura(a->esq), altura(a->dir)+1);
}

/*----------------------*/
int balanceamento(Arvore *a){
    printf("balanceamento\n");
    return altura(a->dir) - altura(a->esq);
}

/*----------------------*/
Arvore* rotacao_simples_esq(Arvore* a){
    printf("rotacao_simples_esq\n");
    No *t = a->dir;
    a->dir = t->esq;
    t->esq = a;
    a->altura = atualizar_altura(a);
    t->altura = atualizar_altura(t);
    return t;
}

/*----------------------*/
Arvore* rotacao_simples_dir(Arvore* a){
    printf("rotacao_simples_dir\n");
    No *t = a->esq;
    a->esq = t->dir;
    t->dir = a;
    a->altura = atualizar_altura(a);
    t->altura = atualizar_altura(t);
    return t;
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a){
    printf("rotacao_dupla_esq\n");
    a->dir = rotacao_simples_dir(a->dir);
    return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a){
    printf("rotacao_dupla_dir\n");
    a->esq = rotacao_simples_esq(a->esq);
    return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore* atualizar_fb_dir(Arvore *a){
    printf("atualizar_fb_dir\n");
    a->altura = atualizar_altura(a);
    if(balanceamento(a) == 2){
        if(balanceamento(a->dir) >= 0)
            a = rotacao_simples_esq(a);
        else
            a = rotacao_dupla_esq(a);
    }
    return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq(Arvore *a){
    printf("atualizar_fb_esq\n");
    a->altura = atualizar_altura(a);
    if(balanceamento(a) == -2){
        if (balanceamento(a->esq) <= 0)
            a = rotacao_simples_dir(a);
        else
            a = rotacao_dupla_dir(a);
    }
    return a;
}

#if defined(NUMEROS)
    Arvore* inserir(Arvore* a, int chave) {
        if(!a){
            a = (Arvore*)malloc(sizeof(Arvore));
            a->chave = chave;
            a->altura = 0;
            a->esq = a->dir = NULL;
        } else if(chave > a->chave){
            a->dir = inserir(a->dir, chave);
        } else if(chave < a->chave){
            a->esq = inserir(a->esq, chave);
        }
        a->altura = 1 + maior(altura(a->esq), altura(a->dir));
        int fb = balanceamento(a);
        if(fb > 1 && chave > a->dir->chave)
            return rotacao_simples_esq(a);
        if(fb > 1 && chave < a->dir->chave){
            a->dir = rotacao_simples_dir(a->dir);
            return rotacao_simples_esq(a);
        }
        if(fb < -1 && chave < a->esq->chave)
            return rotacao_simples_dir(a);
        if(fb < -1 && chave > a->esq->chave){
            a->esq = rotacao_simples_esq(a->esq);
            return rotacao_simples_dir(a);
        }
        return a;
    }

    /*Função para remover um nó de uma árvore binária de busca balanceada!*/
    Arvore* remover(Arvore *a, int chave){
        printf("remover\n");
        if(!a)
            return NULL;
        else{
            if(chave < a->chave){
                a->esq = remover(a->esq, chave);
                a = atualizar_fb_dir(a);
            }
            else if(chave > a->chave){
                a->dir = remover(a->dir, chave);
                a = atualizar_fb_esq(a);
            }
            else{
                if(!a->esq && !a->dir){
                    free(a);
                    a = NULL;
                }
                else if(!a->esq){
                    No *tmp = a;
                    a = a->dir;
                    free(tmp);
                }
                else if(!a->dir){
                    No *tmp = a;
                    a = a->esq;
                    free(tmp);
                }
                else{
                    No *tmp = a->esq;
                    while(tmp->dir)
                        tmp = tmp->dir;
                    a->chave = tmp->chave;
                    tmp->chave = chave;
                    a->esq = remover(a->esq, chave);
                    a = atualizar_fb_dir(a);
                }
            }
            return a;
        }
    }

#elif defined(LETRAS)
    Arvore* inserir(Arvore* a, char chave) {
        if(!a){
            a = (Arvore*)malloc(sizeof(Arvore));
            a->chave = chave;
            a->altura = 0;
            a->esq = a->dir = NULL;
        } else if(chave > a->chave){
            a->dir = inserir(a->dir, chave);
        } else if(chave < a->chave){
            a->esq = inserir(a->esq, chave);
        }
        a->altura = 1 + maior(altura(a->esq), altura(a->dir));
        int fb = balanceamento(a);
        if(fb > 1 && chave > a->dir->chave)
            return rotacao_simples_esq(a);
        if(fb > 1 && chave < a->dir->chave){
            a->dir = rotacao_simples_dir(a->dir);
            return rotacao_simples_esq(a);
        }
        if(fb < -1 && chave < a->esq->chave)
            return rotacao_simples_dir(a);
        if(fb < -1 && chave > a->esq->chave){
            a->esq = rotacao_simples_esq(a->esq);
            return rotacao_simples_dir(a);
        }
        return a;
    }

    /*Função para remover um nó de uma árvore binária de busca balanceada!*/
    Arvore* remover(Arvore *a, char chave){
        printf("remover\n");
        if(!a)
            return NULL;
        else{
            if(chave < a->chave){
                a->esq = remover(a->esq, chave);
                a = atualizar_fb_dir(a);
            }
            else if(chave > a->chave){
                a->dir = remover(a->dir, chave);
                a = atualizar_fb_esq(a);
            }
            else{
                if(!a->esq && !a->dir){
                    free(a);
                    a = NULL;
                }
                else if(!a->esq){
                    No *tmp = a;
                    a = a->dir;
                    free(tmp);
                }
                else if(!a->dir){
                    No *tmp = a;
                    a = a->esq;
                    free(tmp);
                }
                else{
                    No *tmp = a->esq;
                    while(tmp->dir)
                        tmp = tmp->dir;
                    a->chave = tmp->chave;
                    tmp->chave = chave;
                    a->esq = remover(a->esq, chave);
                    a = atualizar_fb_dir(a);
                }
            }
            return a;
        }
    }

#elif defined(NOMES)
    Arvore* inserir(Arvore* a, char* chave) {
        if (!a) {
            a = (Arvore*)malloc(sizeof(Arvore));
            strcpy(a->chave, chave); // Copia a string para o nó.
            a->altura = 0;
            a->esq = a->dir = NULL;
        } else {
            int comparacao = strcmp(chave, a->chave);

            if (comparacao > 0) {
                a->dir = inserir(a->dir, chave);
            } else if (comparacao < 0) {
                a->esq = inserir(a->esq, chave);
            } else {
                // A chave já existe na árvore, não faça nada.
                return a;
            }
        }

        // Atualize a altura do nó após a inserção.
        a->altura = 1 + maior(altura(a->esq), altura(a->dir));

        // Verifique e corrija o fator de balanceamento.
        int balance = balanceamento(a);

        if (balance > 1) {
            if (strcmp(chave, a->dir->chave) > 0) {
                // Rotação simples à esquerda.
                return rotacao_simples_esq(a);
            } else {
                // Rotação dupla à esquerda (rotação à direita seguida de rotação à esquerda).
                a->dir = rotacao_simples_dir(a->dir);
                return rotacao_simples_esq(a);
            }
        }

        if (balance < -1) {
            if (strcmp(chave, a->esq->chave) < 0) {
                // Rotação simples à direita.
                return rotacao_simples_dir(a);
            } else {
                // Rotação dupla à direita (rotação à esquerda seguida de rotação à direita).
                a->esq = rotacao_simples_esq(a->esq);
                return rotacao_simples_dir(a);
            }
        }
        return a;
    }

    Arvore* remover(Arvore* a, char* chave) {
    printf("remover\n");
    if (!a) {
        return NULL;
    } else {
        int comparacao = strcmp(chave, a->chave);

        if (comparacao < 0) {
            a->esq = remover(a->esq, chave);
            a = atualizar_fb_dir(a);
        } else if (comparacao > 0) {
            a->dir = remover(a->dir, chave);
            a = atualizar_fb_esq(a);
        } else {
            if (!a->esq && !a->dir) {
                free(a);
                a = NULL;
            } else if (!a->esq) {
                No* tmp = a;
                a = a->dir;
                free(tmp);
            } else if (!a->dir) {
                No* tmp = a;
                a = a->esq;
                free(tmp);
            } else {
                No* tmp = a->esq;
                while (tmp->dir) {
                    tmp = tmp->dir;
                }
                strcpy(a->chave, tmp->chave);
                a->esq = remover(a->esq, tmp->chave);
                a = atualizar_fb_dir(a);
            }
        }
        return a;
    }
}
#endif

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order(Arvore* a, int nivel){
    printf("imprimir_in_order\n");
    if(a){
        int i;
        for(i=0; i<nivel; i++)
            printf("      ");
        #if defined(LETRAS)
            printf("Chave: %c (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        #elif defined(NOMES)
            printf("Chave: %s (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        #elif defined(NUMEROS)
            printf("Chave: %d (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        #endif
        imprimir_in_order(a->esq, nivel+1);
        imprimir_in_order(a->dir, nivel+1);
    }
}
