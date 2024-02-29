#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Tala
{
    int id_arbol;
    int numero_arbol;
    double densidad;
    double superficie_cortar;
    int fecha_de_corte;
    string variedad;
    string id_encargado;
};
int main()
{
    double suma = 0;
    vector<Tala> info_tala;
    string option;
    int cant_tala;
    cout << "CARACTERISTICAS DE LOS ARBOLES A CORTAR" << endl;
    cout << "Fueron plantados por el solicitante(si)/(no):";
    cin >> option;
    cout << "Cuantas variedades se cortaran:";
    cin >> cant_tala;
    ofstream talar("Tala.txt");
    if (talar.is_open())
    {
        cout << "             REGISTRELOS:" << endl;
        for (int i = 0; i < cant_tala; ++i)
        {
            Tala add_tala;
            cout << "Ingrese el id de la madera " << i + 1 << " :";
            cin >> add_tala.id_arbol;
            cin.ignore();
            cout << "Nombre de la madera:";
            getline(cin, add_tala.variedad);
            cout << "Ingrese la fecha de corte:";
            cin >> add_tala.fecha_de_corte;
            cin.ignore();
            cout << "Numero total de arboles:";
            cin >> add_tala.numero_arbol;
            cin.ignore();
            cout << "Ingrese la densidad:";
            cin >> add_tala.densidad;
            cin.ignore();
            cout << "Superficie a cortar(hectareas):";
            cin >> add_tala.superficie_cortar;
            cin.ignore();

            cout << "\n";
            info_tala.push_back(add_tala);
            suma += add_tala.superficie_cortar;
        }
        cout << "Superficie total:" << suma << endl;
        for (const Tala &tal1 : info_tala)
        {
            cout << "....................................." << endl;
            talar << "ID de la madera:" << tal1.id_arbol << endl;
            talar << "Fecha de corte:" << tal1.fecha_de_corte << endl;

            talar << "ID del encargado:" << tal1.id_encargado << endl;
        }
        talar.close();
        cout << "Datos guardados" << endl;
    }
}