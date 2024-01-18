#include <iostream>
#include <vector>
#include <string>

// Estructura para representar un registro de madera
struct RegistroMadera {
    std::string tipo_madera;
    double calidad;
    // Aquí podrían añadirse más atributos, como fecha, lugar de obtención, etc.
};

// Función para agregar un nuevo registro de madera
void agregarRegistro(std::vector<RegistroMadera>& registros) {
    RegistroMadera nuevoRegistro;
    std::cout << "Ingrese el tipo de madera: ";
    std::cin >> nuevoRegistro.tipo_madera;
    std::cout << "Ingrese la calidad de la madera (en una escala del 1 al 10): ";
    std::cin >> nuevoRegistro.calidad;

    registros.push_back(nuevoRegistro);
    std::cout << "Registro agregado correctamente." << std::endl;
}

// Función para mostrar todos los registros de madera
void mostrarRegistros(const std::vector<RegistroMadera>& registros) {
    std::cout << "Registros de madera:" << std::endl;
    for (const auto& registro : registros) {
        std::cout << "Tipo: " << registro.tipo_madera << ", Calidad: " << registro.calidad << std::endl;
    }
}

int main() {
    std::vector<RegistroMadera> registros;

    char opcion;
    do {
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Agregar registro" << std::endl;
        std::cout << "2. Mostrar registros" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1':
                agregarRegistro(registros);
                break;
            case '2':
                mostrarRegistros(registros);
                break;
            case '3':
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != '3');

    return 0;
}
