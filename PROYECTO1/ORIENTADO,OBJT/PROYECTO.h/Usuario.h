#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;

class Usuario
{

private:
    string nombre;
    int DNI;
    int telefono;
    string correo;
    string Ubicacion;

public:
    Usuario() {}
    Usuario(string n, int dni, int telf, string cor) : nombre(n), DNI(dni), telefono(telf), correo(cor) {}
    void add_usuario(vector<Usuario> &date_usuario);

    friend class Representante;
    string getn() const { return nombre; }
    int getdni() const { return DNI; }
    int gettelf() const { return telefono; }
    string getcor() const { return correo; }
};

void Usuario::add_usuario(vector<Usuario> &date_usuario)
{
    cout << "              | SISTEMA DE VERIFICACION Y SEGUIMIENTO LEGAL DE MADERA |" << endl;
    cout << "Registrese correctamente" << endl;
    cout << endl;
    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE USUARIO |" << endl;
    cout << "  ----------------------" << endl;

    // Registro de Usuario
    Usuario user;
    cout << "Ingrese apellidos y nombres:";
    getline(cin, user.nombre);
     bool errorMostrado = false;

    do {
        if (!errorMostrado) {
            cout << "Ingrese su DNI : ";
        }

        if (!(cin >>user.DNI) || cin.peek() != '\n' || to_string(user.DNI).length() != 8) {
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
    cin >> user.telefono;
    cin.ignore();
    cout << "Ingrese su correo electronico:";
    getline(cin, user.correo);

    cout << "\n";
    date_usuario.push_back(user);
}
#endif