#include <iostream>
#include <string>

// Función para encriptar un mensaje utilizando el cifrado César con el código ASCII
std::string encriptarMensaje(const std::string& mensaje, int clave) {
    std::string mensajeEncriptado = mensaje;

    // Recorre cada carácter del mensaje y realiza el desplazamiento según la clave
    for (char& caracter : mensajeEncriptado) {
        // Solo procesa caracteres alfabéticos
        if (isalpha(caracter)) {
            // Obtén el código ASCII base para mayúsculas o minúsculas
            char base = islower(caracter) ? 'a' : 'A';
            // Aplica el desplazamiento utilizando el código ASCII
            caracter = ((caracter - base + clave) % 26) + base;
        }
    }

    return mensajeEncriptado;
}

// Función para desencriptar un mensaje encriptado con el cifrado César
std::string desencriptarMensaje(const std::string& mensajeEncriptado, int clave) {
    // La operación de desencriptar es la inversa de encriptar, así que usamos la misma función
    return encriptarMensaje(mensajeEncriptado, 26 - clave); // Utilizamos 26 - clave para obtener la operación inversa
}

int main() {
    std::string mensaje = "Hola, este es un mensaje secreto";
    int clave = 3; // Clave para el cifrado (puede ser cualquier número)

    std::string mensajeEncriptado = encriptarMensaje(mensaje, clave);
    std::cout << "Mensaje encriptado: " << mensajeEncriptado << std::endl;

    std::string mensajeDesencriptado = desencriptarMensaje(mensajeEncriptado, clave);
    std::cout << "Mensaje desencriptado: " << mensajeDesencriptado << std::endl;

    return 0;
}