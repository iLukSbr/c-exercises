//Aluno: Lucas Yukio Fukuda Matsumoto
//Matrícula: 2516977
//Lista de Exercícios de Reforço
//Exercício 4)

#include "list.h"

List* add (List *lx, List *ly){
    List *lz = create();
    Node *tx=lx->tail, *ty=ly->tail;
    int tmp = 0;
    while(tx || ty){
        if(tx){
            tmp += tx->data;
            tx = tx->prev;
        }
        if(ty){
            tmp += ty->data;
            ty = ty->prev;
        }
        insert_front(lz, tmp%10);
        tmp /= 10;
    }
    if(tmp)
        insert_front(lz, tmp);
    return lz;
}

int main () {

  /* Resultado esperado:
   * List (head-tail): 9 9        <- X
   * List (head-tail): 9 9 4 5    <- Y
   * List (head-tail): 1 0 0 4 4  <- X + Y
   * */

  int k;

  List *lx = create ();
  int nx = 2;
  int x[] = {9,9};
  for (k = 0; k < nx; k++)
    insert_back (lx, x[k]);
  print_head_to_tail (lx);

  List *ly = create ();
  int ny = 4;
  int y[] = {9,9,4,5};
  for (k = 0; k < ny; k++)
    insert_back (ly, y[k]);
  print_head_to_tail (ly);

  List *lz = add (lx, ly);
  print_head_to_tail (lz);

  destroy (lx);
  destroy (ly);
  destroy (lz);
  return 0;
}
