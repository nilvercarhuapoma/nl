#ifndef Permiso_H
#define Permiso_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Permiso
{
private:
    string documentacion[5];
    string organizacion;

public:
    Permiso() {}
    

    string getdoc(int index) const { return documentacion[index]; }

    string getorganizacion() const { return organizacion; }

    void Ingresar_permiso(vector<Permiso> &perms, int &diaslaborales);
    string get_FechaActual()
    {
        time_t now = time(0);
        tm *timeinfo = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
        return string(buffer);
    }

    string obtenerFechaVencimiento(int &diaslaborales);
};

string Permiso::obtenerFechaVencimiento(int &diaslaborales)
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    // Sumar los días laborales a la fecha actual
    int diasSumados = 0;
    while (diasSumados < diaslaborales)
    {
        timeinfo->tm_mday++;
        mktime(timeinfo);
        // No contar los fines de semana (sábado y domingo)
        if (timeinfo->tm_wday != 0 && timeinfo->tm_wday != 6)
        {
            diasSumados++;
        }
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

void Permiso::Ingresar_permiso(vector<Permiso> &perms, int &diaslaborales)
{
    Permiso permiso;
    cout << "  ----------------------" << endl;
    cout << "  | REGISTRO DE PERMISOS |" << endl;
    cout << "  ----------------------" << endl;

    int numDocumentos = 0;
    // Incrementar el contador de documentos
    numDocumentos++;
    cout << endl;
        cout << "Adjunte los siguientes documentos:" << endl;
    cout << "CIF de la Entidad: ";
    getline(cin, permiso.documentacion[0]);
    cout << "Representación que ostenta: ";
    getline(cin, permiso.documentacion[1]);
    cout << "Croquis de la zona de corta: ";
    getline(cin, permiso.documentacion[2]);
    cout << "Informe sobre los efectos nocivos para el medio: ";
    getline(cin, permiso.documentacion[3]);
    cout << "Otra documentación: ";
    getline(cin, permiso.documentacion[4]);

    cout << "Ingrese la organizacion:";
    getline(cin, permiso.organizacion);
    cout << endl;
    cout << "Fecha inicial del permiso : " << permiso.get_FechaActual();
    cout << endl;
    cout << "Cunatos dias necesita para realizar dicha TALA:";
    cin >> diaslaborales;
    cout << "Fecha final del permiso : " << permiso.obtenerFechaVencimiento(diaslaborales);
    perms.push_back(permiso);
    cout << endl;
}
#endif