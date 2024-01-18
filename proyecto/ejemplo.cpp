#include <iostream>
#include <vector>
#include <string>

struct MarcaCelular {
    std::string nombre;
    std::string modelo;
    std::string sistema_operativo;
    int anio_lanzamiento;
};

int main() {
    std::vector<MarcaCelular> marcas;

    // Registrar información de algunas marcas de celulares
    MarcaCelular marca1 = {"Apple", "iPhone 13", "iOS", 2021};
    MarcaCelular marca2 = {"Samsung", "Galaxy S21", "Android", 2021};
    MarcaCelular marca3 = {"Google", "Pixel 6", "Android", 2021};

    // Agregar las marcas al vector
    marcas.push_back(marca1);
    marcas.push_back(marca2);
    marcas.push_back(marca3);

    // Mostrar la información almacenada
    std::cout << "Informacion de Marcas de Celulares:" << std::endl;
    for (const auto& marca : marcas) {
        std::cout << "Marca: " << marca.nombre << std::endl;
        std::cout << "Modelo: " << marca.modelo << std::endl;
        std::cout << "Sistema Operativo: " << marca.sistema_operativo << std::endl;
        std::cout << "Año de Lanzamiento: " << marca.anio_lanzamiento << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }

    return 0;
}

