#include <stdio.h>
int main(){
    int i;
    float s_vai, s_vem;
    for(i=1; i<=1000000; i++)
    {
        if(i%2 == 0)
            s_vai += -1/i;
        else
            s_vai += 1/i;
    }
    for(i=1000000; i>=1; i--)
    {
        if(i%2 == 0)
            s_vem += -1/i;
        else
            s_vem += 1/i;
    }
    printf("%f %f", s_vai, s_vem);
    return 0;
}
