#include <iostream>
#include <locale>
using namespace std;
int maior(int a,int b,int c){
    if(a>b&&a>b) return a;
    if(b>a&&b>c) return b;
    if(c>a&&c>b) return c;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int N1,N2,N3;
    cout<<"Entre com 3 notas: ";
    cin>>N1>>N2>>N3;
    if(maior(N1,N2,N3)>=70&&maior(N1,N2,N3)<80) cout<<"Bolsa = R$ 500,00"<<endl;
    else if(maior(N1,N2,N3)>=80&&maior(N1,N2,N3)<90) cout<<"Bolsa = R$ 600,00"<<endl;
    else if(maior(N1,N2,N3)>=90) cout<<"Bolsa = R$ 700,00"<<endl;
    else if(maior(N1,N2,N3)<70) cout<<"Bolsa = R$ 0,00"<<endl;
    else return 1;
    return 0;
}
