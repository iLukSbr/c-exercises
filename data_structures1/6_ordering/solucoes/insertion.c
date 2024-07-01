#include "utils.h"

/* */
void insertion_sort (int *A, int n) {
  int i;
  for (i = 1; i < n; i++) {
    int key = A[i];
    int j = i-1;
    while ( (j >= 0) && (key < A[j]) ) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
}

/* */
void _insertion_sort (int *A, int n) {
  int i;
  for (i = 1; i < n; i++) {
    int key = A[i];
    int j;
    for (j = i-1; (j >= 0) && (key < A[j]); j--) {
      A[j+1] = A[j];
    }
    A[j+1] = key;
  }
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
   
  int i;
  int n = atoi(argv[1]);
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  print (A, n, "Input");
  _insertion_sort (A, n);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}
