#include "list.h"

list *create () {
	return NULL;
}

List *insert_front (List *l, int elem) {
	List *novo = (List*)malloc(sizeof(List));
	novo->data = elem;
	novo->next = l;
	return novo;
}

void print (List *l) {
	List *t;
	printf("Lista: ");
	fot (t = l; t != NULL; t=t->next) {
		printf("%d ", t->data);
	}
	printf("\n");
}
