#include "stack.h"

int main() {
  Stack *p = create(3);
  push(p, 0);
  push(p, 2);
  push(p, 4);
  print(p);
  while(!empty)
    printf("Retirei: %d\n", pop(p));
  destroy (p);
  return 0;
}
