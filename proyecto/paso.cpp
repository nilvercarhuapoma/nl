#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Formulario con Adjuntos\n";

    // Campos de texto y otros campos del formulario
    std::string nombre;
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    // Campo para subir imágenes
    std::cout << "Adjuntar Imágenes (ingresa nombres de archivos separados por espacios): ";
    std::string imagenes;
    std::getline(std::cin, imagenes);

    // Campo para subir documentos
    std::cout << "Adjuntar Documentos (ingresa nombres de archivos separados por espacios): ";
    std::string documentos;
    std::getline(std::cin, documentos);

    // Campo para enlaces
    std::string enlace;
    std::cout << "Enlace: ";
    std::getline(std::cin, enlace);

    // Otros campos del formulario

    // Procesar la información
    std::cout << "\nInformación Recibida:\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Imágenes Adjuntas: " << imagenes << "\n";
    std::cout << "Documentos Adjuntos: " << documentos << "\n";
    std::cout << "Enlace: " << enlace << "\n";

    // Puedes realizar acciones adicionales, como guardar la información en archivos, etc.

    return 0;
}