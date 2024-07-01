#ifndef __stack_h__
#define __stack_h__
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int peek;
  int size;
  int *array;
} Stack;

Stack* create (int size);
void destroy (Stack *s);
int empty (Stack *s);
int full (Stack *s);
void push (Stack *s, int e);
int pop (Stack *s);
void print (Stack *s);
int get_peek (Stack *s);
int get_size (Stack *s);

#endif
