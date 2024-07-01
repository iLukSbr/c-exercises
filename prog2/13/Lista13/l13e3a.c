#include <stdio.h>

int ehParDeFoolano (unsigned int n1, unsigned int n2);

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("\n%d\n", ehParDeFoolano(n1, n2));
    return 0;
}

int ehParDeFoolano (unsigned int n1, unsigned int n2)
{
    int car_n1[10]={0}, car_n2[10]={0}, i;
    while(n1>0 && n2>0)
    {
        car_n1[n1%10]++;
        n1 /= 10;
        car_n2[n2%10]++;
        n2 /= 10;
    }
    if(n1 || n2)
        return 0;
    for(i=0; i<10; i++)
        if(car_n1[i] != car_n2[i])
            return 0;
    return 1;
}
