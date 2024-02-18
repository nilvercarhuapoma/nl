#include <iostream>
using namespace std;
inline int suma(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int a = 2, b = 8, c = 8;
    int resultado = suma(a, b, c);
    cout << "la suma es: " << resultado;
}