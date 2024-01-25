//*Diseña una función llamada sumaYResta que tome tres números como parámetros (a, b y c) y
// actualice los valores de a y b sumando y restando el valor de c, respectivamente

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void sumayresta(int &a, int &b, int c)
{
    a += c;
    b -= c;
}

void llenar(int &a, int &b, int &c)
{
    cout << " su primer numero:";
    cin >> a;
    cout << " su segundo numero:";
    cin >> b;
    cout << " su tercer  numero:";
    cin >> c;
}
void mostra(int a, int b)
{

    cout << "El resultado modificado es: a = " << a << ", b = " << b << endl;
}

int main()
{
    int n1, n2, n3;
    llenar(n1, n2, n3);

    cout << "Valores originales: a = " << n1 << ", b = " << n2 << endl;

    sumayresta(n1, n2, n3);

    mostra(n1, n2);
}