#include <iostream>
#include <locale>
using namespace std;
int main(){
    setlocale(LC_ALL,"Portuguese");
    int D;
    float X,H,F;
    cout<<"Altura do degrau (cm): "; cin>>X;
    cout<<"Quantos metros quer subir? "; cin>>H;
    if(H>0){
       D=H*100/X;
       F=H*100/X;
       if(F>D)D=D+1;
       cout<<"Você precisa subir "<<D<<" degraus.";
       return 0;
    }
    else return 1;
}
