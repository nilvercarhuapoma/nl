#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Definición de la estructura
struct Persona
{
    string nombre;
    string dni;
};

struct Permiso
{

    string fechaOtorgamiento;
    string fechaVencimiento;
    Persona representanteLegal;
};

// Función para obtener la fecha actual
string obtenerFechaActual()
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

int main()
{
    // Declaración de variables
    int numDocumentos = 0;
    char continuar;

    do
    {
        // Incrementar el contador de documentos
        numDocumentos++;

        // Declaración de una variable de tipo Permiso
        Permiso permiso;

        // Solicitar datos al usuario

        // Obtener la fecha actual
        permiso.fechaOtorgamiento = obtenerFechaActual();
        cout << "Fecha de otorgamiento: " << permiso.fechaOtorgamiento << endl;

        cout << "Ingrese la fecha de vencimiento (YYYY-MM-DD): ";
        getline(cin, permiso.fechaVencimiento);

        cout << "Ingrese el nombre del representante legal: ";
        getline(cin, permiso.representanteLegal.nombre);

        cout << "Ingrese el DNI del representante legal: ";
        getline(cin, permiso.representanteLegal.dni);

        // Mostrar los datos ingresados
        cout << "\nDatos del permiso " << numDocumentos << ":" << endl;

        cout << "Fecha de otorgamiento: " << permiso.fechaOtorgamiento << endl;
        cout << "Fecha de vencimiento: " << permiso.fechaVencimiento << endl;
        cout << "Representante Legal:" << endl;
        cout << "Nombre: " << permiso.representanteLegal.nombre << endl;
        cout << "DNI: " << permiso.representanteLegal.dni << endl;

        // Preguntar al usuario si desea continuar ingresando datos
        cout << "\n¿Desea ingresar otro documento? (s/n): ";
        cin >> continuar;
        cin.ignore();
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
