//Lucas Yukio Fukuda Matsumoto - 2516977
#include <stdio.h>

void removeExtremos (int *n, int *pri, int *ult);

int main(){
    int n, pri, ult, aux, qtd=0, i;
    printf("Numero = ");
    scanf("%d", &n);
    while(aux > 0){
        aux /= 10;
        qtd++;
    }
    while(n>0){
        removeExtremos(&n, &pri, &ult);
        if(pri != ult){
            printf("Nao e palindromo");
            return 0;
        }
    }
    printf("Palindromo");
    return 0;
}

void removeExtremos (int *n, int *pri, int *ult){
    int tn, pot = 1;
    tn = *n;
    while(tn >= 10){
        tn = tn/10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}
