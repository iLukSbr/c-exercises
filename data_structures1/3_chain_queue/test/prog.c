#include "list.h"

int soma (List *l) {
	int s = 0;
	List *t = l;
	for (t = l; t != NULL; t = t->next)
		s++;
	return s;
}

int main () {
	List *l = create();
	int i;
	for (i=0; i < 10; i++)
		l = insert_front (l, i);
	print (l);
	return 0;
}
