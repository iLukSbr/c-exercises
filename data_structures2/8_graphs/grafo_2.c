// Lucas Yukio Fukuda Matsumoto - 2516977

#include <stdio.h>
#include <stdlib.h>

/* Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
    int id;          /* Identificador armazenado no nó. */
    struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/* Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
    int E;     /* Quantidade de arestas. */
    int V;     /* Quantidade de vértices. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/* Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
    int E;    /* Quantidade de arestas. */
    int V;    /* Quantidade de vértices. */
    int **Mat; /* Matrix de adjacências. */
} GrafoM;

/* Função para criar um grafo com lista de adjacências. */
GrafoA *criar_grafo_adj(int tamanho) {
    int v;
    GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
    for (v = 0; v < G->V; v++) {
        G->Adj[v] = NULL;
    }
    return G;
}

/* Função para criar um grafo com matriz de adjacências. */
GrafoM *criar_grafo_mat(int tamanho) {
    int v, w;
    GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **)malloc(tamanho * sizeof(int *));
    for (v = 0; v < G->V; v++) {
        G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
        for (w = 0; w < G->V; w++) {
            G->Mat[v][w] = 0;
        }
    }
    return G;
}

/* Função para destruir um grafo construído com lista de adjacências. */
void liberar_grafo_adj(GrafoA *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        if (G->Adj[v] != NULL) {
            free(G->Adj[v]);
        }
    }
    free(G->Adj);
    free(G);
}

/* Função para destruir um grafo construído com lista de adjacências. */
void liberar_grafo_mat(GrafoM *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        free(G->Mat[v]);
    }
    free(G->Mat);
    free(G);
}

/* Função para inserir uma aresta direcionada na lista de adjacências. */
void inserir_aresta_adj(GrafoA *G, int v, int w) {
    NoA *nova_aresta = (NoA *)malloc(sizeof(NoA));
    nova_aresta->id = w;
    nova_aresta->next = G->Adj[v];
    G->Adj[v] = nova_aresta;
}

/* Função para inserir uma aresta direcionada na matriz de adjacências. */
void inserir_aresta_mat(GrafoM *G, int u, int v) {
    G->Mat[u][v] = 1;
}

/* Função para imprimir a matriz de adjacências. */
void imprimir_matriz_adj(GrafoM *G) {
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

/* Função para imprimir a lista de adjacências. */
void imprimir_lista_adj(GrafoA *G) {
    printf("\nGrafo (lista adjacência):\n");
    for (int i = 0; i < G->V; i++) {
        printf("%d ->", i);

        // Armazenar os IDs dos vértices em um array para imprimir em ordem crescente
        int *vertice_ids = (int *)malloc(G->V * sizeof(int));
        int count = 0;

        NoA *current = G->Adj[i];
        while (current != NULL) {
            vertice_ids[count] = current->id;
            count++;
            current = current->next;
        }

        // Ordenar os IDs em ordem crescente
        for (int j = 0; j < count; j++) {
            for (int k = j + 1; k < count; k++) {
                if (vertice_ids[j] > vertice_ids[k]) {
                    int temp = vertice_ids[j];
                    vertice_ids[j] = vertice_ids[k];
                    vertice_ids[k] = temp;
                }
            }
        }

        // Imprimir os IDs ordenados
        for (int j = 0; j < count; j++) {
            printf(" %d", vertice_ids[j]);
        }

        free(vertice_ids);
        printf("\n");
    }
}

int main() {
    int V = 6; /* Número de vértices */

    GrafoA *G_lista_adj = criar_grafo_adj(V);
    GrafoM *G_matriz_adj = criar_grafo_mat(V);

    /* Inserção das arestas no grafo direcionado */
    inserir_aresta_adj(G_lista_adj, 0, 1);
    inserir_aresta_adj(G_lista_adj, 0, 5);
    inserir_aresta_adj(G_lista_adj, 1, 2);
    inserir_aresta_adj(G_lista_adj, 1, 3);
    inserir_aresta_adj(G_lista_adj, 2, 0);
    inserir_aresta_adj(G_lista_adj, 2, 4);
    inserir_aresta_adj(G_lista_adj, 3, 2);
    inserir_aresta_adj(G_lista_adj, 4, 3);
    inserir_aresta_adj(G_lista_adj, 5, 4);

    /* Atualização da matriz de adjacências a partir da lista de adjacências */
    for (int i = 0; i < V; i++) {
        NoA *current = G_lista_adj->Adj[i];
        while (current != NULL) {
            inserir_aresta_mat(G_matriz_adj, i, current->id);
            current = current->next;
        }
    }

    /* Impressão do grafo direcionado */
    imprimir_matriz_adj(G_matriz_adj);
    imprimir_lista_adj(G_lista_adj);

    /* Liberação da memória alocada */
    liberar_grafo_adj(G_lista_adj);
    liberar_grafo_mat(G_matriz_adj);

    return 0;
}
