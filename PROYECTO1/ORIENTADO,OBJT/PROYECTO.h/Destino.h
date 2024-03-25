#include "Conductor.h"
#ifndef Destino_H
#define Destino_H
#include <iostream>
#include <vector>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Destino
{
private:
    Conductor conductor;
    string lugar;
    string fechasalida;
    string destinofinal;
    string observacion;
    vector<Conductor> conductores;

public:
    Destino() {}
    Destino(vector<Conductor> &conduct, string n_c, int dni_c, string plc, int id_a, double cant, double vent, string l,
            string f_s, string d_f, string obs) : conductor(n_c, dni_c, plc, id_a, cant, vent), conductores(conduct), lugar(l), fechasalida(f_s), destinofinal(d_f),
                                                  observacion(obs) {}
    Conductor getcd() const { return conductor; }
    string getl() const { return lugar; }
    string getf_s() const { return fechasalida; }
    string getd_f() const { return destinofinal; }
    string getobs() const { return observacion; }

    void Ingresar_datosdestino(vector<Destino> &dest, vector<Conductor> &conduct);
};

void Destino::Ingresar_datosdestino(vector<Destino> &dest, vector<Conductor> &conduct)
{
    Destino destino;
    cout << "  --------------------------------" << endl;
    cout << " | REGISTRO DEL DESTINO DE MADERA |" << endl;
    cout << "  ---------------------------------" << endl;
    cout << "Ingrese el lugar de inicio(coordenadas UTM(x,y,huso)): ";
    getline(cin, destino.lugar);
    cout << "Ingrese la fecha de salida: ";
    getline(cin, destino.fechasalida);
    cout << "Ingrese el destino final(georeferencial): ";
    getline(cin, destino.destinofinal);
    cout << endl;
    destino.conductor.Conductor_destino(conduct);
    
    cout << "Total de costo:" << destino.conductor.suma_ventas(conduct);
    cin.ignore();
    cout << "Alguna observacion:";
    getline(cin, destino.observacion);
    dest.push_back(destino);
    cout << endl;
}
#endif