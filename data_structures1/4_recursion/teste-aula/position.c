#include "list.h"
#include <limits.h>

/* */
int position (List *l, int k){
  int i = 0;
  if(l != NULL){
    if(l->data == k)
      return i;
    else
      i = 1 + position(l->next);
  }
  else
    return -1;
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
