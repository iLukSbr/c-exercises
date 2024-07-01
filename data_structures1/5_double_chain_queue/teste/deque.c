#include "deque.h"

/* */
Deque* create_deque () {
  return NULL;
}

/* */
Point get_front (Deque *d) {
  if (d != NULL) {
    return d->p;
  }
}

/* */
Point get_back (Deque *d) {
  if (d != NULL) {
    Deque *aux = d; 
    while (aux->next != NULL) {
      aux = aux->next;
    }
    return aux->p;
  }
}

/* */
Deque* insert_front (Deque *d, Point p, char field[][SIZE]) {
	Node *n = (Node*)malloc(sizeof(Node));
	
}

Deque* insert_back (Deque *d, Point p, char field[][SIZE]) {
	Node *n = (Node*)malloc(sizeof(Node));

}

Deque* delete_front (Deque *d, char field[][SIZE]) {
		
}

Deque* delete_back (Deque *d, char field[][SIZE]) {
		
}
