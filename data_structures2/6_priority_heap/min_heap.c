/* Lucas Yukio Fukuda Matsumoto */

#include <stdio.h>
#include <stdlib.h>

int pai(int i){
   return (i - 1)/2;
}

int esquerda(int i){
   return (i * 2) + 1;
}

int direita(int i){
   return (i * 2) + 2;
}

void trocar(int *V, int a, int b){
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir(int *V, int size){
   int i;
   for(i = 0; i < size; i++)
      printf("%d ", V[i]);
   printf("\n");
}

void min_heapify(int *V, int size, int i){
   int e = esquerda(i);
   int d = direita(i);
   int menor;
   if(e < size && V[e] < V[i])
      menor = e;
   else
      menor = i;
   if(d < size && V[d] < V[menor])
      menor = d;
   if(menor != i){
      trocar(V, i, menor);
      min_heapify(V, size, menor);
   }
}

void build_min_heap(int *V, int size){
    for(int i = size/2 - 1; i >= 0; i--)
        min_heapify(V, size, i);
}

int heap_extract_min(int *V, int *size){
    if(*size <= 0)
        return -1;
    int min = V[0];
    V[0] = V[*size - 1];
    (*size)--;
    min_heapify(V, *size, 0);
    return min;
}

void heap_decrease_key(int *V, int i, int chave, int size){
   V[i] = chave;
   while(i > 0 && V[pai(i)] > V[i]){
      trocar(V, i, pai(i));
      i = pai(i);
   }
}

void min_heap_insert(int *V, int chave, int *size){
  V[*size] = chave;
  *size += 1;
  int i = *size - 1;
  while(i > 0 && V[pai(i)] > V[i]){
    trocar(V, i, pai(i));
    i = pai(i);
  }
}

int main(){
    int size = 10;
    int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    imprimir(V, size);
    build_min_heap(V, size);
    imprimir(V, size);
    heap_extract_min(V, &size);
    imprimir(V, size);
    heap_decrease_key(V, size-1, 1, size);
    imprimir(V, size);
    min_heap_insert(V, 0, &size);
    imprimir(V, size);
    return 0;
}
