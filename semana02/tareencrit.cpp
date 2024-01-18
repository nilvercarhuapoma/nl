#include<iostream>
#include<string>
using namespace std;
int main (){
    
    string palabra;
  
    int clave,suma =0,totl;
    
    cout<<"ingrese una letra:";
    getline(cin,palabra);
    cout<<"ingrese una clave (un numero entero):";
    cin>>clave;     
    cout<<"ingrese su nombre:";
    cin>>palabra;
    for(char caracter: palabra){
        suma+=caracter;
        cout<<"....................";
        totl=clave + suma;

           }
    cout<<"\n el numero que se registra es:"<<totl;
        return 0;

}