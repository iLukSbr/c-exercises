#include <iostream>
#include <math.h>
#include <locale>
#define PI 3.1415
using namespace std;
int main(){
    setlocale(LC_ALL,"Portuguese");
    float R;
    cout<<"Raio da esfera: "; cin>>R;
    cout<<"Volume da esfera: "<<4*PI*pow(R,3)/3<<endl;
    return 0;
}
