#include <iostream>
#include <string>
using namespace std;
class Silla
{
private:
    string material;
    string diseño;
    double resistencia;

public:
    Silla(string, string, double);
    void mostrar();
    void llenar();
};
Silla::Silla(string material, string diseño, double resistencia)
{
    this->material = material;
    this->diseño = diseño;
    this->resistencia = resistencia;
}

void Silla::mostrar()
{
    cout << "Esta silla esta hecha de " << material << " con diseño " << diseño << " con una resisitencia " << resistencia << endl;
}
int main()
{
    Silla p1("plastico", "modelchair3", 200);
    p1.mostrar();
    return 0;
}