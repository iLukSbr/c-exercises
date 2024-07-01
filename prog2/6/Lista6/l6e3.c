#include <stdio.h>
int main(){
    int i;
    float n, soma, max=0, min=10;
    for(i=1; i<=6; i++){
        printf("Nota %d = ", i);
        scanf("%f", &n);
        soma += n;
        if(n > max)
            max = n;
        if(n < min)
            min = n;
    }
    printf("Nota final = %f", (soma - max - min)/4);
    return 0;
}
