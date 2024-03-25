#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Tienda {
private:
    double precio;
    string nombre;
public:
    Tienda() {} // Constructor por defecto

    void registro(vector<Tienda> &date) {
        int n;
        cout << "¿Cuántas cosas desea registrar?: ";
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; ++i) {
            Tienda dad; // Crear un objeto Tienda dentro del bucle
            cout << "Ingrese el nombre de la cosa " << i + 1 << " :";
            getline(cin, dad.nombre);
            cout << "Ingrese el precio del " << dad.nombre << " :";
            cin >> dad.precio;
            cin.ignore();
            date.push_back(dad);
        }
    }

    void vender(vector<Tienda> &date) {
        cout << endl;
        cout << "Productos en la tienda:\n";
        for(int i = 0; i < date.size(); ++i) {
            cout << "Producto " << i + 1 << ": " << date[i].nombre << ", Precio: " << date[i].precio << endl;
        }
    }

    void escribirArchivo(vector<Tienda> &date) {
        ofstream archivo("tienda.txt");
        if (archivo.is_open()) {
            for(const auto &tiend : date) {
                archivo << "Registro: " << tiend.nombre << ", Precio: " << tiend.precio << endl;
            }
            archivo.close();
            cout << "Datos guardados exitosamente en 'tienda.txt'" << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
};

int main() {
    Tienda t1;
    vector<Tienda> date;
    t1.registro(date);
    t1.vender(date);
    t1.escribirArchivo(date);
    return 0;
}
