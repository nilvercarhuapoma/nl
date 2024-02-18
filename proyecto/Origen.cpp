#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
struct Origen
{
    string Departamento;
    string Provincia;
    string Distrito;
    string localidad;
    string ubicacion_georeferenciada;
};
int main()
{
    vector<Origen> direcction;
    ofstream ubication("Origen.txt");
    if (ubication.is_open())
    {
        cout << "INGRESE LOS DATOS:" << endl;
        Origen from;
        cout << "Ingrese el departamento :";
        getline(cin, from.Departamento);
        cout << "Ingrese la provincia: ";
        getline(cin, from.Provincia);
        cout << "ingrese el distrito:";
        getline(cin, from.Distrito);
        cout << "Ubicacion georeferenciada: ";
        getline(cin, from.ubicacion_georeferenciada);
        direcction.push_back(from);
        cout << "\n";
        for (const Origen &ubic : direcction)
        {
            ubication << "DEPARTAMENTO:" << ubic.Departamento << endl;
            ubication << "PROVINCIA:" << ubic.Provincia << endl;
            ubication << "DISTRITO:" << ubic.Distrito << endl;
            ubication << "UBICACION GEOREFERENCIADA:" << ubic.ubicacion_georeferenciada << endl;
            cout << "..............................................." << endl;
        }
        ubication.close();
        cout << "Se guardaron los datos";
    }
    else
    {
        cout << "este archivo no se pudo abrir";
    }
}