#include <iostream>
#include <vector>
using namespace std;
class vehiculo
{
private:
    string marca;
    int año;

public:
    vehiculo(string m, int a) : marca(m), año(a) {}
    void mostrar()
    {
        cout << "MARCA:" << marca << endl;
        cout << "ANIO:" << año << endl;
    }
    int get_año()
    {
        return año;
    }
    void set_año(int a)
    {
        año = a;
    }
};
class Motocicleta : public vehiculo
{
private:
    string origen;

public:
    Motocicleta(string marca, int año, string o) : vehiculo(marca, año), origen(o) {}
    void mostrar()
    {
        vehiculo::mostrar();
        cout << "ORIGEN" << origen << endl;
    }
};
class Automovil : public vehiculo
{
private:
    int pasajeros;

public:
    Automovil(string marca, int año, int p) : vehiculo(marca, año), pasajeros(p) {}
    void mostrar()
    {
        vehiculo::mostrar();
        cout << "PASAJEROS:" << pasajeros << endl;
    }

    int set_paj(int p)
    {
        return pasajeros = p;
    }
};
void modificar_pasajeros(Automovil pasajeros)
{
    pasajeros.set_paj(3);
}
void modificar_psjreferenci(Automovil &pasajeros)
{
    pasajeros.set_paj(5);
}
int main()
{
    Motocicleta m1("Kawasaqui", 2020, "japon");
    m1.set_año(2023);
    m1.mostrar();
    cout << endl;
    Automovil a1("Ferrari", 2021, 3);
    modificar_pasajeros(a1);
    modificar_psjreferenci(a1);
    a1.mostrar();
}