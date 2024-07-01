#include <iostream>
#include <locale>
using namespace std;
int troca(int N1,int N2){
    if(N2==N1/1000+(N1%1000-N1%100)/10+(N1%100-N1%10)*10+(N1%10)*1000) return 1;
    else return 0;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int N1,N2;
    cout<<"N1 = "; cin>>N1;
    cout<<"N2 = "; cin>>N2;
    if(N1<1000||N2<1000||N1>9999||N2>9999) return 1;
    if(!troca(N1,N2)) cout<<"FALSE"<<endl;
    else cout<<"TRUE"<<endl;
    return 0;
}
