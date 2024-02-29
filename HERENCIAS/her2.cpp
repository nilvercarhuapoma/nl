#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aula
{
private:
    double nota;
    string nombre;

public:
    Aula(double n = 0, string na = "") : nota(n), nombre(na) {} // Constructor con valores por defecto

    void ingresarAlumno(vector<Aula> &info)
    {
        int n;
        cout << "¿Cuántos alumnos desea ingresar?: ";
        cin >> n;
        cin.ignore(); // Limpiar el buffer del salto de línea anterior
        for (int i = 0; i < n; ++i)
        {
            double nota;
            string nombre;
            cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
            getline(cin, nombre);
            cout << "Ingrese la nota del alumno " << i + 1 << ": ";
            cin >> nota;
            cin.ignore(); // Limpiar el buffer del salto de línea después de leer la nota
            info.push_back(Aula(nota, nombre));
        }
    }
};

void mostrar(vector<Aula> &info)
{
    cout << "Información de los alumnos ingresados:\n";
   for(int i=0;i<info.size();++i){
    cout<<"Alumnos "<<i+1<<

   }
}

int main()
{
    Aula aula;
    vector<Aula> info;
    aula.ingresarAlumno(info);
    mostrar(info);

    return 0;
}
