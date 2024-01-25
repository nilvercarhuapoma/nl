#include<iostream>
#include<cmath>
using namespace std;
float area(int l){
return pow(l,2);
}
double diagonal( int l){
return sqrt(2.0)*l;
}
float perimetro(int l){
return l*4;

}
int llenar( )
{
int r;
cout<<"ingrese el lado:";
cin>>r;
return r;

}
void mostrar(float a,double d,float p){
    cout<<"el area es:"<<a<<endl;
    cout<<"la diagonal es:"<<d<<endl;
    cout<<"el perimetro es:"<<p<<endl;

}
int main(){
int l,a,d,p;
l=llenar();
float a_resultado=area(l);
double d_resultado=diagonal(l);
float p_resultado=perimetro(l);
mostrar(a_resultado,d_resultado,p_resultado);
return 0;
}