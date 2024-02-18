#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Duenio
{
private:
    string nombre;
    string ocupacion;
    int edad;

public:
   Duenio(string _nombre,string _ocupacion,int _edad):nombre(_nombre),ocupacion(_ocupacion),edad(_edad){};
    void tala()
    {
        cout << "La tala fue realizada por: " << nombre<<endl;
    }
    void usuario()
    {
        cout << "Nombre del usaurio:" << nombre<<endl;
        cout << "ocupacion:" << ocupacion<<endl;
        cout << "De edad :" << edad<<endl;
    }
};
class Permisos : public Duenio
{

public:
   Permisos(string nombre,string ocupacion,int edad):Duenio(nombre,ocupacion,edad){};

    void autorizacion(string permit)
    {
        cout << "Permisos autorizados:" << permit<<endl;
    }
};
int main(){
string permit;
Permisos perm("juan","ing.Ambiental",28);
perm.autorizacion("Tala de madera legal");
perm.usuario();
perm.tala();


}