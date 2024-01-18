#include <iostream>
using namespace std;
int main(){
    double n=0;
    double numero;
    int suma=0;
    int contador=0;
    while (contador<7)
    {
        cout<<"ingrese los numeros:"<<contador +1<<":";
        cin>>numero;
        suma+=numero;
        contador++;
    }
    cout<<"la suma de los numeros:"<<suma;
    
}