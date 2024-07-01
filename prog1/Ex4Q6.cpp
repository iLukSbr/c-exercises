#include <iostream>
#include <locale>
using namespace std;
int convbindec(int BIN1,int BIN2,int &DEC1,int &DEC2){
    int POT1=1,POT2=1;
    while(BIN1>0){
        DEC1=DEC1+(BIN1%10)*POT1;
        BIN1=BIN1/10;
        POT1=POT1*2;
    }
    while(BIN2>0){
        DEC2=DEC2+(BIN2%10)*POT2;
        BIN2=BIN2/10;
        POT2=POT2*2;
    }
    return 0;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int BIN1,BIN2,DEC1=0,DEC2=0;
    cout<<"Valor binário 1: "; cin>>BIN1;
    cout<<"Valor binário 2: "; cin>>BIN2;
    convbindec(BIN1,BIN2,DEC1,DEC2);
    cout<<"Valor decimal 1: "<<DEC1<<endl;
    cout<<"Valor decimal 2: "<<DEC2<<endl;
    return 0;
}
