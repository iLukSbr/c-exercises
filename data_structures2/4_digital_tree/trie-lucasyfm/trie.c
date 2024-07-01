/* Lista Árvore Digital / Trie */
/* Lucas Yukio Fukuda Matsumoto - 2516977 */

#include "trie.h"

/* */
Trie *create_node(char data){
  Trie *node = (Trie*)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size
  for(i = 0; i < size; i++) {
    node->keys[i] = NULL;
  }
  return node;
}

/* */
void free_node(Trie *node){
  int i;
  for(i = 0; i < size; i++){
    if(node->keys[i] != NULL){
      free_node(node->keys[i]);
    }
  }
  free (node);
}

/* */
Trie *insert(Trie *root, char *word){
    Trie *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // Assuming lowercase letters only
        if (current->keys[index] == NULL) {
            current->keys[index] = create_node(word[i]);
            current->nchild++;
        }
        current = current->keys[index];
    }
    current->end = TRUE;
    return root;
}

/* */
int search_auxiliary(Trie *root, char *word){
    Trie *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // Assuming lowercase letters only
        if (current->keys[index] == NULL) {
            return FALSE; // Word not found
        }
        current = current->keys[index];
    }
    return current != NULL && current->end;
}

void search(Trie *root, char *word){
  if(search_auxiliary (root, word))
    printf("Word %s found!\n", word);
  else
    printf("Error: word %s not found!\n", word);
}

/* */
void print(Trie *root, int level){
  if(root != NULL){
    int i;
    if(root->data == '\0')
      printf("(null)");
    for(i = 0; i < level; i++){
      printf("| ");
    }
    printf("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for(i = 0; i < size; i++) {
      print(root->keys[i], level+1);
    }
  }
}

void delete(Trie *root, char *word){
    Trie *current = root;
    Trie *path[size]; // To keep track of nodes along the path
    int depth = 0;
    int i;

    // Traverse the Trie to find the word
    for (i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // Assuming lowercase letters only
        path[depth] = current;
        depth++;

        if (current->keys[index] == NULL) {
            // Word not found
            return;
        }
        current = current->keys[index];
    }

    if (current->end) {
        current->end = FALSE; // Mark the end flag as FALSE
    }

    // Traverse back and clean up the Trie if necessary
    for (i = depth - 1; i >= 0; i--) {
        int index = word[i] - 'a'; // Assuming lowercase letters only
        if (current->nchild == 0 && !current->end) {
            free(current);
            path[i]->keys[index] = NULL;
            current = path[i];
        } else {
            break;
        }
    }
}
