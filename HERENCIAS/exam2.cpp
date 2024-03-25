#include <iostream>
#include <vector>
using namespace std;

class Vehiculo
{
private:
    string marca;
    int persona;

public:
    Vehiculo(string m, int p) : marca(m), persona(p) {}

    void mostrar()
    {
        cout << "Marca: " << marca << endl;
        cout << "Pasajeros: " << persona << endl;
    }
};

class Automovil : public Vehiculo
{
private:
    int llantas;

public:
    Automovil(string marca, int persona, int ll) : Vehiculo(marca, persona), llantas(ll) {}

    void mostrar()
    {
        Vehiculo::mostrar();
        cout << "Llantas: " << llantas << endl;
    }
};

class Motocicleta : public Automovil
{
private:
    int costo;

public:
    Motocicleta(string marca, int persona, int llantas, int c) : Automovil(marca, persona, llantas), costo(c) {}

    void mostrar()
    {
        Automovil::mostrar();
        cout << "Costo: " << costo << endl;
    }

    int get_costo()
    {
        return costo;
    }

    void set_costo(int c)
    {
        costo = c;
    }
};

void modificar(Motocicleta m)
{
    m.set_costo(9000);
}

void modificar_referencia(Motocicleta &m)
{
    m.set_costo(12000);
}

int main()
{   cout<<"    AUTOMOVIL"<<endl;
    Automovil a1("Ferrari", 4, 4);
    a1.mostrar();
    cout << endl;
    cout<<"    MOTOCICLETA"<<endl;
    Motocicleta m1("Kawasaki", 2, 2, 8000);
    cout<<"    utilizando el set:"<<endl;
    m1.set_costo(9000);
    m1.mostrar();
    cout << endl;
    cout<<"    Paso por valor:"<<endl;
    modificar(m1);
    m1.mostrar();
    cout << endl;
    cout<<"    Paso por referencia:"<<endl;
    modificar_referencia(m1);
    m1.mostrar();

    return 0;
}
