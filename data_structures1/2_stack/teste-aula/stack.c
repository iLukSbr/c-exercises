#include "stack.h"

Stack* create (int size) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->peek = 0;
  s->size = size;
  s->array = (int *)malloc(size * sizeof(int));
  return s;
}

void destroy(Stack *s) {
  free(s->array);
  free(s);
 }

int empty (Stack *s) {
  return (s->peek == 0);
}

int full (Stack *s) {
  return (s->peek == s->size);
}

void push (Stack *s, int e) {
  if (full(s)) {
    printf("stack overflow\n");
    exit(1);
  }
  else {
    s->array[s->peek] = e;
    (s->peek)++;
  }
}

int pop (Stack *s) {
  if (empty(s)) {
    printf("stack underflow\n");
    exit(1);
  }
  else {
    (s->peek)--;
    return s->array[s->peek];
  }
}

void print (Stack *s) {
  int i;
  for (i = 0; i < s->peek; i++)
    printf("%d ", s->array[i]);
  printf(" (<- peek) \n");
}

int get_peek (Stack *s) {
  if (!empty(s))
    return s->array[s->peek-1];
  printf("empty\n");
  exit(1);
}
