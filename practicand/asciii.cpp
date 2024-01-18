#include<iostream>
#include<string>
int main() {
    std::string texto;
    std::cout << "Ingrese un mensaje: ";
    std::getline(std::cin, texto);

    int suma = 0;
    for (char caracter : texto) {
        suma += caracter; 
    }

    std::cout << "La suma de los códigos ASCII es: " << suma << std::endl;
    }