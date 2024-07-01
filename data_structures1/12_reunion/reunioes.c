#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  int inicio;
  int fim;
} Reunioes;

int compare (const void *a, const void *b) {
  Reunioes *A = (Reunioes *) a;
  Reunioes *B = (Reunioes *) b;
  return (A->inicio >= B->inicio);
}

int print (Reunioes R[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("R[%d] = {%d,%d}\n", i, R[i].inicio, R[i].fim);	  
  }
}

int forca_bruta (Reunioes R[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if ( (i != j) && (R[j].fim >= R[i].inicio) && (R[j].inicio <= R[i].fim) ) {
	return FALSE;      
      }	      
    }	    
  }
  return TRUE;
}

int otimizado (Reunioes R[], int n) {
  int i, j;
  /*melhor usar merge do que o quick abaixo para garantir nlogn*/
  qsort (R, n, sizeof(Reunioes), compare); 
  print (R, n);
  for (i = 0; i < n-1; i++) {
    if (R[i].fim >= R[i+1].inicio) { 
      return FALSE;      
    }	    
  }
  return TRUE;
}

int main () {
  int n = 3;
  Reunioes R[3] = {{15,20},{0,30},{5,10}};
  //int n = 2;
  //Reunioes R[2] = {{7,10},{2,4}};
  print (R, n);
  printf ("Força-bruta: %d\n", forca_bruta (R, n));
  printf ("Otimizado: %d\n", otimizado (R, n));
  return 0;	
}
