#include<iostream>
using namespace std;
int main (){
    int porcentaje,numero,n;
    cout<<"ingrese su numero:";
    cin>>numero;
    cout<<"ingrese el porcentaje:";
    cin>>n;
    porcentaje =(numero*n)/100;
    cout<<"el\t"<<n<<" porciento de\t"<<numero<<"\tes :"<<porcentaje;
    return 0;
}