#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Zona
{
    string punto_central;
    string punto_cauce;
    double metros_madera;
};

struct Origen
{
    string Departamento;
    string Provincia;
    string Distrito;
    string ubicacion_georeferenciada;
    Zona zona;
};

void ingresarOrigen(vector<Origen> &direcciones)
{
    Origen from;
    cout << "Ingrese el departamento: ";
    getline(cin >> ws, from.Departamento);

    cout << "Ingrese la provincia: ";
    getline(cin >> ws, from.Provincia);

    cout << "Ingrese el distrito: ";
    getline(cin >> ws, from.Distrito);

    cout << "Ubicacion georeferenciada: ";
    getline(cin >> ws, from.ubicacion_georeferenciada);

    direcciones.push_back(from);
}

void ingresarCoordenadas(Zona &zona)
{
    cout << "Coordenadas UTM (x)(y)(HUSO)"<<endl;
   
    cout << "Punto central:";
    getline(cin >> ws, zona.punto_central);

    cout << "Punto mas cercano al cauce:";
    getline(cin >> ws, zona.punto_cauce);

}

int main()
{
    vector<Origen> direcciones;

    ingresarOrigen(direcciones);

    int number = 0;
    Zona zona;

    do
    {
        cout << "LOCALIZACION DE LA ACTUACION:" << endl;
        cout << "[1]. ZONA DE D.P.H" << endl;
        cout << "[2]. ZONA DE POLICIA" << endl;
        cout << "[3]. Ambas" << endl;
        cout << "[0]. Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> number;

        switch (number)
        {
        case 1:
            cout << "ZONA DE D.P.H" << endl;
            ingresarCoordenadas(zona);
            break;
        case 2:
            cout << "ZONA DE POLICIA" << endl;
            ingresarCoordenadas(zona);
            break;
        case 3:
            cout << "ZONA DE D.P.H" << endl;
            ingresarCoordenadas(zona);
            cout << "M3 de madera:";
            cin >> zona.metros_madera;
            cin.ignore(); // Limpiar el buffer

            cout << "ZONA DE POLICIA" << endl;
            ingresarCoordenadas(zona);
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (number != 0);

    cout << "Se guardaron los datos" << endl;

    return 0;
}
