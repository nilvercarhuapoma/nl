#include <iostream>
#include <vector>
using namespace std;

struct alumno
{
    string nombre;
    int edad;
    float nota;
    vector<float> calificaciones;
};

int main()
{
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    vector<alumno> Estudiante(n);

    for (int i = 0; i < n; ++i)
    {
        
        cout << "ingrese el nombre "<<i+1<<":";
        cin >> Estudiante[i].nombre;
        cout << "ingrese su edad:";
        cin >> Estudiante[i].edad;
        cout << "ingrese la nota: ";
        cin >> Estudiante[i].nota;
    }
    for (int i = 0; i < n; ++i)
    {

        cout <<"sus datos son:\n"<<"nombre:" << Estudiante[i].nombre<<endl;
        cout <<"edad:"<<Estudiante[i].edad<<endl;
        cout <<"nota:"<< Estudiante[i].nota<<endl;
    }
    return 0;
}