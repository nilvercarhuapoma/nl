#include<iostream>
#include<string>
using namespace std;
class Peces{
private:
string nombre;
string respiracion;
string escamosidad;
public:
Peces(string _nombre,string _respiracion,string _escamosidad):nombre(_nombre),respiracion(_respiracion),escamosidad(_escamosidad){};
void mostrar(){
cout<<"NOMBRE:"<<nombre<<endl;
cout<<"RESPIRACION:"<<respiracion<<endl;
cout<<"ESCAMOSIDAD:"<<escamosidad<<endl;
}
};
class Agua_dulce:public Peces{
    private:
    string habitad;
public:
Agua_dulce(string nombre,string respiracion,string escamosidad,string habitad):Peces(nombre,respiracion,escamosidad),habitad(habitad){};
void mostrar(){
Peces::mostrar();
cout<<"HABITAD:"<<habitad<<endl;
}
void Comer( ){
    string comida="Peces,Crustaceos y otros organismos";
cout<<"Come escensialmente "<<comida<<endl;
}
void adaptarse(){
string adaptarse="un sistema respiratorio ";
cout<<"Se adapta a "<<adaptarse<<endl;
}
};
int main (){
Agua_dulce a1("Paiche","Dual","Escamoso","Rios y Lagos");
a1.mostrar();
cout<<"COMER:"<<endl;
a1.Comer();
cout<<"ADAPTARSE:"<<endl;
a1.adaptarse();
}