#include <iostream>
#include <vector>
using namespace std;

class Persona {
private:
    string identificador;
    string apellidos;
    string nombres;
    string direccion;
    string tipo_contacto[3];

public:
    Persona() {}
    Persona(string id, string ap, string nom, string dir, string contacto1, string contacto2, string contacto3)
        : identificador(id), apellidos(ap), nombres(nom), direccion(dir) {
        tipo_contacto[0] = contacto1;
        tipo_contacto[1] = contacto2;
        tipo_contacto[2] = contacto3;
    }
    virtual void salariot()=0;
    void mostrar() {
        cout << "Identificador: " << identificador << endl;
        cout << "Apellidos: " << apellidos << endl;
        cout << "Nombres: " << nombres << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Contacto 1: " << tipo_contacto[0] << endl;
        cout << "Contacto 2: " << tipo_contacto[1] << endl;
        cout << "Contacto 3: " << tipo_contacto[2] << endl;
    }
};

class Empleado : public Persona {
private:
    int codigo;
    double costo_hh;
    string departamento[2];
    double salario;

public:
    Empleado() {}
    Empleado(string id, string ap, string nom, string dir, string contacto1, string contacto2, string contacto3,
             int cod, double costo, string dep1, string dep2, double sal)
        : Persona(id, ap, nom, dir, contacto1, contacto2, contacto3), codigo(cod), costo_hh(costo), salario(sal) {
        departamento[0] = dep1;
        departamento[1] = dep2;
    }
     void salariot()override{
        cout<<10000;
     }
    void mostrar() {
        Persona::mostrar();
        cout << "Codigo: " << codigo << endl;
        cout << "Costo por hora: " << costo_hh << endl;
        cout << "codigo dep 1: " << departamento[0] << endl;
        cout << "Nombre dep 2: " << departamento[1] << endl;
        cout << "Salario: ";
        
    }
};

class Gerente : public Empleado {
private:
    double bono;

public:
    Gerente() {}
    Gerente(string id, string ap, string nom, string dir, string contacto1, string contacto2, string contacto3,
            int cod, double costo, string dep1, string dep2, double sal, double bn)
        : Empleado(id, ap, nom, dir, contacto1, contacto2, contacto3, cod, costo, dep1, dep2, sal), bono(bn) {}

    void mostrar() {
        Empleado::mostrar();
        cout << "Bono: " << bono << endl;
    }
    void salariot()override{
        cout<<20000;
    }
};

class Ingeniero : public Empleado {
private:
    float horas_extras;

public:
    Ingeniero() {}
    Ingeniero(string id, string ap, string nom, string dir, string contacto1, string contacto2, string contacto3,
              int cod, double costo, string dep1, string dep2, double sal, float horas)
        : Empleado(id, ap, nom, dir, contacto1, contacto2, contacto3, cod, costo, dep1, dep2, sal), horas_extras(horas) {}

    void mostrar() {
        Empleado::mostrar();
        cout << "Horas extras: " << horas_extras << endl;
    }
    void salariot(){
        cout<<"Salario:"<<30000;
    }
};

int main() {
    // Crear un objeto de Ingeniero
    cout<<endl;
    Ingeniero ingeniero("123", "Perez", "Juan", "Calle A", "123456", "789012", "345678", 001, 15.5,"001", "huanuco ", 2000, 10.5);
    ingeniero.mostrar();
    ingeniero.salariot();
    cout<<endl;
    // Crear un objeto de Gerente
    Gerente gerente("456", "Gomez", "Maria", "Calle B", "987654", "321098", "567890", 002, 20.5, " 004", " pucalpa", 3000, 100);
    gerente.mostrar();
    gerente.salariot();

    return 0;
}
