// Lucas Yukio Fukuda Matsumorto - 2516977

#include <stdio.h>
#include <stdlib.h>

/* Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
    int id;             /* Identificador armazenado no nó. */
    struct noA* next;   /* Próximo nó na lista encadeada. */
} NoA;

/* Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
    int E;              /* Quantidade de arestas. */
    int V;              /* Quantidade de vértices. */
    NoA** Adj;          /* Lista de adjacências. */
} GrafoA;

/* Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
    int E;              /* Quantidade de arestas. */
    int V;              /* Quantidade de vértices. */
    int** Mat;          /* Matrix de adjacências. */
} GrafoM;

/* Função para criar um nó em uma lista encadeada */
NoA* criar_no(int id, NoA* next) {
    NoA* no = (NoA*)malloc(sizeof(NoA));
    no->id = id;
    no->next = next;
    return no;
}

/* Função para criar um grafo com lista de adjacências */
GrafoA* criar_grafo_adj(int tamanho) {
    int v;
    GrafoA* G = (GrafoA*)malloc(sizeof(GrafoA));
    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA**)malloc(tamanho * sizeof(NoA*));
    for (v = 0; v < G->V; v++) {
        G->Adj[v] = NULL;
    }
    return G;
}

/* Função para criar um grafo com matriz de adjacências */
GrafoM* criar_grafo_mat(int tamanho) {
    int v;
    GrafoM* G = (GrafoM*)malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int**)malloc(tamanho * sizeof(int*));
    for (v = 0; v < G->V; v++) {
        G->Mat[v] = (int*)malloc(tamanho * sizeof(int));
        for (int w = 0; w < G->V; w++) {
            G->Mat[v][w] = 0;
        }
    }
    return G;
}

/* Função para destruir um grafo construído com lista de adjacências */
void liberar_grafo_adj(GrafoA* G) {
    int v;
    for (v = 0; v < G->V; v++) {
        NoA* current = G->Adj[v];
        while (current != NULL) {
            NoA* next = current->next;
            free(current);
            current = next;
        }
    }
    free(G->Adj);
    free(G);
}

/* Função para destruir um grafo construído com matriz de adjacências */
void liberar_grafo_mat(GrafoM* G) {
    int v;
    for (v = 0; v < G->V; v++) {
        free(G->Mat[v]);
    }
    free(G->Mat);
    free(G);
}

/* Função para inserir uma aresta em uma lista de adjacências */
void inserir_aresta_adj(GrafoA* G, int v1, int v2) {
    G->Adj[v1] = criar_no(v2, G->Adj[v1]);
    G->Adj[v2] = criar_no(v1, G->Adj[v2]);
    G->E++;
}

/* Função para inserir uma aresta em uma matriz de adjacências */
void inserir_aresta_mat(GrafoM* G, int v1, int v2) {
    G->Mat[v1][v2] = 1;
    G->Mat[v2][v1] = 1;
    G->E++;
}

/* Função para imprimir a matriz de adjacências */
void imprimir_matriz_adj(GrafoM* G) {
    printf("\nGrafo (matriz adjacência):\n");
    printf("  ");
    for (int i = 0; i < G->V; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < G->V; i++) {
        printf("%d ", i);
        for (int j = 0; j < G->V; j++) {
            printf("%d ", G->Mat[i][j]);
        }
        printf("\n");
    }
}

/* Função para imprimir a lista de adjacências */
void imprimir_lista_adj(GrafoA* G) {
    printf("\nGrafo (lista adjacência):\n");
    for (int i = 0; i < G->V; i++) {
        printf("%d -> ", i);
        NoA* current = G->Adj[i];
        NoA* prev = NULL;
        while (current != NULL) {
            NoA* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        current = prev;
        while (current != NULL) {
            printf("%d ", current->id);
            NoA* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        printf("\n");
    }
}

/* Programa principal */
int main() {
    int Va = 6; /* Número de vértices */

    GrafoA* Ga = criar_grafo_adj(Va);
    GrafoM* Gm = criar_grafo_mat(Va);

    inserir_aresta_adj(Ga, 0, 1);
    inserir_aresta_adj(Ga, 0, 2);
    inserir_aresta_adj(Ga, 0, 5);
    inserir_aresta_adj(Ga, 1, 2);
    inserir_aresta_adj(Ga, 1, 3);
    inserir_aresta_adj(Ga, 2, 3);
    inserir_aresta_adj(Ga, 2, 4);
    inserir_aresta_adj(Ga, 3, 4);
    inserir_aresta_adj(Ga, 4, 5);

    inserir_aresta_mat(Gm, 0, 1);
    inserir_aresta_mat(Gm, 0, 2);
    inserir_aresta_mat(Gm, 0, 5);
    inserir_aresta_mat(Gm, 1, 2);
    inserir_aresta_mat(Gm, 1, 3);
    inserir_aresta_mat(Gm, 2, 3);
    inserir_aresta_mat(Gm, 2, 4);
    inserir_aresta_mat(Gm, 3, 4);
    inserir_aresta_mat(Gm, 4, 5);

    imprimir_matriz_adj(Gm);
    imprimir_lista_adj(Ga);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);

    return 0;
}
