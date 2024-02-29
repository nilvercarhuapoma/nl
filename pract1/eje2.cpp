#include <iostream>
using namespace std;
int main()
{
    float x, y, z;
    cout << "Ingrese la primera nota:";
    cin >> x;
    cout << "Ingrese la segunda nota:";
    cin >> y;
    cout << "Ingrese la tercera nota:";
    cin >> z;
    float promedio = (x + y + z) / 3;
    cout << "El promedio del alumno es :" << promedio << endl;
    if (promedio <= 10)
    {
        cout << "[El alumno es malo]";
    }
    else if ((promedio >= 11) && (promedio <= 15))
    {
        cout << "[El alumno es regular]";
    }
    else if ((promedio >= 16) && (promedio <= 20))
    {
        cout << "[El alumno es bueno]";
    }
    return 0;
}