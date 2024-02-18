#include<iostream>
#include<string>
using namespace std;
class Soldado{
private:
string nombre;
int salud;
public:
Soldado(string _nombre,int _salud):nombre(_nombre),salud(_salud){};
void mostrar(){
    cout<<"Nombre:"<<nombre<<endl;
    cout<<"El nivel de salud es:"<<salud<<endl;
}
void disparo(){
if(salud>5){
cout<<"tiin me disparan,";
salud-=25;
cout<<"salud es:"<<salud<<endl;
}else{
  cout<<"ELIMINADO!";  
}

}
};
int main(){
Soldado s1("pontef",100);
s1.mostrar();
s1.disparo();
s1.disparo();
s1.disparo();
s1.disparo();
s1.disparo();
s1.disparo();
}
