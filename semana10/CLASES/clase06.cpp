#include<iostream>
#include<fstream>
using namespace std;
class Animal{
private:
string nombre;
int patas;
string aliment;
string pelaje;
public:
Animal(string _nombre,int _patas,string _aliment,string _pelaje ):nombre(_nombre),patas(_patas),aliment(_aliment),pelaje(_pelaje){};
void mostrar(){
cout<<"NOMBRE:"<<nombre<<endl;
cout<<"PATAS:"<<patas<<endl;
cout<<"ALIMENTACION:"<<aliment<<endl;
cout<<"PELAJE:"<<pelaje<<endl;
}
};
class Leopardo:public Animal{
public:
Leopardo(string nombre,int patas,string aliment,string pelaje ):Animal(nombre,patas,aliment,pelaje){};
void mostrar1(int velocidad){
cout<<"VELOCIDAD:"<<velocidad<<"Km/h"<<endl;
}
};
int main(){
Leopardo l1("leopent",4,"carnivoro","pelo bajo");
l1.mostrar();
l1.mostrar1(128);
return 0;
}