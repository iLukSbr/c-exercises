#include <stdlib.h>
#include <stdio.h>

typedef  struct node {
	int data;
	struct node* next;
} List;

List *create ();
List *insert_front (List *l, int elem);
void print (List *l);
