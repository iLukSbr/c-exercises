#include <stdio.h>

#define A1 0.075
#define A2 0.15
#define A3 0.225
#define A4 0.275
#define L1 1200.25
#define L2 2300.5
#define L3 3500.75
#define L4 4000

int main()
{
    float rend, imp;
    scanf("%f", &rend);
    if(rend <= L1)
        imp = 0;
    else if(rend > L1 && rend <= L2)
        imp = A1*(rend-L1);
    else if(rend > L2 && rend <= L3)
        imp = A2*(rend-L2) + A1*(L2-L1);
    else if(rend > L3 && rend <= L4)
        imp = A3*(rend-L3) + A2*(L3-L2) + A1*(L2-L1);
    else
        imp = A4*(rend-L4) + A3*(L4-L3) + A2*(L3-L2) + A1*(L2-L1);
    printf("%.2f", imp);
    return 0;
}
