//==================
/*==Exerc�cio 2===*/
//==================

#define BRANCO 1
#define CINZA  2
#define PRETO  3
#define VERMELHO  4

/*Estrutura para um v�rtice em uma lista encadeada: */
typedef struct dfs {
    int d;//instante de descoberta
    int f;//instante de finaliza��o
    int cor;
    int pai;
    int identificador; /*Identificador do v�rtice armazenado no n�. */
    struct dfs* proximo; /* Pr�ximo n� na lista encadeada. */
} DFS;


/*=== Impress�o arestas =====*/
void Busca_Profundidade(Grafo* G) {
    int u;
    int tempo = 0;
    //lista de v�rtices do grafo
    DFS* V(DFS*)malloc(G->V * sizeof(DFS));

    //inicializa��o para o DFS
    for (u = 0; u < G->V; u++) {
        V[u].cor = BRANCO;
        V[u].pai = -1;
    }

    for (u = 0; u < G->V; u++) {
        if (V[u].cor == BRANCO) {
            DFS_Visit(G, V, u, &tempo);
        }
    }
    printf("Busca em profundidade:\n");
    for (u = 0; u < G->V; u++) {
        printf("%2d = [d : %2d, f : %2d, pai : %2d]\n", u, V[u].d, V[u].f, V[u].pai);
    }
}

/* */
void DFS_Visit(Grafo* G, DFS* V, int u, int* tempo) {
    V[u].cor = CINZA;
    *tempo = (*tempo) + 1;
    V[u].d = (*tempo);
    DFS* v;
    for (v = G->listaAdj[u]; v != NULL; v = v->proximo) {
        if (V[v->identificador].cor == BRANCO) {
            V[v->identificador].pai = u;
            DFS_Visit(G, V, v->identificador, tempo);
        }
    }
    V[u].cor = PRETO;
    *tempo = (*tempo) + 1;
    V[u].f = *tempo;
}


//==================
/*==Exerc�cio 3===*/
//==================
void Busca_Profundidade(Grafo* G) {
    int u;
    int tempo = 0;
    //lista de v�rtices do grafo
    DFS* V = (DFS*)malloc(G->V * sizeof(DFS));

    //inicializa��o para o DFS
    for (u = 0; u < G->V; u++) {
        V[u].cor = BRANCO;
        V[u].pai = -1;
    }

    int pinta_cor = VERMELHO;

    for (u = 0; u < G->V; u++) {
        if (V[u].cor == BRANCO) {
            DFS_Visit(G, V, u, &tempo, pinta_cor);
        }
    }

    printf("O grafo � bipartido\n");

}

/* */
void DFS_Visit(Grafo* G, DFS* V, int u, int* tempo, int pinta_cor) {
    //V[u].cor = CINZA;
    V[u].cor = pinta_cor;
    *tempo = (*tempo) + 1;
    V[u].d = (*tempo);
    DFS* v;
    for (v = G->listaAdj[u]; v != NULL; v = v->proximo) {
        //if (V[v->identificador].cor == BRANCO) {
        if (V[v->identificador].cor == pinta_cor) {
            printf("O grafo n�o � bipartido!\n");
            exit(1);
        else if (V[v->identificador].cor == BRANCO)
            V[v->identificador].pai = u;
        DFS_Visit(G, V, v->identificador, tempo, (pinta_cor == VERMELHO ? PRETO : VERMELHO));
        }
    }
    V[u].cor = PRETO;
    *tempo = (*tempo) + 1;
    V[u].f = *tempo;
}