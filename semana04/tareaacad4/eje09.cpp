#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
    int inicio = 0, fin = 0;
    cout << "ingrese el inicio del rango:";
    cin >> inicio;
    cout << "ingrese el fin del rango:";
    cin >> fin;
    cout << "los numeros primos son:";
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
        }
    }

    return 0;
}