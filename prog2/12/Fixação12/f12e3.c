#include <stdio.h.>

int main(){
    int p, a;
    a = 20;
    p = &a;
    printf("%p", p);
    p = 5;
    printf("%d", p);
    *p = 1;
    printf("%d", p);
    return 0;
}

