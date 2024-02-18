#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct frutas
{
    string nombre;
    int unidades;
    float costo;
};
void mostrar(vector<frutas> datos)
{
    cout << &datos;
}

int main()
{
    vector<frutas> datos;
    int cant;
    cout << "cuantas tipos de frutas quiere registrar:";
    cin>>cant;
    cout<<endl;
    for (int i = 0; i < cant; ++i)
    { cin.ignore();
        frutas agregar;
        cout << "ingrese el nombre de la fruta " << i + 1 << ":";
        getline(cin, agregar.nombre);
        cout << "cuantas unidades tienes de " << agregar.nombre << ":";
        cin >> agregar.unidades;
        cin.ignore();
        cout << "cual es precio por kilo:";
        cin >> agregar.costo;
        cin.ignore();
        cout << endl;
        datos.push_back(agregar);
    }
}