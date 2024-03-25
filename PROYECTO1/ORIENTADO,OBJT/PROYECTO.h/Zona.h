#ifndef Zona_H
#define Zona_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Zona
{
private:
    string tipo;
    double metros_madera;
    string punto_cauce;
    string punto_central;

public:
    Zona() {}
    Zona(string ti, double m_m, string p_c, string p_cent) : tipo(ti), metros_madera(m_m), punto_cauce(p_c), punto_central(p_cent) {}
    friend class Origen;
    void ingresarZona(Zona &zona, bool es_dph);
    string gett() const { return tipo; }
    double getm_m() const { return metros_madera; }
    string getp_c() const { return punto_cauce; }
    string getp_cent() const { return punto_central; }
};

void Zona::ingresarZona(Zona &zona, bool es_dph)
{
    cout << "Coordenadas UTM (x)(y)(HUSO)" << endl;
    cout << "Punto central:";
    getline(cin >> ws, punto_central);
    cout << "Punto mas cercano al cauce:";
    getline(cin >> ws, punto_cauce);

    if (es_dph)
    {
        cout << "Metros cubicos de madera:";
        cin >> metros_madera;
        cin.ignore();
    }
}
#endif