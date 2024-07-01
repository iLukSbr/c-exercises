#include <iostream>
#include <locale>
using namespace std;
int ehPrimo(int N){
    int X, RESTO;
    if(N!=2&&N%2!=0){
        X=2;
        RESTO=N%X;
        while(X<N&&RESTO!=0){
            X=X+1;
            RESTO=N%X;
        }
    }
    if(X==N||N==2) return 1;
    else return 0;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int N=1,c=0;
    while(N<=1000){
        if(ehPrimo(N)==1){
            cout<<N<<" ";
            c=c+1;
        }
        if(c%10==0) cout<<endl;
        N=N+1;
        }
    return 0;
}
