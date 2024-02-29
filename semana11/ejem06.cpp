#include <iostream>
#include <string>
using namespace std;
class Persona
{
private:
    string nombre;

public:
    Persona(string _nombre) : nombre(_nombre) {}
    Persona();
    void mostar()
    {
        cout << "NOMBRE:" << nombre << endl;
    }
};
class Administrativo : public Persona
{
private:
    string area;

public:
    Administrativo(string nombre, string _area) : Persona(nombre), area(_area) {}
    void info();
    void consultar()
    {
        Persona::mostar();
        cout << "Oficio:" << area << endl;
    }
};

int main()
{
    Administrativo a1("jose", "mecanico");
    a1.consultar();

}