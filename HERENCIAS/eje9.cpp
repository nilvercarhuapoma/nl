#include <iostream>
#include <vector>
using namespace std;

class Persona {
private:
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

    void add_date(vector<Persona> &date, int &n) {
        cout << " Total de personas: " << n << endl;
       
        for (int i = 0; i < n; ++i) {
            Persona add;
            cout << "Ingrese el identificador " << i + 1 << ": ";
            getline(cin, add.identf);
            cout << "Ingrese el nombre " << i + 1 << ": ";
            getline(cin, add.name);
            cout << "Ingrese el apellido: ";
            getline(cin, add.apelld);
            cout << "Ingrese la direccion: ";
            getline(cin, add.direct);
            cout << "Que tipo de contacto obtiene:" << endl;
            cout << "[1].ID" << endl;
            cout << "[2].Correo" << endl;
            cout << "[3].Telefono" << endl;
            cout << "Ingrese la opcion: ";
            int m;
            cin >> m;
            cin.ignore();
            switch (m) {
                case 1:
                    cout << "Ingrese el ID: ";
                    getline(cin, add.contact[0]);
                    break;
                case 2:
                    cout << "Ingrese el correo: ";
                    getline(cin, add.contact[1]);
                    break;
                case 3:
                    cout << "Ingrese el telefono: ";
                    getline(cin, add.contact[2]);
                    break;
                default:
                    cout << "Opción invalida" << endl;
                    break;
            }
            cout << endl;
            date.push_back(add);
        }
    }

    void display() {
        cout << "Identificador: " << identf << endl;
        cout << "Nombre: " << name << " " << apelld << endl;
        cout << "Direccion: " << direct << endl;
        cout << "Contacto:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "  " << contact[i] << endl;
        }
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
        for (int i = 0; i < 1; ++i) {
            departamento[i] = dept;
        }
    }

    virtual double salario_total() = 0;

    void date_empleado(vector<Empleado*> &info, int &n) {
        cout << "Numero de empleados: " << n << endl;
       
        for (int i = 0; i < n; ++i) {
            Empleado* emp ; // Se crea un nuevo objeto Empleado
            cout << "Ingrese el codigo " << i + 1 << ": ";
            cin >> emp->codigo;
            cout << "Ingrese el costo: ";
            cin >> emp->costo_hh;
            cin.ignore();
            cout << "Ingrese el departamento: ";
            cout<<"codigo del departamento:";
            cin>>emp->departamento[0];
            cout<<"Ingrese nombre del departamento:";
            cin>>emp->departamento[1];
            cout << endl;
            info.push_back(emp);
        }
    }

    void display() {
        Persona::display();
        cout << "Codigo: " << codigo << endl;
        cout << "Codigo del departamento: " << departamento[0] << endl;
        cout << "Nombre del departamento: " << departamento[1] << endl;
    }
};

class Gerente : public Empleado {
private:
    double bono;

public:
    Gerente(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double bn) : Empleado(idt, ap, na, dict, cont, c, cst, dept), bono(bn) {}

    double salario_total() override {
        return costo_hh + bono;
    }

    void display() {
        Empleado::display();
        cout << "Salario Total: " << salario_total() << endl;
    }
};

class Ingeniero : public Empleado {
private:
    double horax_ext;

public:
    Ingeniero(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double hx) : Empleado(idt, ap, na, dict, cont, c, cst, dept), horax_ext(hx) {}

    double salario_total() override {
        return costo_hh + horax_ext;
    }

    void display() {
        Empleado::display();
        cout << "Horas Extras: " << horax_ext << endl;
        cout << "Salario Total: " << salario_total() << endl;
    }
};

int main() {
    int n = 2;
    vector<Persona> personas;
    Persona p;
    p.add_date(personas, n);
    
    vector<Empleado*> empleados;
    Empleado *e;
    e->date_empleado(empleados, n);

    // Mostrar información de empleados
    cout << "Datos de los empleados:" << endl;
    for (auto emp : empleados) {
        emp->display();
        cout << endl;
    }

    return 0;
}
