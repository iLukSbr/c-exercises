#include "abbListaLucasYukio.h"

Arvore* cria_arvore_vazia(){
   return NULL;
}

void arvore_libera(Arvore* a){
   if(!a){
      arvore_libera(a->esq);
      arvore_libera(a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir(Arvore *a, int v){
	if(!a){
		a = (Arvore*)malloc(sizeof(Arvore));
		a->info = v;
		a->esq = NULL;
		a->dir = NULL;
		return a;
	}
	else if(v < a->info)
		a->esq = inserir(a->esq, v);
	else
		a->dir = inserir(a->dir, v);
	return a;
}

//========= Q1 - remover
Arvore* remover(Arvore *a, int v){
    if (!a)
        return a;
    if (v < a->info)
        a->esq = remover(a->esq, v);
    else if (v > a->info)
        a->dir = remover(a->dir, v);
    else{
        if(!a->esq){
            Arvore* tmp = a->dir;
            return tmp;
        }
		else if(!a->dir){
            Arvore* tmp = a->esq;
            return tmp;
        }
        Arvore* maior = a->dir;
        while(maior->esq)
            maior = maior->esq;
        a->info = maior->info;
        a->dir = remover(a->dir, maior->info);
    }
    return a;
}


//========= Q1 - busca
int buscar(Arvore *a, int v){
  if(!a)
  	return 0;
  else if(v < a->info)
  	return buscar(a->esq, v);
  else if(v > a->info)
  	return buscar(a->dir, v);
  else
  	return 1;
}

//========= Q2 - min =====
int min(Arvore *a){
	if(!a)
		return NULL;
	if(a->esq)
		return min(a->esq);
	else
		return NULL;
}

//========= Q2 - max =====
int max(Arvore *a){
	if(!a)
		return NULL;
	if(a->dir)
		return max(a->dir);
	else
		return NULL;
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a){
	if(a->dir)
		imprime_decrescente(a->dir);
	if(a->esq)
		imprime_decrescente(a->esq);
	printf("%d\n", a->info);
}

//========= Q4 - maior ramo =====
#ifndef maxval
    #define maxval(a, b) (a>b ? a:b)
#endif

int maior_ramo(Arvore* a){
    if(!a)
        return 0;
    return a->info + maxval(maior_ramo(a->esq), maior_ramo(a->dir));
}

void pre_order(Arvore* a){
   if(!a){
      printf("%d ", a->info);
      pre_order(a->esq);
      pre_order(a->dir);
   }
}

void conta_tempo(Arvore *a){
	clock_t begin, end;
   	begin = clock();
   	int tmp = buscar(a, 100000);
   	end = clock();
   	printf("Encontrado: %d\t Tempo: %lf\n", tmp, (double)(end - begin)/CLOCKS_PER_SEC);
}

int main(){
	srand(time(NULL));
   	int i, j, tmp[100000], temp;
   	Arvore *a = cria_arvore_vazia();
//	a = inserir(a, 50);
//	a = inserir(a, 30);
//	a = inserir(a, 90);
//	a = inserir(a, 20);
//	a = inserir(a, 40);
//	a = inserir(a, 95);
//	a = inserir(a, 10);
//	a = inserir(a, 35);
//	a = inserir(a, 45);
//	printf("\n");
//	pre_order(a);
//	printf("\n");
//   // ====== Q5 ====
//   	arvore_libera(a);
   	for(i=0; i<100000; i++){
        tmp[i] = i;
        a = inserir(a, i);
    }
	conta_tempo(a);
   	arvore_libera(a);
    for(i=99999; i>0; i--){
        j = rand()%(i+1);
        temp = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = temp;
    }
    for(i=0; i<100000; i++)
        a = inserir(a, tmp[i]);
	conta_tempo(a);
	arvore_libera(a);
   	return 0;
}
