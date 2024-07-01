#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 50

void balanceamentoDeParenteses(char* str, int* parenteses);

int main()
{
    char str[BUFLEN], *copia, *parenteses;
    fgets(str, BUFLEN, stdin);
    copia = empacotaString (string);
    balanceamentoDeParenteses(copia, parenteses);
    return 0;
}

void balanceamentoDeParenteses(char* str, int* parenteses)
{
    int tam, i, pos;
    tam = strlen(str);
    parenteses = (int*) malloc(tam*sizeof(int));
    for(i=0; i<tam; i++)
        parenteses[i] = 0;
    for(i=0; i<tam; i++)
    {
        if(str[i] == '(')
        {

        }
    }
}

char* empacotaString (char* string)
{
    int i, tam;
    char* copia;
    tam = strlen(string)+1;
    copia = (char*) malloc(tam*sizeof(char));
    for(i=0; i<tam; i++)
        copia[i] = string[i];
    return copia;
}
