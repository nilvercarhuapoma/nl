#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Persona{
private:
string nombre;
string lugar;
string ocupation;
int edad;
public:
Persona(string _nombre,string _lugar,string _ocupation,int _edad):nombre(_nombre),lugar(_lugar),ocupation(_ocupation),edad(_edad){};
void present( ){
cout<<"nombre del trabajador:"<<nombre<<endl;
cout<<"lugar de:"<<lugar<<endl;
cout<<"Ocupacion:"<<ocupation<<endl;
cout<<"Con edad:"<<edad<<" anios"<<endl;
}
public:
string lugar_trabajo;
int horas_trabajo;
string que_trabaja;
Persona(string _lugar_trabajo,int _horas_trabajo,string _que_trabaja):lugar_trabajo(_lugar_trabajo),horas_trabajo(_horas_trabajo),que_trabaja(_que_trabaja){};
void trabajo(){
cout<<"lugar de trabajo :"<<lugar_trabajo<<endl;
cout<<"Sus horas de trabajo :"<<horas_trabajo<<" horas"<<endl;
cout<<"Trabaja de :"<<que_trabaja<<endl;

}


};
int main(){
Persona p1("Samuel","pucallpa","ing.sistemas",28);
p1.present();
Persona p2("empresa texIA",6,"programador");
p2.trabajo();
}