#include<iostream>
#include<string>
using namespace std;
int main(){
    string nombre, apellido;
    cout<<"ingrese sus nombres y apellidos:";
    cin>>nombre;
    getline(cin,apellido);
    cout<<"el nombre del usuario es:"<<nombre<<" "<<apellido<<endl;
    return 0;

}