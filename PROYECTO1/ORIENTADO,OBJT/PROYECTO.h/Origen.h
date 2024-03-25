#include "Zona.h"
#ifndef Origen_H
#define Origen_H
#include <iostream>
#include <vector>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Origen
{
private:
    Zona zona_dph;
    Zona zona_policial;
    string Departamento;
    string Provincia;
    string Distrito;
    string ubicacion_georeferenciada;

public:
    Origen() {}
    Origen(string D, string P, string dis, string U_b, Zona a_dph, Zona a_p) : zona_dph(a_dph), zona_policial(a_p), Departamento(D), Provincia(P), Distrito(dis),
                                                                               ubicacion_georeferenciada(U_b) {}
    void ingresarOrigen(vector<Origen> &direcciones);
    Zona geta_dph() const { return zona_dph; }
    Zona geta_p() const { return zona_policial; }
    string getD() const { return Departamento; }
    string getP() const { return Provincia; }
    string getdis() const { return Distrito; }
    string getU_b() const { return ubicacion_georeferenciada; }
};

void Origen::ingresarOrigen(vector<Origen> &direcciones)
{

    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE ORIGEN |" << endl;
    cout << "  ----------------------" << endl;
    Origen from;
    cout << "        Origen de usuario" << endl;
    cout << "Ingrese el departamento: ";
    getline(cin >> ws, from.Departamento);
    cout << "Ingrese la provincia: ";
    getline(cin >> ws, from.Provincia);
    cout << "Ingrese el distrito: ";
    getline(cin >> ws, from.Distrito);
    cout << "Ubicacion georeferenciada: ";
    getline(cin >> ws, from.ubicacion_georeferenciada);
    cout << endl;
    cout << "       Zona en la que actuara(origen)" << endl;
    int opcion_zona;
    cout << endl;
    cout << "Seleccione la zona de actuacion:" << endl;
    cout << "[1] ZONA DE D.P.H" << endl;
    cout << "[2] ZONA POLICIAL" << endl;
    cout << "[3] Ambas" << endl;
    cout << ":";
    cin >> opcion_zona;
    cin.ignore();

    switch (opcion_zona)
    {
    case 1:
        from.zona_dph.tipo = "ZONA DE D.P.H";
        from.zona_dph.ingresarZona(from.zona_dph, true);
        break;
    case 2:
        from.zona_policial.tipo = "ZONA POLICIAL";
        from.zona_policial.ingresarZona(from.zona_policial, false);
        break;
    case 3:
        from.zona_dph.tipo = "ZONA DE D.P.H";
        from.zona_policial.tipo = "ZONA POLICIAL";
        cout << "Datos para la zona de D.P.H:" << endl;
        from.zona_dph.ingresarZona(from.zona_dph, true);
        cout << "Datos para la zona policial:" << endl;
        from.zona_policial.ingresarZona(from.zona_policial, false);
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }

    direcciones.push_back(from);
}
#endif