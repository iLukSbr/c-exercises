//Lucas Yukio Fukuda Matsumoto - 2516977
#include <stdio.h>

void segundosParaHMS(int total_segundos, int *h, int *m, int *s);

int main(){
    int total_segundos, h, m, s;
    printf("Total de segundos = ");
    scanf("%d", &total_segundos);
    segundosParaHMS(total_segundos, &h, &m, &s);
    printf("%d:%d:%d", h, m, s);
    return 0;
}

void segundosParaHMS(int total_segundos, int *h, int *m, int *s){
    *h = total_segundos/3600;
    total_segundos %= 3600;
    *m = total_segundos/60;
    *s = total_segundos%60;
}
