#include<iostream>
#include<vector>
using namespace std;

class Dispositivo {
    string name;
    int cantidad;
public:
    Dispositivo(string n, int cant): name(n), cantidad(cant) {}
    void mostrar() {
        cout << "Name: " << name << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
    friend class Sistema; // Permitir que la clase Sistema acceda a los miembros privados de Dispositivo
};

class Sistema {
    Dispositivo &dispositivo;
public:
    Sistema(Dispositivo &dispositivo): dispositivo(dispositivo) {}
    void display() {
        cout << "Agregar " << dispositivo.cantidad << " " << dispositivo.name << endl;
    }
};

int main() {
    Dispositivo d("scaner", 4);
    d.mostrar();

    Sistema s(d);
    s.display();

    return 0;
}
