#include "Madera.h"
#ifndef Tala_H
#define Tala_H
#include <iostream>
#include <vector>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Tala : public Madera
{
private:
    int id_arbol;
    int numero_arbol;
    double densidad;
    string fecha_de_corte;

public:
    Tala() : Madera() {}
    Tala(string n, string t, int cant, double supfc, int id, int N_a, double densd, string f_c)
        : Madera(n, t, cant, supfc), id_arbol(id), numero_arbol(N_a), densidad(densd), fecha_de_corte(f_c) {}
    int getid() const { return id_arbol; }
    int getN_a() const { return numero_arbol; }
    double getdensd() const { return densidad; }
    string getf_c() const { return fecha_de_corte; }

    void ingresar_tala(vector<Tala> &info_tala);

    double suma_superficie(vector<Tala> &info_tala);
};

void Tala::ingresar_tala(vector<Tala> &info_tala)
{
    cout << "  -------------------" << endl;
    cout << "  | REGISTRO DE TALA |" << endl;
    cout << "  -------------------" << endl;

    int cant_tala;
    cout << "CARACTERISTICAS DE LOS ARBOLES A CORTAR" << endl;
    cout << "Cuantas variedades se cortaran: ";
    cin >> cant_tala;
    cin.ignore();
    for (int i = 0; i < cant_tala; ++i)
    {
        Tala cut;
        cout << "Asignar un ID al arbol " << i + 1 << " : ";
        cin >> cut.id_arbol;
        cin.ignore();
        cout << "Nombre de la madera: ";
        getline(cin, cut.nombre_M);
        cout << "Fueron plantados por ustedes (si/no):";
        cin >> cut.trabajo;
        cout << "Ingrese la fecha de corte: ";
        cin >> cut.fecha_de_corte;
        cin.ignore();
        cout << "Numero total de arboles: ";
        cin >> cut.numero_arbol;
        cin.ignore();
        cout << "Ingrese la densidad: ";
        cin >> cut.densidad;
        cin.ignore();
        cout << "Superficie a cortar (hectareas): ";
        cin >> cut.superficie;
        cin.ignore();
        cout << "\n";
        info_tala.push_back(cut);
    }
    cout << endl;
}
double Tala::suma_superficie(vector<Tala> &info_tala)
{
    double sumaSuperficie = 0.0;
    for (const auto &tala : info_tala)
    {
        sumaSuperficie += tala.getsuprf();
    }
    return sumaSuperficie;
}
#endif