#include <iostream>
#include <string>
using namespace std;
class Vehiculo
{
private:
    string marca;
    string modelo;
    int año;

public:
    Vehiculo(string ma, string mo, int an) : marca(ma), modelo(mo), año(an) {}
    void mostrar();
};
void Vehiculo::mostrar()
{
    cout << "MARCA:" << marca << endl;
    cout << "MODELO:" << modelo << endl;
    cout << "DEL AÑO:" << año << endl;
}
class Automovil : public Vehiculo
{
private:
    int n_puertas;

public:
    Automovil(string marca, string modelo, int año, int n) : Vehiculo(marca, modelo, año), n_puertas(n) {}
    void puertas()
    {
        Vehiculo::mostrar();
        cout << "puetas:" << n_puertas << endl;
    }
};
class Motocicleta : public Vehiculo
{
private:
    string tipo;
    public:
        Motocicleta(string marca, string modelo, int año, string t) : Vehiculo(marca, modelo, año),tipo(t) {}
    void creacion();
};
void Motocicleta::creacion(){
Vehiculo::mostrar();
cout<<"tipo:"<<tipo<<endl;
}

int main(){
Automovil a1("Ferrari","dtxa",2009,4);
a1.puertas();
cout<<"......................"<<endl;
Motocicleta m1("kawasaki","rx43",2012,"Deportiva");
m1.creacion();
}
