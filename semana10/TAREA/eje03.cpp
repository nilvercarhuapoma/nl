#include <iostream>
#include <string>
using namespace std;
class Heroe
{
private:
    string nombre;
    int edad;
    double estatura;

public:
    Heroe(string _nombre, int _edad, double _estatura) : nombre(_nombre), edad(_edad), estatura(_estatura){};
    virtual void abilidad() = 0;
    virtual void mostrar()
    {
        cout << "ME PRESENTO:" << endl;
        cout << "Mi nombre es " << nombre << endl;
        cout << " y tengo " << edad << " anios, con una " << endl;
        cout << " estatura de " << estatura << " metros" << endl;
        cout << " y poseo una abilidad de ";
        abilidad();
        cout << " " << endl;
    }
};
class Hombre : public Heroe
{
public:
    Hombre(string nombre, int edad, double estatura) : Heroe(nombre, edad, estatura){};
    virtual void abilidad()
    {
        cout << "tela de arania." << endl;
    }
    void salvar()
    {

        string mision = "Los humanos en peligro";
        cout << "salvo a " << mision << endl;
    }
    void Descansar()
    {

        string descanso = "mision esta completa";
        cout << "mis horas de descanso son cuando la " << descanso << endl;
    }
};
int main()
{
    Hombre h1("spiderman", 25, 1.58);
    h1.mostrar();
    cout << "SALVAR:" << endl;
    h1.salvar();
    cout << "DESCANSAR:" << endl;
    h1.Descansar();
    return 0;
}
