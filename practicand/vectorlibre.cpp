#include <iostream>
#include <vector>

int main() {
    // Crear un vector de enteros
    std::vector<int> numeros;

    // Agregar elementos al vector
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    // Acceder a elementos por índice
    std::cout << "Elemento en la posición 1: " << numeros[1] << std::endl;

    // Mostrar todos los elementos del vector
    std::cout << "Elementos del vector:" << std::endl;
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}