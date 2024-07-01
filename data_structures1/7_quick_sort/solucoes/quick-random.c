#include "utils.h"

/* */
int partition (int A[], int left, int right) {
  int pivot = A[right];
  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (A[j] <= pivot) {
      i += 1;
      swap (A, i, j);
    }
  }
  swap (A, i+1, right);
  return i+1;
}

/* */
int random_partition (int A[], int left, int right) {
  int rand_pivot = rand() % (right - left + 1) + left;
  if ((rand_pivot < left) || (rand_pivot > right)) {
    printf("error: pivot out of interval!\n");
    exit(1);
  }
  swap (A, rand_pivot, right);   
  return partition (A, left, right);
}

/* */
void quick_sort (int *A, int left, int right) {
  if (left < right) {
    int pivot = random_partition (A, left, right);
    quick_sort (A, left, pivot-1);
    quick_sort (A, pivot+1, right); 
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
  int n = atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }  

  start = clock();
  //print (A, n, "Input");
  quick_sort (A, 0, n-1);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

