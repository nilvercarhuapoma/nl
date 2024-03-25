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

    void add_date(vector<Persona> &date, int n[2]) {
        cout << "Total de personas: " << n[2] << endl;
        
        for (int i = 0; i < n[2]; ++i) {
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
                    cout << "Opción inválida" << endl;
                    break;
            }
            cout << endl;
            date.push_back(add);
        }
    }

    void display1() {
        cout << "Identificador: " << identf[0] << endl;
        cout << "Nombre: " << name[0] << " " << apelld[0] << endl;
        cout << "Direccion: " << direct[0] << endl;
        cout << "Contacto:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "  " << contact[i] << endl;
        }
    }
    void display2(){
        cout << "Identificador: " << identf[1] << endl;
        cout << "Nombre: " << name[1] << " " << apelld[1] << endl;
        cout << "Direccion: " << direct[1] << endl;
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

    virtual double salario_total()=0;

   void agg_empleado(vector<Empleado>&em) {
        Empleado e;
        cout << "Codigo: " ;
        cin>>e.codigo;
        cout<<"Ingrese el costo:";
        cin>>e.costo_hh;
        cout << "Codigo del departamento: ";
        cin>>e.departamento[0];
        cout << "Nombre del departamento: ";
        getline(cin,e.departamento[1]);
        cin.ignore();
        em.push_back(e);
    }
    void mostrar(vector<Empleado>&em){
     Persona::display1();
     Persona::display2();
     cout<<"Codigo:"<<codigo;  
     cout<<"Costo:"<<costo_hh;  
     cout<<"Codigo del departamento:"<<departamento[0];  
     cout<<"Nombre del departamento:"<<departamento[1];  

    }
};

class Gerente : public Empleado {
private:
    double bono;

public:
Gerente(){}
    Gerente(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double bn) : Empleado(idt, ap, na, dict, cont, c, cst, dept), bono(bn) {}

    double salario_total() override {
        return costo_hh + bono;
    }

    void agg_gerent(vector<Gerente>&gert){
        Empleado::display1();
        Gerente gt;
        cout<<"Ingrese el bono:";
        cin>>gt.bono;
        cout << "Salario Total: " << salario_total() << endl;
        gert.push_back(gt);
    }
    void mostrar1(){
    Persona::display1;
    Empleado::mostrar();
    cout<<"Bono:"<<bono<<endl;
    
    }
};

class Ingeniero : public Empleado {
private:
    double horax_ext;

public:
    Ingeniero(){}
    Ingeniero(string idt, string ap, string na, string dict, string cont, int c, double cst, string dept, double hx) : Empleado(idt, ap, na, dict, cont, c, cst, dept), horax_ext(hx) {}

    double salario_total() override {
        return costo_hh + horax_ext;
    }

    void agg_inge(vector<Ingeniero>&ing) {
        Empleado::display2();
        Ingeniero agg;
        cout << "Horas Extras: ";
        cin>>agg.horax_ext;
        cout << "Salario Total: " << salario_total() << endl;
        ing.push_back(agg);

    }
    void mostrar(){
        Persona::display2();
        Empleado::mostrar();
        cout<<"Pago de horas extras:"<<horax_ext<<endl;
        cout<<"Salario total:"<<salario_total();
    }
};

int main() {
    int n = 2;
    Persona p;
    vector<Persona>date;
    p.add_date(date,n);
    Empleado e1;
    vector<Empleado>em;
   e1.agg_empleado(em);
    Gerente g1;
    vector<Gerente>gert;
    g1.agg_gerent(gert);
    Ingeniero i1;
    vector<Ingeniero>ing;
    i1.agg_inge(ing);
    //mostrar los datos:
    cout<<"   GERENTE:"<<endl;
    p.display1();
    e1.mostrar(em);
    g1.mostrar1();
    e1.salario_total();
    cout<<endl;
    cout<<"   INGENIERO:"<<endl;
    p.display2();
    e1.mostrar(em);
    i1.mostrar();
    i1.salario_total();
    return 0;
}
