#include <iostream>
#include <math.h>
#include <locale>
using namespace std;
int main(){
    setlocale(LC_ALL,"Portuguese");
    float A, D;
    cout<<"�ngulo que a escada est� do ch�o (graus): "; cin>>A;
    cout<<"Dist�ncia da escada � parede: "; cin>>D;
    if(A<0||A>90){
        return 1;
    }
    else{
       cout<<"Altura que a escada toca a parede: "<<tan(A)*D;
       return 0;
    }
}
