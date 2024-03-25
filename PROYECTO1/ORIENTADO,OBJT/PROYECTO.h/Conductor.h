#ifndef Conductor_H
#define Conductor_H
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Conductor
{

private:
    string nombreConductor;
    int dniConductor;
    string placaVehiculo;
    int idarbol;
    double cantidad;
    double ventas;

public:
    Conductor() {}
    Conductor(string n_c, int dni_c, string plc, int id_a, double cant, double vent) : nombreConductor(n_c),
                                                                                       dniConductor(dni_c), placaVehiculo(plc), idarbol(id_a), cantidad(cant), ventas(vent) {}

    string getn_c() const { return nombreConductor; }
    int getdni_c() const { return dniConductor; }
    string getplc() const { return placaVehiculo; }
    int getid_a() const { return idarbol; }
    double geticant() const { return cantidad; }
    double getvent() const { return ventas; }

    void Conductor_destino(vector<Conductor> &conduct);
    double suma_ventas(vector<Conductor> &conduct);
};
void Conductor::Conductor_destino(vector<Conductor> &conduct)
{
    int vh;

    int venta;
    cout << "Cuantos vehiculos se llevaran de madera:";
    cin >> vh;
    cin.ignore();
    for (int i = 0; i < vh; ++i)
    {
        Conductor cdtr;
        cout << "Ingrese apellidos y nombres del conductor del vehiculo " << i + 1 << " :";
        getline(cin, cdtr.nombreConductor);
        bool errorMostrado = false;

    do {
        if (!errorMostrado) {
            cout << "Ingrese su DNI : ";
        }

        if (!(cin >> cdtr.dniConductor) || cin.peek() != '\n' || to_string(cdtr.dniConductor).length() != 8) {
            if (!errorMostrado) {
                cout << "Datos incorrectos. Intintalo de nuevo." << endl;
                errorMostrado = true;
            }

            // Secuencia de escape ANSI para mover el cursor hacia arriba y borrar líneas anteriores
            cout << "\033[A\033[2K";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
        cin.ignore();
        cout << "Ingrese la placa del vehiculo:";
        getline(cin, cdtr.placaVehiculo);
        cout << "Ingrese el ID de la madera a llevar: ";
        cin >> cdtr.idarbol;
        cin.ignore();
        cout << "Cantidad a llevar (Toneladas):";
        cin >> cdtr.cantidad;
        cout << "Total de costo a llevar de madera:";
        cin >> cdtr.ventas;
        cin.ignore();

        cout << endl;
        conduct.push_back(cdtr);
    }
    
}
double Conductor::suma_ventas(vector<Conductor> &conduct)
{
    double suma = 0.0;
    for (const auto &cdtr : conduct)
    {
        suma += cdtr.getvent();
    }
    return suma;
}
#endif