#include <stdio.h>

int main()
{
    int i, n;
    for(i=1000; i<=9999; i++){
        n = i/100 + i%100;
        if(n*n == i)
            printf("%d\n", i);
    }
    return 0;
}
