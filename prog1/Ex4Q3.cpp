#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
int main(){
    setlocale(LC_ALL,"Portuguese");
    double x;
    cout<<"Entre com o valor de x: "; cin>>x;
    cout<<"1. "<<pow(x,2)<<endl;
    cout<<"2. "<<cbrt(x)<<endl;
    cout<<"3. "<<sqrt(x)<<endl;
    cout<<"4. "<<pow(x,3)<<endl;
    return 0;
}
