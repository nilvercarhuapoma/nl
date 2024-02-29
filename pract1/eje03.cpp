#include <iostream>
using namespace std;
int main()
{
    double n;
    cout << "Ingrese un numero:";
    cin >> n;
    if (n < 0)
    {
        cout << "El " << n << " es negativo";
    }
    else if (n == 0)
    {
        cout << "El " << n << " es igaul a cero";
    }
    else if (n > 0)
    {
        cout << "El " << n << " es positivo";
    }
    return 0;
}