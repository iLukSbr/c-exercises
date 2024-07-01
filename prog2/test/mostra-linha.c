#include <stdio.h>
#define N 50

void mostraLinha(int n, int linha);

int main(){
    int n, linha;
    for(n=3; n<=N; n++){
        for(linha=1; linha<=n+2; linha++)
            mostraLinha(n, linha);
    }
    return 0;
}

void mostraLinha(int n, int linha){
    int i;
    if(linha == 1)
        printf("%d\n", n);
    else if(linha == n+2)
        printf("\n");
    else if(linha == 2){
        for(i=1; i<=n; i++)
            printf("$");
    }
    else if(linha == n+1)
        printf("\n$\n");
    else{
        printf("\n");
        for(i=n-linha+1; i>0; i--)
            printf(" ");
        printf("$");
    }
}
