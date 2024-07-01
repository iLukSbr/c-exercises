#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 1024

char* empacotaString (char* string);

int main()
{
    char buffer[BUFLEN], *copia;
    fgets(buffer, BUFLEN, stdin);
    copia = empacotaString(buffer);
    printf("\n%s\n", copia);
    free(copia);
    return 0;
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
