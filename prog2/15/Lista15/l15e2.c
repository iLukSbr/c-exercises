#include <stdio.h>
#define N 1000

unsigned int contaPalavras(char *frase);

int main()
{
    char frase[N];
    fgets(frase, N, stdin);
    printf("\n%u palavra(s)\n", contaPalavras(frase));
    return 0;
}

unsigned int contaPalavras(char *frase)
{
    unsigned int i, palavras=0;
    for(i=0; frase[i]!='\0'; i++)
    {
        if(((frase[i]>='A' && frase[i]<='Z')||(frase[i]>='a' && frase[i]<='z')) && (frase[i+1]<'A' || (frase[i+1]>'Z' && frase[i+1]<'a') || frase[i+1]>'z'))
            palavras++;
    }
    return palavras;
}
