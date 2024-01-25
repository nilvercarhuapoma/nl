#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> carateres;

    while (true)
    {
        char caracter;

        cout << "Ingrese la f para terminar.\n";
        cout << "Ingrese sus caracteres: ";
        cin >> caracter;
        if (caracter == 'f')
            break;

        carateres.push_back(caracter);
    }
    int resultado = 0;

    for (char &caracter : carateres)
    {
        resultado += static_cast<int>(caracter);
    }

    cout << "La suma de los carateres son: " << resultado << endl;
    return 0;
}