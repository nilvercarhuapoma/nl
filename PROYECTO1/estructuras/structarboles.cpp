#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
struct Madera
{
    string nombre;
    string origen_geografico;
    string trabajo;
    int id_arbol;
    int cantidad;
    int edad;
    double tamaño_parcela;
};
int main()
{

    vector<Madera> datos;
    int information;
    ofstream Arboles("arbol.txt");
    if (Arboles.is_open())
    {
        cout << " cuantos tipos de arboles desea registrar:";
        cin >> information;
        cin.ignore();
        for (int i = 0; i < information; ++i)
        {
            
            Madera add;

            cout << "ingrese el nombre " << i + 1 << ": ";
            getline(cin, add.nombre);
            cout << "ingrese el tamanio del terreno(hectareas):";
            cin >> add.tamaño_parcela;
            cin.ignore();
            cout << "Fueron plantados por ustedes(si)(no):";
            cin >> add.trabajo;
            cin.ignore();
            cout << "ingrese el lugar de donde procede:";
            getline(cin, add.origen_geografico);
            cout << "\n";
            datos.push_back(add);

            for (const Madera &arbol : datos)
            {
                Arboles << "Nombre: " << arbol.nombre << endl;
                Arboles << "Tamaño de parcela: " << arbol.tamaño_parcela << endl;
                Arboles << "Cantidad: " << arbol.cantidad << endl;
                Arboles << "Origen geográfico: " << arbol.origen_geografico << endl;

                Arboles << "------------------------------------------" << endl;
            }
        }
        Arboles.close();
        cout << "Datos guardados exitosamente en 'arboles.txt'.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo.\n";
    }
}
