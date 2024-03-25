#include <iostream>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "---- MENÚ PRINCIPAL ----" << endl;
    cout << "1. Realizar acción 1" << endl;
    cout << "2. Realizar acción 2" << endl;
    cout << "3. Salir del programa" << endl;
    cout << "------------------------" << endl;
}

int main() {
    int opcion;
    bool salir = false;

    do {
        mostrarMenuPrincipal();
        
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Acción 1
                cout << "Realizando acción 1..." << endl;
                // Aquí puedes poner la lógica para la acción 1
                break;
            case 2:
                // Acción 2
                cout << "Realizando acción 2..." << endl;
                // Aquí puedes poner la lógica para la acción 2
                break;
            case 3:
                // Salir del programa
                salir = true;
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (!salir);

    return 0;
}
