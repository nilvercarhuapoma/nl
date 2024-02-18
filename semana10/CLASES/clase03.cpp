#include <iostream>
#include <string>
using namespace std;
class Perro
{
private:
    string name;
    int edad;
    string raza;

public:
    Perro(string _name, int _edad, string _raza) : name(_name), edad(_edad), raza(_raza){};

    
void mostrar()
{
    cout << "el nombre del perro es " << name << " con edad " << edad << " anios y una raza " << raza;
}
string getraza()
{
    return raza;
}
void setraza(string _raza)
{
    raza = _raza;
}
};
int main()
{
    Perro p1("bruck", 3, "chihuahua");
    p1.setraza("labarador");
    p1.mostrar();
    
}
