#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "ingresa el primer numero:";
    cin >> x;
    cout << "ingrese el segundo numero:";
    cin >> y;
    if (x > y)
    {
        cout << x << " es mayor";
    }
    else
    {
        cout << y << " es el mayor";
    }
}