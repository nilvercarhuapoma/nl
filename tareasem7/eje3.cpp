#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int suma(int n, int s)
{
    if (n % 2 == 0)
    {
        return s + n;
    }
    return s;
}
int llenar()
{
    vector<int> numero;
    int cantidad;
    cout << "ingrese una cantidad de numeros:";
    cin >> cantidad;
    for (int i = 0; i < cantidad; ++i)
    {
        int n;
        cout << "ingrese el numero " << i + 1 << ":";
        cin >> n;
        if (n % 2 == 0)
        {

            numero.push_back(n);
        }
    }
    int resultado = 0;
    for (int n : numero)
    {
        resultado = suma(n, resultado);
        
    }
    return resultado;
}
void mostrar(int s)
{

    cout << " la suma de los numeros pares es:" << s;
}
int main()
{
    int s = llenar();
    mostrar(s);
}