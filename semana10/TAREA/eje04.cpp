#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Figuras_math
{
private:
    string nombre;
    int lados;

public:
    Figuras_math(string _nombre, int _lados) : nombre(_nombre), lados(_lados) {}
    
    void mostrar()
    {
        cout << "Nombre de la figura: " << nombre << endl;
        cout << "Numero de lados: " << lados << endl;
    }
};
class Rectangulo : public Figuras_math
{
private:
    double altura;
    double ancho;

public:
    Rectangulo(string nombre, int lados, double _altura, double _ancho) : Figuras_math(nombre, lados), altura(_altura), ancho(_ancho) {}

    void mostrar()
    {
        Figuras_math::mostrar();
    }
    double Perimetro1()
    {
        return 2 * (altura + ancho);
    }
};
class Triangulo : public Figuras_math
{
    double a;
    double b;
    double c;

public:
    Triangulo(string nombre, int lados, double _a, double _b, double _c) : Figuras_math(nombre, lados), a(_a), b(_b), c(_c) {}
    void mostrar()
    {
        Figuras_math::mostrar();
    }
    double Perimetro2()
    {
        return a + b + c;
    }
};
int main()
{
    Rectangulo r1("rectangulo", 4, 8, 7.5);
    r1.mostrar();
    cout << "Perimetro del rectangulo es :" << r1.Perimetro1() << endl;
    cout << endl;
    Triangulo t1("triangulo", 3, 9, 8.5, 6.5);
    t1.mostrar();
    cout << "El perimetro del triangulo es :" << t1.Perimetro2();
}