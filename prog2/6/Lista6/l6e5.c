#include <stdio.h>

int main()
{
    int h, m, s, h1, m1, s1, h2, m2, s2;
    printf("hh:mm:ss\n");
    printf("Hora 1 = ");
    scanf("%d:%d:%d", &h1, &m1, &s1);
    printf("Hora 2 = ");
    scanf("%d:%d:%d", &h2, &m2, &s2);
    s = s1 + s2;
    m = m1 + m2;
    h = h1 + h2;
    if(s > 59){
        m += s/60;
        s = s%60;
    }
    if(m > 59){
        h += m/60;
        m = m%60;
    }
    printf("Soma = %02d:%02d:%02d", h, m, s);
    return 0;
}
