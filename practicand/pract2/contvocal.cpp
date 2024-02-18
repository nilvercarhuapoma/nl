#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nombre ;
    cout<<"ingrese la oracion:";
    getline(cin,nombre);
    int vocales = 0;
    int consonantes = 0;
    while (true)
    {
        for (char caracter : nombre)
        {
            char vocal = tolower(caracter);
            if (vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u')
            {

                vocales++;
            }
            else
            {
                consonantes++;
            }
        }
        break;
    }
    cout << "El toral de vocales es:" << vocales << endl;
    cout << "El total de consonates:" << consonantes << endl;
}
