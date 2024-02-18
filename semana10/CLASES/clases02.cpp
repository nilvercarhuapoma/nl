#include <iostream>
#include <string>
using namespace std;
class Gato
{
private:
    string nombre;
    double peso;

public:
    Gato(string _nombre, double _peso) : nombre(_nombre), peso(_peso){};

    void aullar(string aullar)
    {

        cout << "el gato dice" << aullar << endl;
    }
    void comer(string comer)
    {

        cout << "el gato come " << comer << endl;
    }
    void mostrar()
    {
        cout << "El gato se llama  " << nombre << "  con un peso de " << peso << endl;
    }
    void dormir(double dormir)
    {

        cout << "Duerme al " << dormir << " am" << endl;
    }
};
int main()
{
    Gato g1("Garfiel", 1.5);
    g1.mostrar();
    g1.aullar("Miauuuu");
    g1.comer("ratas");
    g1.dormir(8.00);
}