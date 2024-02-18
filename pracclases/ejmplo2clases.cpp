#include <iostream>
using namespace std;
class Pokemon
{
private:
    string nombre;
    float poder;
    int edad;

public:
    Pokemon(string _nombre float _poder, int _edad):nombre(_nombre),poder(_poder),edad(_edad){};
    void mostrar();
    void salud(int);
};
void Pokemon::mostrar()
{
    cout << "mi nombre " << nombre << " y mi poder es " << poder << " y mi edad " << endl;
}
void Pokemon::salud(int salud){
int salud=20;
cout<<"mi salud es"<<salud<<" %";
}
int main()
{
Pokemon p1("pikachu",24.5,14);
p1.mostrar();
}

