#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void perimetro(int &n1,int &n2,int &n3,int &p2){
n1*=2;
n2-=1;
n3+=3;
p2=n1+n2+n3;

}
void llenar(int &a,int &b,int &c){
cout<<"ingrese su lado 1:";
cin>>a;
cout<<"ingrese su lado 2:";
cin>>b;
cout<<"ingrese su lado 3:";
cin>>c;

}
void mostrar(int p1,int p2){
    
    
  cout<<"el perimetro original es:"<<p1<<endl;
    cout<<"el nuevo perimetro es:"<<p2<<endl;
}

int main(){
int n1,n2,n3,p2;
llenar(n1,n2,n3);
int p1=n1+n2+n3;
perimetro(n1,n2,n3,p2);
mostrar(p1,p2);

}