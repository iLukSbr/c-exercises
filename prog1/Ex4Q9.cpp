#include <iostream>
#include <locale>
using namespace std;
float pesoideal(float A,int S){
    float P;
    if(!S) P=(72.7*A)-58;
    else P=(62.1*A)-44.7;
    return P;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int S;
    float A;
    cout<<"Altura (metros): "; cin>>A;
    cout<<"Sexo (0 masculino e 1 feminino): "; cin>>S;
    if(A<=0||S<0||S>0) return 1;
    cout<<"Peso ideal = "<<pesoideal(A,S)<<endl;
    return 0;
}
