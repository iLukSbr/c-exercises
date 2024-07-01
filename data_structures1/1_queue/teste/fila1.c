#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int front;
  int back;
  int size;
  int *array;
} Queue;

Queue* create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (int *)malloc(size*sizeof(int));
  return q;
}

int empty (Queue *q) {
  return (q->back == q->front);
}

int full (Queue *q) {
  return (q->front == (q->back + 1)%q->size);
}

void enqueue (Queue *q, int e) {
  if (full(q)) {
    printf("queue overflow\n");
    exit(1);
  }
  else {
    q->array[q->back] = e;
    q->back = (q->back + 1) % q->size;
  }
}

int dequeue (Queue *q) {
  if (empty(q)) {
    printf("queue underflow");
    exit(1);
  }
  else {
    int e = q->array[q->front];
    (q->front)++;
  }
}

void imprimir (Queue *q) {
  int i;
  printf("Fila:");
  for(i = q->front; i != q->back; (i+1)%q->size){
    printf("%d", q->array[i]);
  }
  printf("\n");
}

int main () {
  int size = 3;
  Queue *q = create (size);
  enqueue (q, 0);
  enqueue (q, 2);
  enqueue (q, 4);
  imprimir (q);
  printf ("Remove: %d\n", dequeue(q));
  printf ("Remove: %d\n", dequeue(q));
  enqueue(q, 8);
  imprimir (q);
  return 0;
}
