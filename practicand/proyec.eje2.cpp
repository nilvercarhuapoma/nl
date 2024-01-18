#include <iostream>
#include <vector>

// Estructura para representar un registro de madera
struct RegistroMadera {
    std::string tipo_madera;
    double calidad; // Puntuación de calidad de la madera (por ejemplo, escala del 1 al 10)
};

// Función para mostrar los registros de madera
void mostrarRegistros(const std::vector<RegistroMadera>& registros) {
    std::cout << "Registros de madera:" << std::endl;
    for (const auto& registro : registros) {
        std::cout << "Tipo: " << registro.tipo_madera << ", Calidad: " << registro.calidad << std::endl;
    }
}

int main() {
    std::vector<RegistroMadera> registros;

    // Ejemplo de captura de datos
    RegistroMadera registro1 = {"Pino", 8.5};
    RegistroMadera registro2 = {"Roble", 9.2};
    RegistroMadera registro3 = {"Cedro", 7.8};

    // Agregar registros al vector
    registros.push_back(registro1);
    registros.push_back(registro2);
    registros.push_back(registro3);

    // Mostrar los registros almacenados
    mostrarRegistros(registros);

    return 0;
}