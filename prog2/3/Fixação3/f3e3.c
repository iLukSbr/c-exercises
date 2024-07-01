#include <stdio.h>
#include <math.h>

int main ()
{
    int v;
    scanf("%d", &v);
    if(v < 0)
        v = -1*v;
    printf("%d", v);
    return 0;
}
