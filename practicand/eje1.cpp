#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int respt,palabra,A; 
    char caracter='a';
    cout<<"ingrese una palabra:\n";
    cin>>palabra,20;
   
    cout<<"ingrese un numero:\n";
    cin>>A,1;
   
    cout<<"ingrese un caracter\n:";
    char caracter;
    cin>>caracter;
    respt=A + caracter + palabra;
    cout<<"el resultado es:\n"<<respt<<endl;
    return 0;
}