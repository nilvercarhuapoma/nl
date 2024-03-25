#include <iostream>
#include <vector>
using namespace std;

class Persona {
protected:
    string identf;
    string apelld;
    string name;
    string direct;
    string contact[3];

public:
    Persona() {}
    Persona(string idt, string ap, string na, string dict, string cont) : identf(idt), apelld(ap), name(na), direct(dict) {
        for (int i = 0; i < 3; ++i) {
            contact[i] = cont;
        }
    }

    void add_data() {
        cout << "Ingrese el identificador: ";
        getline(cin, identf);
        cout << "Ingrese el nombre: ";
        getline(cin, name);
        cout << "Ingrese el apellido: ";
        getline(cin, apelld);
        cout << "Ingrese la direccion: ";
        getline(cin, direct);
        cout << "Que tipo de contacto obtiene:" << endl;
        cout << "[1]. ID" << endl;
        cout << "[2]. Correo" << endl;
        cout << "[3]. Telefono" << endl;
        cout << "Ingrese la opcion: ";
        int m;
        cin >> m;
        cin.ignore();
        switch (m) {
        case 1:
            cout << "Ingrese el ID: ";
            getline(cin, contact[0]);
            break;
        case 2:
            cout << "Ingrese el correo: ";
            getline(cin, contact[1]);
            break;
        case 3:
            cout << "Ingrese el telefono: ";
            getline(cin, contact[2]);
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
        }
        
    }

    void show_data() const {
        cout << "Identificador: " << identf << endl;
        cout << "Nombre: " << name << " " << apelld << endl;
        cout << "Direccion: " << direct << endl;
        cout << "Contacto:" << endl;
        if (!contact[0].empty()) cout << "  ID: " << contact[0] << endl;
        if (!contact[1].empty()) cout << "  Correo: " << contact[1] << endl;
        if (!contact[2].empty()) cout << "  Telefono: " << contact[2] << endl;
    }
};

class Empleado : public Persona {
protected:
    int codigo;
    double costo_hh;
    string departamento[2];

public:
    Empleado() {}
    Empleado(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept) : Persona(idt, ap, na, dict, cont), codigo(c), costo_hh(cst) {
        departamento[0] = dept;
    }

    virtual double salario_total() const = 0;

    virtual void add_data() {
        Persona::add_data();
        cout << "Ingrese el codigo: ";
        cin >> codigo;
        cout << "Ingrese el costo por hora: ";
        cin >> costo_hh;
        cout << "Ingrese el codigo del departamento: ";
        cin >> departamento[0];
        cout << "Ingrese el nombre del departamento: ";
        cin.ignore();
        getline(cin, departamento[1]);
        
    }

    virtual void show_data() const {
        Persona::show_data();
        cout << "Codigo: " << codigo << endl;
        cout << "Codigo del departamento: " << departamento[0] << endl;
        cout << "Nombre del departamento: " << departamento[1] << endl;
    }
};

class Gerente : public Empleado {
private:
    double bono;

public:
    Gerente() {}
    Gerente(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double bn) : Empleado(idt, ap, na, dict, cont, c, cst, dept), bono(bn) {}

    double salario_total() const override {
        return costo_hh + bono;
    }

    void add_data() override {
        Empleado::add_data();
        cout << "Ingrese el bono: ";
        cin >> bono;
        cout << endl;
    }

    void show_data() const override {
        cout << "Datos del Gerente:" << endl;
        Empleado::show_data();
        cout << "Salario Total: " << salario_total() << endl;
    }
};

class Ingeniero : public Empleado {
private:
    double horax_ext;

public:
    Ingeniero() {}
    Ingeniero(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double hx) : Empleado(idt, ap, na, dict, cont, c, cst, dept), horax_ext(hx) {}

    double salario_total() const override {
        return costo_hh + horax_ext;
    }

    void add_data() override {
        cin.ignore();
        Empleado::add_data();
        cout << "Ingrese el pago por horas extras: ";
        cin >> horax_ext;
        cout << endl;
    }

    void show_data() const override {
        cout << "Datos del Ingeniero:" << endl;
        Empleado::show_data();
        cout << "Pago de horas extras: " << horax_ext << endl;
        cout << "Salario Total: " << salario_total() << endl;
    }
};

int main() {
    vector<Gerente> gerentes;
    vector<Ingeniero> ingenieros;

    cout << "Ingrese los datos del Gerente:" << endl;
    Gerente g;
    g.add_data();
    gerentes.push_back(g);

    cout << "Ingrese los datos del Ingeniero:" << endl;
    Ingeniero i;
    i.add_data();
    ingenieros.push_back(i);

    cout << "    GERENTE:" << endl;
    gerentes[0].show_data();
    cout << endl;

    cout << "    INGENIERO:" << endl;
    ingenieros[0].show_data();

    return 0;
}
