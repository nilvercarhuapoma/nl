#include<iostream>
using namespace std;
int main (){
    float m,d,s,r,x,y;
    cout<<"ingrese los numeros:";
    cin>>x;
    cout<<"ingrese el otro numero:";
    cin>>y;
    m=x*y;
    d=x/y;
    s=x+y;
    r=x-y;
    cout<<"las respuestas de la operaciones es :"<<endl;
    cout<<"la suma es:"<<s<<endl;
    cout<<"la division es:"<<d<<endl;
    cout<<"la multiplicacion es :"<<m<<endl;
    cout<<"la resta es :"<<r<<endl;
    return 0;
    
}