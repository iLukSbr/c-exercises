#include "list.h"
#include <limits.h>

/* */
int maior (int a, int b) {
  return (a > b ? a : b);
}

int max (List *l) {
  if(l != NULL)
    return maior (l->data, maior());
  else
    return i;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Max = %d\n", max(l,3));
  destroy (l);
  return 0;
}
