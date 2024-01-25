#include<iostream>
#include<cmath>
using namespace std;
float area(int b,int h){
return (b*h)/2.0;

}
int perimetro(int a,int c,int b){

    return a+c+b;
}
void llenar( int &a,int &c,int &b,int &h){
   
cout<<"ingrese el lado 1:";
cin>>a;
cout<<"ingrese el lado 2:";
cin>>c;
cout<<"ingrese la base :";
cin>>b;
cout<<"ingrese la altura:";
cin>>h;

}
void mostar(float A,int P){

cout<<"el area del triangulo es:"<<A<<endl;
cout<<"el perimetro del triangulo es:"<<P<<endl;

}
int main(){

    int a,c,b,h;
    llenar(a,c,b,h);
    float A=area(b,h);
    int P=perimetro(a,c,b);
    mostar(A,P);
    return 0;
}