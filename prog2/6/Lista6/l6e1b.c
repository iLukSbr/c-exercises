#include <stdio.h>

int main()
{
    int i=1, j=0, num, soma=0;
    while(i <= 10){
        printf("%do numero? ", i);
        scanf("%d", &num);
        if(num < 20){
            soma += num;
            j++;
        }
        i++;
    }
    if(j == 0)
        j = 1;
    printf("Media = %f", (float) soma/j);
    return(0);
}
