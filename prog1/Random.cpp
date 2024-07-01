#include <iostream>
#include <stdlib.h>
using namespace std;
int PRIMO_ALEATORIO(){
    int i=2, n=rand()%100+1;
    while((n%i)!=0) i=i+1;
    if(i!=n) return 0;
    return 1;
}
int main(){
    cout<<PRIMO_ALEATORIO();
    return 0;
}
