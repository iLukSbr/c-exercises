// Lucas Yukio Fukuda Matsumoto - 2516977

#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NIL -1

typedef struct noA {
   int id;
   struct noA *next;
} NoA;

typedef struct grafoA {
   int E;
   int V;
   NoA **Adj;
} GrafoA;

typedef struct dfs {
    int cor;
    int pai;
    int d;
    int f;
} DFS;

NoA* criar_no(int id) {
    NoA* no = (NoA*) malloc(sizeof(NoA));
    no->id = id;
    no->next = NULL;
    return no;
}

GrafoA* criar_grafo_adj (int tamanho) {
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

void adicionar_aresta(GrafoA* G, int origem, int destino) {
    NoA* no = criar_no(destino);
    no->next = G->Adj[origem];
    G->Adj[origem] = no;
}

void DFS_Visit (GrafoA *G, int u, DFS *V, int *tempo) {
    NoA *v;
    V[u].cor = CINZA;
    V[u].d = ++(*tempo);
    for (v = G->Adj[u]; v != NULL; v = v->next) {
        if (V[v->id].cor == BRANCO) {
            V[v->id].pai = u;
            printf("Aresta arvore: (%d - %d)\n", u, v->id);
            DFS_Visit(G, v->id, V, tempo);
        } else if (V[v->id].cor == CINZA) {
            printf("Aresta outra : (%d - %d)\n", u, v->id);
        }
    }
    V[u].cor = PRETO;
    V[u].f = ++(*tempo);
}

void Busca_Profundidade (GrafoA *G) {
    int u;
    DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
    for (u = 0; u < G->V; u++) {
        V[u].cor = BRANCO;
        V[u].pai = NIL;
    }
    int tempo = 0;
    for (u = 0; u < G->V; u++) {
        if (V[u].cor == BRANCO) {
            DFS_Visit (G, u, V, &tempo);
        }
    }
    printf("\n");
    for (u = 0; u < G->V; u++) {
        if (V[u].pai == NIL) {
            printf("Componente: ");
            for (int v = 0; v < G->V; v++) {
                if (V[v].pai == u || v == u) {
                    printf("%d ", v);
                }
            }
            printf("\n");
        }
    }
}

int main () {
    int Va = 12;
    GrafoA* Ga = criar_grafo_adj (Va);
    adicionar_aresta(Ga, 0, 1);
    adicionar_aresta(Ga, 1, 2);
    adicionar_aresta(Ga, 2, 5);
    adicionar_aresta(Ga, 5, 4);
    adicionar_aresta(Ga, 4, 1);
    adicionar_aresta(Ga, 5, 6);
    adicionar_aresta(Ga, 6, 0);
    adicionar_aresta(Ga, 6, 3);
    adicionar_aresta(Ga, 6, 4);
    adicionar_aresta(Ga, 0, 3);
    adicionar_aresta(Ga, 7, 8);
    adicionar_aresta(Ga, 9, 10);
    adicionar_aresta(Ga, 10, 11);
    adicionar_aresta(Ga, 11, 9);
    Busca_Profundidade(Ga);
    return 0;
}
