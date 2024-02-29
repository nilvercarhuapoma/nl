#include<iostream>
using namespace std;
class Vehiculo {
private:
string marca;
int año;
public:
Vehiculo(string m,int a):marca(m),año(a){};
void mostrar();
};
void Vehiculo::mostrar(){
cout<<"SU MARACA:"<<marca<<endl;;
cout<<"DEL ANIO:"<<año<<endl;
}
class Automovil :public Vehiculo{
private:
int llantas;
public:
Automovil(string marca,int año,int ll):Vehiculo(marca,año),llantas(ll){};
void capacidad_person();
void structr(){
cout<<"Con "<<llantas<<" llantas"<<endl;
}


};
void Automovil::capacidad_person(  ){
int person;
cout<<"LLEVA SOLO 4 personas"<<endl;

}
int main(){
 
Automovil a1("ferrari",2006,4);
a1.mostrar();
a1.structr();
a1.capacidad_person();


}