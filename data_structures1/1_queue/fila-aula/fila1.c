#include <stdio.h>
#include <stdlib.h>

int empty (int *front, int back) {
  return (*front == back);
}

int full (int *back, int size) {
  return (*back >= size);
}

void enqueue (int array[], int *back, int size, int elem) {
  if (full(back, size)) {
    printf("queue overflow\n");
    exit(1);
  }
  else {
    array[*back] = elem;
    (*back)++;
  }
}

int dequeue (int array[], int *front, int back) {
  if (empty(front, back)) {
    printf("queue underflow\n");
    exit(1);
  }
  else {
    int elem = array[*front];
    (*front)++;
    return elem;
  }
}

void imprimir (int array[], int front, int back) {
  int i;
  printf("Fila: ");
  for (i = front; i < back; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int size = 3;	
  int front = 0;
  int back = 0;
  int array[size];  
  enqueue (array, &back, size, 0);
  enqueue (array, &back, size, 2);
  enqueue (array, &back, size, 4);
  imprimir (array, front, back);
  printf("Retirei: %d\n", dequeue(array, &front, back));
  imprimir (array, front, back);
  printf("Retirei: %d\n", dequeue(array, &front, back));
  imprimir (array, front, back);
  enqueue (array, &back, size, 8);
  imprimir (array, front, back);
  return 0;
}
