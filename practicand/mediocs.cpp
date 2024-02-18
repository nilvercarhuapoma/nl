#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Alumno
{
    string nombre;
    float nota;
    int edad;
    string facultad;
};

int main()
{
    vector<Alumno> datos;
    int x;
    cout << " cuantos alumnos desea ingresar:";
    cin >> x;
    cin.ignore();
    for (int i = 0; i < x; ++i)
    {
        Alumno agregar;
        cout << "ingrese el nombre del alumno " << i + 1 << ":";
        getline(cin, agregar.nombre);
        cout<<"nota:";
        cin >> agregar.nota;
        cin.ignore();
        cout << "edad:";
        cin >> agregar.edad;
        cin.ignore();
        cout << "facultad:";
        getline(cin, agregar.facultad);
        cout << "\n";
        datos.push_back(agregar);
        
        if (agregar.facultad == "FIIS")
        {
            cout << " los alumnos:" << agregar.nombre<< " pertenecen a esta facultad:" << agregar.facultad;
        }
    }

return 0;
}