#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
struct Usuario
{
    string nombre;
    string documentacion;
    string nombre_parcela;
    int DNI;
    int edad;
    int telefono;
    string correo;
};
int main()
{
    vector<Usuario> datos;
    ofstream identidad("Registro de usaurio.txt");
    if (identidad.is_open())
    {
        cout << "REGISTRESE:" << endl;
        Usuario date;
        cin.ignore();
        cout << "ingrese su nombre completo:";
        getline(cin, date.nombre);
        cout << "ingrese su edad:";
        cin >> date.edad;
        cin.ignore();
        cout << "Igrese su DNI:";
        cin >> date.DNI;
        cin.ignore();
        cout << "ingrese el nombre de su parcela: ";
        getline(cin, date.nombre_parcela);
        cout << "adjunte su documentacion:";
        getline(cin, date.documentacion);
        cout << "\n";
        datos.push_back(date);

        for (const Usuario &ident : datos)
        {
            identidad << "Nombre completo: " << ident.nombre << endl;
            identidad << "DNI:" << ident.DNI << endl;
            identidad << "Su edad: " << ident.edad << endl;
            identidad << "Nombre de su parcel :" << ident.nombre_parcela << endl;
            identidad << "Su documentacion: " << ident.documentacion << endl;
            cout << "........................................" << endl;
        }
        identidad.close();
        cout << "datos guardados";
    }
    else
    {
        cout << "no se pudo abrir este archivo";
    }
    return 0;
}