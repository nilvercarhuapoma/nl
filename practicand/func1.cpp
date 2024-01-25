#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int area(int b,int l){
return b*l;

}
int perimetro(int b,int l){

return b+b+l+l;

}
void llenar(int &b,int &l){
cout<<"ingrese su base:";
cin>>b;
cout<<"ingrese el lado:";
cin>>l;

}
void mostrar(int a,int p){
cout<<"el area es:"<<a<<endl;
cout<<"el permetro es:"<<p<<endl;

}

int main (){
int b,l;
llenar(b,l);
int a=area(b,l);
int p=perimetro(b,l);
mostrar(a,p);
    return 0;
}