#ifndef Madera_H
#define Madera_H
#include <iostream>
#include <vector>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Madera
{
protected:
    string nombre_M;
    string trabajo;
    int cantidad;
    double superficie;

public:
    Madera() {}
    Madera(string n, string t, int cant, double supfc) : nombre_M(n), trabajo(t), cantidad(cant), superficie(supfc) {}
    void ingresar_madera(vector<Madera> &datos_madera);
    string getn_M() const { return nombre_M; }
    string getT() const { return trabajo; }
    int getcant_M() const { return cantidad; }
    double getsuprf() const { return superficie; }
};

void Madera::ingresar_madera(vector<Madera> &datos_madera)
{
    cout << endl;
    cout << "  -------------------------" << endl;
    cout << "  | REGISTRO DE MADERA     |" << endl;
    cout << "  -------------------------" << endl;

    int information;
    cout << "Cuantos tipos de madera está trabajando: ";
    cin >> information;
    cin.ignore();
    for (int i = 0; i < information; ++i)
    {
        Madera tree;
        cout << "Ingrese el nombre de la madera " << i + 1 << ": ";
        getline(cin, tree.nombre_M);
        cout << "Ingrese la cantidad de madera: ";
        cin >> tree.cantidad;
        cin.ignore();
        cout << "Ingrese el tamaño del arbol (hectareas): ";
        cin >> tree.superficie;
        cin.ignore();
        cout << "Fueron plantados por usted (si/no): ";
        getline(cin, tree.trabajo);
        cout << "\n";
        datos_madera.push_back(tree);
    }
    cout << endl;
}
#endif