#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
    int inicio = 0, fin = 0;
    cout << "ingrese el incio del rango:";
    cin >> inicio;
    cout << "ingrrse el fin del rsngo:";
    cin >> fin;
    int contador = 0;
    for (int i = inicio; i <= fin; ++i)
    {
        bool primo = true;
        if (i <= 1)
        {
            primo = false;
        }
        else
        {
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    primo = false;
                    break;
                }
            }
        }
        if (primo)
        {
            cout << i << " ";
            contador++;
        }
    }
    cout << "la suma de los numeros primos:" << contador;
    return 0;
}