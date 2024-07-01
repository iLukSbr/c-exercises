#include "queue.h"
#include <time.h>

int main () {
  srand(time(NULL));
  int i, n = 10;
  Queue *par = create (n); /*fila de pares*/
  Queue *imp = create (n); /*fila de ímpares*/
  while (i < n) {
    int sorteio = rand() % 100;
    if (sorteio % 2) {
      enqueue (imp, sorteio);	    
    }
    else {
      enqueue (par, sorteio);	    
    }
    i++;
  }
  printf("Fila de pares: ");
  print (par);
  destroy (par);
  printf("Fila de ímpares: ");
  print (imp);
  destroy (imp);
  return 0;
}

