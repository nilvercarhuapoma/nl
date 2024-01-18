#include <iostream>
using namespace std;

int main() {
    char letra = 'A';
    char simbolo = '$';
    char numero = 65; // 'A' en la tabla ASCII

    cout << "Caracteres individuales:" << endl;
    cout << "Letra: " << letra << endl;
    cout << "Símbolo: " << simbolo << endl;
    cout << "Número (correspondiente a 'A' en ASCII): " << numero << endl;

    // Comparación de caracteres
    if (letra == 'A') {
        cout << "La letra es 'A'." << endl;
    } else {
        cout << "La letra no es 'A'." << endl;
    }

    // Operaciones con caracteres
    char siguienteLetra = letra + 1;
    cout << "La siguiente letra a 'A' es: " << siguienteLetra << endl;

    return 0;
}