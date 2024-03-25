#include "Usuario.h"
#ifndef Representante_H
#define Representante_H
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;
class Representante : public Usuario
{
private:

    string ubicacion;

public:
    Representante() : Usuario() {}
    Representante(string u) : ubicacion(u) {}
    string get_u() const { return ubicacion; }
    void ingresar_representante(vector<Representante> &representante);
};
void Representante::ingresar_representante(vector<Representante> &representante)
{
    Representante represt;
    cout << "Ingrese los apellidos y nombres del representate:" << endl;
    cout << "Ingrese apellidos y nombres:";
    getline(cin, represt.nombre);
   bool errorMostrado = false;

    do {
        if (!errorMostrado) {
            cout << "Ingrese su DNI : ";
        }

        if (!(cin >> DNI) || cin.peek() != '\n' || to_string(DNI).length() != 8) {
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
    cout << "Ingrese su telefono:";
    cin >> represt.telefono;
    cin.ignore();
    cout << "Ingrese su correo electronico:";
    getline(cin, represt.correo);
    cout << "Ingrese una ubicaion georreferenciada:";
    getline(cin, represt.ubicacion);
    representante.push_back(represt);
    cout << "\n";
    
}

#endif