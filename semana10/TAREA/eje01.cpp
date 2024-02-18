#include <iostream>
#include <string>
using namespace std;
class Granja
{
private:
    string dueño;
    string ambiente;
    double hora_inicio;

public:
    Granja(string _dueño, string _ambiente, double _hora_inicio) : dueño(_dueño), ambiente(_ambiente), hora_inicio(_hora_inicio){};
    void mostrar()
    {
        cout << "El DUENIO DE LA GRANJA: " << dueño << endl;
        cout << "LUGAR: " << ambiente << endl;
        cout << "INICIO A LAS: " << hora_inicio << " am" << endl;
    }
};
class Gallinas : public Granja
{
public:
    Gallinas(string dueño, string ambiente, double hora_inicio) : Granja(dueño, ambiente, hora_inicio){};

    void mostrar1(string encargado)
    {
        cout << "LAS GALLINAS" << endl;
        cout << "El encargado de la gallinas el/la estudiante:" << encargado << endl;
    }
    void Comer(int alimenta, string tipo_aliment1, string aliment2)
    {
        cout << "COMEN " << alimenta << " VECES AL DIA:" << endl;
        cout << "En la maniana:" << tipo_aliment1 << endl;
        cout << "En la tarde  :" << aliment2 << endl;
    }
    void Poner(int cant)
    {
        cout << "Ponen " << cant << " huevo al dia" << endl;
    }
};
int main()
{
    cout << ".....GRANJA...." << endl;
    Gallinas g1("Aberto Zanches Marrufo", "Facultad de Zooctenia", 8);
    g1.mostrar();
    cout << endl;
    g1.mostrar1("Zayuli Ponce Perez");
    cout << endl;
    g1.Comer(2, "Maiz molido", "valanceado");
    cout << endl;
    cout << "PONEN" << endl;
    g1.Poner(1);
}
