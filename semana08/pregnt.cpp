#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nombre = "Nilver";
    int totalvocales = 0;
    int consonantes = 0;
    while(true){
        for (char caracter : nombre)
        {
            char vocal = tolower(caracter);
            if (vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u')
            {
                totalvocales++;
            }
            else
            {

                consonantes++;
            }
        }
        break;
    }
    cout << "Total de vocales:" << totalvocales << endl;
    cout << "Total de consonates:" << consonantes << endl;

    return 0;
}
