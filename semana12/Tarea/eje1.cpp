#include <iostream>
#include <vector>
using namespace std;

class Vehiculo
{
private:
    string marca;
    int año;

public:
    Vehiculo(string m, int a) : marca(m), año(a) {}

    virtual void origen() = 0;

    void mostrar()
    {
        cout << "marca:" << marca << endl;
        cout << "Anio:" << año << endl;
        cout << "Origen:";
        origen();
    }

    int get_año(int año)
    {
        return año;
    }

    void set_a(int a)
    {
        año = a;
    }
};

class Automovil : public Vehiculo
{
private:
    int ventanas;
    int pasajeros;

public:
    Automovil(string marca, int año, int v, int p) : Vehiculo(marca, año), ventanas(v), pasajeros(p) {}

    void mostrar()
    {
        Vehiculo::mostrar();
        cout << "Ventanas:" << ventanas << endl;
        cout << "Pasajeros:" << pasajeros << endl;
    }

    void origen() override
    {
        cout << "Italia" << endl;
    }

    void viajar()
    {
        cout << "Este Automovil esta ocupado" << endl;
    }
};

void actualizar_año(Automovil &año)
{
    año.set_a(2014);
}

class Motocicleta : public Vehiculo
{
private:
    double costo;

public:
    Motocicleta(string marca, int año, double com) : Vehiculo(marca, año), costo(com) {}

    void mostrar()
    {
        Vehiculo::mostrar();
        cout << "Costo:" << costo << endl;
    }

    void origen() override
    {
        cout << "Japon" << endl;
    }

    void competir()
    {
        cout << "Esta Motocicleta esta en competencia" << endl;
    }
};

void modificar_año(Motocicleta &año)
{
    año.set_a(2013);
}

int main()
{
    Automovil a1("Ferrari", 2011, 4, 5);
    a1.set_a(2012);
    a1.mostrar();
    cout << endl;
    system("cls");
    cout << "Actualizar anio de automovil:" << endl;
    actualizar_año(a1);
    a1.mostrar();
    a1.viajar();
    cout << endl;
    cout << "Actualizar anio de Motocicleta:" << endl;
    Motocicleta m1("Kawasaki", 2010, 20000);
    modificar_año(m1);
    m1.mostrar();
    m1.competir();

    return 0;
}
