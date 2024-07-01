#include<stdio.h>

int main()
{
    int n, num, ant, i=1, cresc=0, decresc=0;
    printf("Quantidade de numeros = ");
    scanf("%d", &n);
    if(n>0){
        printf("num%d = ", i);
        scanf("%d", &ant);
    }
    for(i=2; i<=n; i++){
        printf("num%d = ", i);
        scanf("%d", &num);
        if(ant<num)
            cresc = 1;
        else if(ant>num)
            decresc = 1;
        ant = num;
    }
        if(decresc==0 && cresc==1)
            printf("Crescente.");
        else if(decresc==1 && cresc==0)
            printf("Decrescente.");
        else
            printf("Nenhum dos casos.");
    return 0;
}
