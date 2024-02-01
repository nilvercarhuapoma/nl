

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Arboles
{
    // ... (sin cambios)
};

int main()
{
    int opcion = 0;

    do
    {
        cout << "MENU DE OPCIONES" << endl;
        cout << "1. Registrar madera" << endl;
        cout << "2. Datos informativos de la madera" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Código para registrar madera
            break;
        case 2:
            // Código para mostrar datos informativos de la madera
            break;
        }

    } while (opcion != 0);

    return 0;
}