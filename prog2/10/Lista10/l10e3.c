#include <stdio.h>

int proxFibonacci (int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", proxFibonacci(n));
    return 0;
}

int proxFibonacci (int n)
{
    int ant = 0, atual = 1, prox;
    while(prox <= n)
    {
        prox = atual + ant;
        ant = atual;
        atual = prox;
    }
    return prox;
}
