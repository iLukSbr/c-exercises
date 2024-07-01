#include <stdio.h>

int main()
{
    int i, j=0, num, soma=0;
    for(i=1; i<=10; i++){
        printf("%do numero? ", i);
        scanf("%d", &num);
        if(num < 20){
            soma += num;
            j++;
        }
    }
    if(j == 0)
        j = 1;
    printf("Media = %f", (float) soma/j);
    return 0;
}
