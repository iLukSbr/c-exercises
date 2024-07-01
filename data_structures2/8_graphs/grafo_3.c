// Lucas Yukio Fukuda Matsumoto 2516977

#include <stdio.h>
#include <stdlib.h>

/* Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
    int id;           /* Identificador armazenado no nó. */
    int peso;         /* Peso da aresta (0 se não houver aresta). */
    struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/* Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
    int E;    /* Quantidade de arestas. */
    int V;    /* Quantidade de vértices. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/* Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
    int E;    /* Quantidade de arestas. */
    int V;    /* Quantidade de vértices. */
    int **Mat; /* Matriz de adjacências. */
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
    int v;
    GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **)malloc(tamanho * sizeof(int *));
    for (v = 0; v < G->V; v++) {
        G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
        for (int w = 0; w < G->V; w++) {
            G->Mat[v][w] = 0;
        }
    }
    return G;
}

/* Função para destruir um grafo construído com lista de adjacências. */
void liberar_grafo_adj(GrafoA *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        NoA *current = G->Adj[v];
        while (current != NULL) {
            NoA *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G->Adj);
    free(G);
}

/* Função para destruir um grafo construído com matriz de adjacências. */
void liberar_grafo_mat(GrafoM *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        free(G->Mat[v]);
    }
    free(G->Mat);
    free(G);
}

/* Função para inserir uma aresta em um grafo com lista de adjacências. */
void inserir_aresta_adj(GrafoA *G, int u, int v, int peso) {
    NoA *novo = (NoA *)malloc(sizeof(NoA));
    novo->id = v;
    novo->peso = peso;
    novo->next = G->Adj[u];
    G->Adj[u] = novo;
}

/* Função para inserir uma aresta em um grafo com matriz de adjacências. */
void inserir_aresta_mat(GrafoM *G, int u, int v, int peso) {
    G->Mat[u][v] = peso;
}

/* Função para imprimir o grafo com matriz de adjacências. */
void imprimir_grafo_mat(GrafoM *G) {
    printf("\nGrafo (matriz adjacência):\n");
    printf("   ");
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

        NoA *current = G->Adj[i];
        while (current != NULL) {
            printf(" %d (w:%d)", current->id, current->peso);
            current = current->next;
        }
        printf("\n");
    }
}

/* Função para contar o número de arestas incidentes a um vértice. */
int contar_arestas_incidentes(GrafoA *G, int vertice) {
    int count = 0;
    for (int i = 0; i < G->V; i++) {
        NoA *current = G->Adj[i];
        while (current != NULL) {
            if (current->id == vertice) {
                count++;
            }
            current = current->next;
        }
    }
    return count;
}

/* Função para contar o número de arestas que saem de um vértice. */
int contar_arestas_que_saem(GrafoA *G, int vertice) {
    int count = 0;
    NoA *current = G->Adj[vertice];
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* Função para imprimir vértices adjacentes a um vértice. */
void imprimir_vertices_adjacentes(GrafoA *G, int vertice) {
    printf("\nVértices adjacentes ao vértice %d:", vertice);
    for (int i = 0; i < G->V; i++) {
        NoA *current = G->Adj[i];
        while (current != NULL) {
            if (current->id == vertice) {
                printf(" %d", i);
            }
            current = current->next;
        }
    }
    printf("\n");
}

int main() {

    int Va = 6; /* Número de vértices */

    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /* Número de vértices */

    GrafoM *Gm = criar_grafo_mat(Vm);

    inserir_aresta_adj(Ga, 0, 1, 1);
    inserir_aresta_adj(Ga, 0, 3, 5);
    inserir_aresta_adj(Ga, 1, 3, 8);
    inserir_aresta_adj(Ga, 2, 0, 5);
    inserir_aresta_adj(Ga, 2, 3, 4);
    inserir_aresta_adj(Ga, 3, 3, 6);
    inserir_aresta_adj(Ga, 3, 4, 3);
    inserir_aresta_adj(Ga, 4, 2, 7);
    inserir_aresta_adj(Ga, 4, 5, 9);
    inserir_aresta_adj(Ga, 5, 0, 2);

    inserir_aresta_mat(Gm, 0, 1, 1);
    inserir_aresta_mat(Gm, 0, 3, 5);
    inserir_aresta_mat(Gm, 1, 3, 8);
    inserir_aresta_mat(Gm, 2, 0, 5);
    inserir_aresta_mat(Gm, 2, 3, 4);
    inserir_aresta_mat(Gm, 3, 3, 6);
    inserir_aresta_mat(Gm, 3, 4, 3);
    inserir_aresta_mat(Gm, 4, 2, 7);
    inserir_aresta_mat(Gm, 4, 5, 9);
    inserir_aresta_mat(Gm, 5, 0, 2);

    imprimir_grafo_mat(Gm);
    imprimir_lista_adj(Ga);

    int vertice3_incidentes = contar_arestas_incidentes(Ga, 3);
    int vertice4_saindo = contar_arestas_que_saem(Ga, 4);

    printf("\nNúmero de arestas incidentes ao vértice 3: %d\n", vertice3_incidentes);
    printf("Número de arestas que saem do vértice 4: %d\n", vertice4_saindo);

    imprimir_vertices_adjacentes(Ga, 2);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);

    return 0;
}
