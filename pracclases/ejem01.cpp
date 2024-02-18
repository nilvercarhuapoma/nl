#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Madera
{
private:
    string nombre;
    string ubicacion;
    double tamanio;

public:
    Madera(string _nombre, string _ubicacion, int _tamanio) : nombre(_nombre), ubicacion(_ubicacion), tamanio(_tamanio) {}
    void crecer( )
    {double nuevo_tamanio;
        cout << "Ingrese el nuevo tamanio de la madera: ";
        cin >> nuevo_tamanio;
        tamanio = nuevo_tamanio;
        cout << "Tamanio actualizado: " << tamanio << endl;
    }
    void registrar_madera()
    {

        vector<Madera> information;
        cout << "CUANTOS TIPOS DE MADERA DESEA REGISTRAR" << endl;
        int cant;
        cin>>cant;
        cin.ignore();
        for (int i = 0; i < cant; ++i)
        {
           
            cout << "Ingrese su madera " << i + 1<<" :";
            getline(cin, nombre);
            cout << "Ingrese la ubicacion:";
            getline(cin,ubicacion);
            Madera new_madera(nombre,ubicacion,0.0);
            information.push_back(new_madera);

        }
    }
};
int main()
{ 
    Madera m1("Pino","Amazonas",12.0);
     m1.crecer();
     m1.registrar_madera();
    return 0;
}