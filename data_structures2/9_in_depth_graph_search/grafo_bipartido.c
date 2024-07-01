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
    int corVertice;
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

int DFS_Visit (GrafoA *G, int u, DFS *V) {
    NoA *v;
    V[u].cor = CINZA;
    for (v = G->Adj[u]; v != NULL; v = v->next) {
        if (V[v->id].cor == BRANCO) {
            V[v->id].pai = u;
            V[v->id].corVertice = 1 - V[u].corVertice;
            if (!DFS_Visit(G, v->id, V)) {
                return 0;
            }
        } else if (V[v->id].corVertice == V[u].corVertice) {
            return 0;
        }
    }
    V[u].cor = PRETO;
    return 1;
}

int Busca_Profundidade (GrafoA *G) {
    int u;
    DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
    for (u = 0; u < G->V; u++) {
        V[u].cor = BRANCO;
        V[u].pai = NIL;
        V[u].corVertice = 0;
    }
    for (u = 0; u < G->V; u++) {
        if (V[u].cor == BRANCO) {
            if (!DFS_Visit (G, u, V)) {
                return 0;
            }
        }
    }
    return 1;
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
    if (Busca_Profundidade(Ga)) {
        printf("O grafo e bipartido.\n");
    } else {
        printf("O grafo nao e bipartido.\n");
    }
    return 0;
}
