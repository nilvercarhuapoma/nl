#include <iostream>
#include <string>

std::string cifradoCesar(const std::string& texto, int clave) {
    std::string resultado = "";

    for (char caracter : texto) {
        // Verificar si el carácter es una letra mayúscula
        if (isalpha(caracter) && isupper(caracter)) {
            resultado += 'A' + (caracter - 'A' + clave) % 26;
        }
        // Verificar si el carácter es una letra minúscula
        else if (isalpha(caracter) && islower(caracter)) {
            resultado += 'a' + (caracter - 'a' + clave) % 26;
        }
        // Mantener otros caracteres sin cambio
        else {
            resultado += caracter;
        }
    }

    return resultado;
}

int main() {
    std::string texto;
    int clave;

    // Solicitar al usuario ingresar una cadena
    std::cout << "Ingrese una cadena: ";
    std::getline(std::cin, texto);

    // Solicitar al usuario ingresar la clave del cifrado
    std::cout << "Ingrese la clave del cifrado: ";
    std::cin >> clave;

    // Aplicar el cifrado César
    std::string textoCifrado = cifradoCesar(texto, clave);

    // Mostrar el resultado
    std::cout << "Texto cifrado: " << textoCifrado << std::endl;

    return 0;
}