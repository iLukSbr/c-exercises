#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int front;
  int back;
  int size;	
  int *array; 
} Queue;  

Queue *create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;	
  q->array = (int *)malloc(size * sizeof(int)); 
  return q;
}  

int empty (Queue *q) {
  return (q->front == q->back);
}

int full (Queue *q) {
  return (q->back >= q->size);
}

void enqueue (Queue *q, int elem) {
  if (full(q)) {
    printf("queue overflow\n");
    exit(1);
  }
  else {
    q->array[q->back] = elem;
    (q->back)++;
  }
}

int dequeue (Queue *q) {
  if (empty(q)) {
    printf("queue underflow\n");
    exit(1);
  }
  else {
    int elem = q->array[q->front];
    (q->front)++;
    return elem;
  }
}

void imprimir (Queue *q) {
  int i;
  printf("Fila: ");
  for (i = q->front; i < q->back; i++) {
    printf("%d ", q->array[i]);
  }
  printf("\n");
}

int main() {
  int size = 3;	
  Queue *q = create (size);	
  enqueue (q, 0);
  enqueue (q, 2);
  enqueue (q, 4);
  imprimir (q);
  printf("Retirei: %d\n", dequeue(q));
  imprimir (q);
  printf("Retirei: %d\n", dequeue(q));
  imprimir (q);
  enqueue (q, 8);
  imprimir (q);
  return 0;
}
