// 10-	Contador de vocales
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string texto;
    cout << "ingrese el texto:";
    getline(cin, texto);
    int totalvocales = 0;
    for (char caracter : texto)
    {
        char vocal = tolower(caracter);
        if (vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u')
        {
            totalvocales++;
        }
    }
    cout << "el total de vocales en el texto es:" << totalvocales;
    return 0;
}