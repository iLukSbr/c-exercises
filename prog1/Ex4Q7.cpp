#include <iostream>
#include <locale>
using namespace std;
int maior(int a,int b,int c,int &M){
    if(a>M) M=a;
    if(b>M) M=b;
    if(c>M) M=c;
    return 0;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int N1,N2,N3,N4,N5,N6,N7,N8,N9,M;
    cout<<"Entre com os 9 valores: ";
    cin>>N1>>N2>>N3>>N4>>N5>>N6>>N7>>N8>>N9;
    M=N1;
    maior(N1,N2,N3,M);
    maior(N4,N5,N6,M);
    maior(N7,N8,N9,M);
    cout<<"Maior valor = "<<M<<endl;
    return 0;
}
