#include <iostream>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
void perimetro(int &n1,int &n2,int &n3,int &p2){
n1*=2;
n2+=n1;
n3+=n2;
p2=n1+n2+n3;
}
void llenar(int &a,int &b,int &c){
cout<<"ingrese el lado 1:"<<endl;
cin>>a;
cout<<"ingrese el lado 2:"<<endl;
cin>>b;
cout<<"ingrese el lado 3:"<<endl;
cin>>c;

}
void mostrar(int p1, int p2){
cout<<"el perimetro original es:"<<p1<<endl;
cout<<"el perimetro modificado es:"<<p2<<endl;



}

int main(){
int n1,n2,n3,p2;
llenar(n1,n2,n3);
int p1=n1+n2+n3;
perimetro(n1,n2,n3,p2);
mostrar(p1,p2);


}