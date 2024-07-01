//****exe1***
//====Matriz de adjacências
/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

/*-----------Init Matriz--------------------*/
void inicializar_grafo_mat (GrafoM *G) {
   int u, v; 
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
         G->Mat[u][v] = 0;
      }
   } 
}

/*----------Add aresta Matriz---------------------*/
void _adicionar_aresta_grafo_mat (int u, int v, GrafoM *G, int peso) {
   if (G->Mat[u][v] == 0) {
      G->Mat[u][v]=1;
   }
   else {
      printf("a aresta (%d,%d) já existe!!!", u, v);
   }
   G->E++;
}

void adicionar_aresta_grafo_mat (int u, int v, GrafoM *G) {
   //bidirecional	
   _adicionar_aresta_grafo_mat (u, v, G,1);
   _adicionar_aresta_grafo_mat (v, u, G,1);
}

//====Lista de adjacências

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Função para criar um grafo com lista de adjacências.*/
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

/*----------Add aresta Lista---------------------*/
void _adicionar_aresta_grafo_adj (int u, int v, GrafoA *G) {
   NoA *aux, *ultimo = NULL;
   //percorre lista de adj até chegar ao último nó
   for (aux = G->Adj[u]; aux != NULL; aux = aux->next) {
      if (aux->id == v) {
         printf("a aresta (%d,%d) já existe!!!", u, v);
         return;
      } 
      ultimo = aux;
   }
   //adiciona nova adj no final da lista 
   NoA *novo = (NoA *)malloc(sizeof(NoA));
   novo->id = v;
   novo->next = NULL;
   //lista já tinha elementos
   if (ultimo != NULL) {
      ultimo->next = novo;
   }
   //lista estava vazia
   else {
      G->Adj[u] = novo;
   }
   G->E++;
}

void adicionar_aresta_grafo_adj (int u, int v, GrafoA *G) {
   //bidirecional	
   _adicionar_aresta_grafo_adj (u, v, G);
   _adicionar_aresta_grafo_adj (v, u, G);
}


//******exe2*****
void adicionar_aresta_grafo_adj (int u, int v, GrafoA *G) {
   _adicionar_aresta_grafo_adj (u, v, G);
}

void adicionar_aresta_grafo_mat (int u, int v, GrafoM *G) {
   _adicionar_aresta_grafo_mat (u, v, G);
}

//******exe3*****
/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   int weight;      /*Peso do nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura para um nó em uma matriz de adjacências: */
typedef struct noM {
   int peso;       /*Peso armazenado na aresta. */
} NoM;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoM **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (NoM **)malloc(tamanho * sizeof(NoM *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (NoM *)malloc(tamanho * sizeof(NoM));
   }
   return G;
}

/*-------------------------------*/
void inicializar_grafo_mat (GrafoM *G) {
   int u, v; 
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
         G->Mat[u][v].peso = 0;
      }
   } 
}

/*-------------------------------*/
void _adicionar_aresta_grafo_mat (int u, int v, int w, GrafoM *G) {
   if (G->Mat[u][v].peso == 0) {
      G->Mat[u][v].peso = w;
   }
   else {
      printf("a aresta (%d,%d) já existe!!!", u, v);
   }
   G->E++;
}

//---- add aresta na matriz ---
void adicionar_aresta_grafo_mat (int u, int v, int w, GrafoM *G) {
   _adicionar_aresta_grafo_mat (u, v, w, G);
}

/*-------------------------------*/
void _adicionar_aresta_grafo_adj (int u, int v, int w, GrafoA *G) {
   NoA *aux, *ultimo = NULL;
   for (aux = G->Adj[u]; aux != NULL; aux = aux->next) {
      if (aux->id == v) {
         printf("a aresta (%d,%d) já existe!!!", u, v);
         return;
      } 
      ultimo = aux;
   } 
   NoA *novo = (NoA *)malloc(sizeof(NoA));
   novo->id = v;
   novo->weight = w;
   novo->next = NULL;
   if (ultimo != NULL) {
      ultimo->next = novo;
   }
   else {
      G->Adj[u] = novo;
   }
   G->E++;
}

//---- add aresta na lista ---
void adicionar_aresta_grafo_adj (int u, int v, int w, GrafoA *G) {
   _adicionar_aresta_grafo_adj (u, v, w, G);
}

/*---Arestas incidentes em u: Matriz---------*/
void imprimir_qtd_incidentes_mat (int u, GrafoM *G) {
   int sum = 0;
   int i;
   for (i = 0; i < G->V; i++) {
      if (G->Mat[i][u].peso != 0) {
         sum++;
      }
   }
   printf ("Número de arestas incidentes ao vértice %d: %d.\n", u, sum);   
}

/*---Arestas que saem de u: Matriz---------*/
void imprimir_qtd_vizinhos_mat (int u, GrafoM *G) {
   int sum = 0;
   int i;
   for (i = 0; i < G->V; i++) {
      if (G->Mat[u][i].peso != 0) {
         sum++;
      }
   }
   printf ("Número de arestas que saem do vértice %d: %d.\n", u, sum);   
}

/*---print todos vizinhos de u: Matriz---------*/
void imprimir_adjacentes_mat (int u, GrafoM *G) {
   printf ("Vértice adjacentes ao vértice %d: ", u);   
   int i;
   for (i = 0; i < G->V; i++) {
      if (G->Mat[u][i].peso != 0) {
         printf ("%d ", i);   
      }
   }
   printf (".\n");   
}


/*---Arestas incidentes em u: lista---------*/
void imprimir_qtd_incidentes_adj (int u, GrafoA *G) {
   int sum = 0, x;
   NoA *v;
   for (x = 0; x < G->V; x++) {
      for (v = G->Adj[x]; v != NULL; v = v->next) { 
         if (v->id == u) {
            sum++; 
         }
      } 
   }
   printf ("Número de arestas incidentes ao vértice %d: %d.\n", u, sum);   
}

/*---Arestas que saem de u: lista---------*/
void imprimir_qtd_vizinhos_adj (int u, GrafoA *G) {
   int sum = 0;
   NoA *v;
   for (v = G->Adj[u]; v != NULL; v = v->next) { 
      sum++; 
   }   
   printf ("Número de arestas que saem do vértice %d: %d.\n", u, sum);   
}

/*---print todos vizinhos de u: lista---------*/
void imprimir_adjacentes_adj (int u, GrafoA *G) {
   printf ("Vértice adjacentes ao vértice %d: ", u);  
   NoA *v;
   for (v = G->Adj[u]; v != NULL; v = v->next) { 
      printf ("%d ", v->id); 
   } 
   printf (".\n");   
}



