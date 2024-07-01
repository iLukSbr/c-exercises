#include <iostream>
#include <locale>
using namespace std;
int main(){
  setlocale(LC_ALL,"Portuguese");
  int L=0, C=0;
  float M1X3[3], M3X3[3][3];
  cout<<"Matriz (i, j)"<<endl<<endl<<"Máscara 1X3:"<<endl;
  while(C<3){
    cout<<"Entre M1X3 (1, "<<C+1<<"): "; cin>>M1X3[C];
    C=C+1;
  }
  cout<<endl<<"Matriz 3X3:"<<endl;
  while(L<3){
    C=0;
    while(C<3){
        cout<<"Entre M3X3 ("<<L+1<<", "<<C+1<<"): "; cin>>M3X3[L][C];
        C=C+1;
    }

    L=L+1;
  }
  cout<<endl<<"Matriz mascarada 3X3:"<<endl;
  L=0;
  while(L<3){
    C=0;
    while(C<3){
        cout<<M3X3[L][C]<<" ";
        C=C+1;
    }
    cout<<endl;
    L=L+1;
  }
  return 0;
}
