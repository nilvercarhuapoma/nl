#include<iostream>
#include<string>
using namespace std;

class Pet {
private:
    string nombre;
    string raza;
public:
    Pet(string n, string r) : nombre(n), raza(r) {}
    void mostrar() {
        cout << "Name: " << nombre << endl;
        cout << "Raza: " << raza << endl;
    }
};

class Dog : public Pet {
private:
    string dueño;
public:
    Dog(string nombre, string raza, string d) : Pet(nombre, raza), dueño(d) {}
    void mostrar1() {
        Pet::mostrar();
        cout << "Duenio: " << dueño << endl;
    }
};

class Fiis : public Dog {
private:
    string mascoat_fiis;
public:
    Fiis(string nombre, string raza, string dueño, string m) : Dog(nombre, raza, dueño), mascoat_fiis(m) {}
    void mostrar2() {
        Dog::mostrar1();
        cout << "Mascota de fiis: " << mascoat_fiis << endl;
    }
};

int main() {
    Fiis f("pepe", "pitbul", "juan", "mono");
    f.mostrar2();
    return 0;
}
