/* Lista Árvore Digital / Trie */
/* Lucas Yukio Fukuda Matsumoto - 2516977 */

#include "trie.h"

int main(){

  Trie *root = create_node('\0');

  root = insert(root, "roupa");
  root = insert(root, "roupas");
  root = insert(root, "rato");
  root = insert(root, "casa");
  root = insert(root, "castor");
  root = insert(root, "mesa");
  root = insert(root, "morro");
  root = insert(root, "gorro");
  root = insert(root, "galho");

  print(root, 0);

  search(root, "mes");
  search(root, "tatu");
  search(root, "galhos");
  search(root, "casa");

  delete(root, "mes");
  delete(root, "tatu");
  delete(root, "galhos");
  delete(root, "roupa");

  print(root, 0);

  return 0;
}
