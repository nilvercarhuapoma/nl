#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tienda{
private:
    double precio;
    string nombre;
public:
    Tienda() {} // Constructor por defecto

    void registro(vector<Tienda> &date){
        int n;
        cout << "¿Cuántas cosas desea registrar?: ";
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; ++i){
            Tienda dad; // Crear un objeto Tienda dentro del bucle
            cout << "Ingrese el nombre de la cosa " << i + 1 << " :";
            getline(cin, dad.nombre);
            cout << "Ingrese el precio del " << dad.nombre << " :";
            cin >> dad.precio;
            cin.ignore();
            date.push_back(dad);
        }
    }

    void vender(vector<Tienda> &date){
        cout<<endl;
        cout << "Productos en la tienda:\n";
        for(int i = 0; i < date.size(); ++i){
            cout << "Producto " << i + 1 << ": " << date[i].nombre << ", Precio: " << date[i].precio << endl;
        }
    }
};

int main(){
    Tienda t1;
    vector<Tienda> date;
    t1.registro(date);
    t1.vender(date);
    return 0;
}
