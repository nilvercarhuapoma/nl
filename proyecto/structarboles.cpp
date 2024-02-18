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
    int fecha_de_corte;
    int cantidad;
    int edad;
    int tamaño_parcela;
};
int main()
{

    vector<Madera> datos;
    int information;
    cin.ignore();
    ofstream Arboles("resgistro de arboles.txt");
    if (Arboles.is_open())
    {
        cout << " cuaton tipos de arboles desea registrar:";
        cin >> information;
        for (int i = 0; i < information; ++i)
        {

            Madera add;
            cin.ignore();
            cout << "ingrese el nombre " << i + 1 << ": ";
            getline(cin, add.nombre);
            cout << "ingrese el tamanio de parcela:";
            cin >> add.tamaño_parcela;
            cin.ignore();
            cout << "ingrese el anio de la madera :";
            cin >> add.cantidad;
            cin.ignore();
            cout << "ingrese el lugar de donde procede:";
            getline(cin, add.origen_geografico);
            cout << "ingrese la fecha de corte: ";
            cin >> add.fecha_de_corte;
            cout << "\n";
            datos.push_back(add);

            for (const Madera &arbol : datos)
            {
                Arboles << "Nombre: " << arbol.nombre << endl;
                Arboles << "Tamaño de parcela: " << arbol.tamaño_parcela << endl;
                Arboles << "Cantidad: " << arbol.cantidad << endl;
                Arboles << "Origen geográfico: " << arbol.origen_geografico << endl;
                Arboles << "Fecha de corte: " << arbol.fecha_de_corte << endl;
                Arboles << "------------------------------------------" << endl;
            }
        }
        Arboles.close();
        cout << "Datos guardados exitosamente en 'registro_de_arboles.txt'.\n";
    }
    else
    {
        cout << "No se pudo abrir el archivo.\n";
    }
}
