#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 1024

char* concatenaStrings(char* s1, char* s2);

char* empacotaString (char* string);

int main()
{
    char buffer[BUFLEN], *concatenado, *s1, *s2;
    fgets(buffer, BUFLEN, stdin);
    s1 = empacotaString(buffer);
    fgets(buffer, BUFLEN, stdin);
    s2 = empacotaString(buffer);
    concatenado = concatenaStrings(s1, s2);
    printf("\n%s", concatenado);
    free(s1);
    free(s2);
    free(concatenado);
}

char* concatenaStrings(char* s1, char* s2)
{
    char* concatenado;
    int tam1, tam2, i, j=0;
    tam1 = strlen(s1);
    tam2 = strlen(s2);
    concatenado = (char*) malloc((tam1+tam2+1)*sizeof(char));
    for(i=0; i<tam1; i++)
    {
        if(s1[i] != '\n')
            concatenado[i] = s1[i];
    }
    for(i=tam1; i<=tam1+tam2; i++)
    {
        if(s2[j] != '\n')
            concatenado[i] = s2[j];
        j++;
    }
    return concatenado;
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
