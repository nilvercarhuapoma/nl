#include <iostream>
#include <string>
using namespace std;
class Personaje
{
private:
    string nombre;
    int salud;

public:
    Personaje(string _nombre, int _salud) : nombre(_nombre), salud(_salud){};
    void mostrar()
    {
        cout << "Nombre:" << nombre << endl;
        cout << "salud:" << salud << "%" << endl;
    }
};
class Mago : public Personaje
{
public:
    Mago(string nombre, int salud) : Personaje(nombre, salud){};
    void mostrar1(string habilidad)
    {

        cout << "Habilidad:" << habilidad << endl;
    }
};
class Guerrero : public Personaje
{
public:
    Guerrero(string nombre, int salud) : Personaje(nombre, salud){};
    void mostrar1(string habilidad)
    {
        cout << "Habilidad:" << habilidad << endl;
    }
};
class Arquero : public Personaje
{
public:
    Arquero(string nombre, int salud) : Personaje(nombre, salud){};
    void mostrar1(string habilidad)
    {

        cout << "Habilidad:" << habilidad << endl;
    }
};
int main()
{
    cout << ".......MAGO......." << endl;
    Mago m1("Juan", 168);
    m1.mostrar();
    m1.mostrar1("tormenta");
    cout << "......GUERRERO......." << endl;
    Guerrero g1("Manuel", 260);
    g1.mostrar();
    g1.mostrar1("Rayos");
    cout << "......ARQUERO......" << endl;
    Arquero a1("Nilver", 168);
    a1.mostrar();
    a1.mostrar1("Laser");
    return 0;
}