#include <iostream>
#include <vector>
using namespace std;
class University
{
private:
    string nombre;
    int creacion;

public:
    University(string n, int c) : nombre(n), creacion(c) {}
    virtual void ubicacion() = 0;
    void mostrar()
    {
        cout << "Nombre:" << nombre << endl;
        cout << "Creacion:" << creacion << endl;
        cout << "Ubicacion:";
        ubicacion();
    }
};
class U_publicas : public University
{
private:
    int telf;

public:
    U_publicas(string nombre, int creacion, int tl) : University(nombre, creacion), telf(tl) {}
    void mostrar()
    {
        University::mostrar();
        cout << "Telefono:" << telf << endl;
    }
    void ubicacion() override
    {
        cout << ": Carretera Central km. 1.21. Tingo Maria - Peru" << endl;
    }
};
class U_privadas : public U_publicas
{
private:
    double cost_matricul;

public:
    U_privadas(string nombre, int creacion, int telf, double cst) : U_publicas(nombre, creacion, telf), cost_matricul(cst) {}
    void mostrar()
    {
        U_publicas::mostrar();
        cout << "Costo de matricula promedio:" << cost_matricul << endl;
    }
    void ubicacion() override
    {
        cout << "Av. Universitaria 1801, San Miguel 15088" << endl;
    }
};
class Institutos : public U_privadas
{
private:
    int carreras;

public:
    Institutos(string nombre, int creacion, int telf, double cost_matricula, int cars) : U_privadas(nombre, creacion, telf, cost_matricula), carreras(cars) {}
    void mostar()
    {
        U_privadas::mostrar();

        cout << "Cantidad de carreras:" << carreras << endl;
    }
    void ubicacion() override
    {
        cout << " Av. Alfredo Mendiola 3540, San Martin de Porres 15311" << endl;
    }
};
int main()
{
    cout << "Universidad publica:" << endl;
    U_publicas u1("UNAS", 1961, 994411862);
    u1.mostrar();
    cout << endl;
    cout << "Universidad privada:" << endl;
    U_privadas p1("PUCP", 1917, 016262000, 4560);
    p1.mostrar();
    cout << endl;
    cout << "Un instituto cualquiera:" << endl;
    Institutos i1("SENATI", 1961, 946973754, 344.00, 72);
    i1.mostar();
}