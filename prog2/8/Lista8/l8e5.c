#include <stdio.h>

#define MIN_TERMO 0.2

int main(){
    int i=1;
    double a=1, soma=0;
    while(a>MIN_TERMO){
        a = 1./i;
        soma += a;
        printf("%f    %f\n", a, soma);
        i++;
    }
    return 0;
}
