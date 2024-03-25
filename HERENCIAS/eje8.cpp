#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Persona {
protected:
    string nombre;
    int id;
    int dni;
    string dir;
public:
    Persona() {}
    Persona(string n, int i, int d, string dr) : nombre(n), id(i), dni(d), dir(dr) {}
};

class Vendedor : public Persona {
private:
    int ventas;
public:
    void datos_ventas(vector<Vendedor>& info) {
        int n;
        cout << "Cuantas personas vendieron: ";
        cin >> n;
        cin.ignore(); 

        for (int i = 0; i < n; ++i) {
            Vendedor add;
            cout << "Ingrese el nombre del vendedor " << i + 1 << ": ";
            getline(cin, add.nombre);
            cout << "Ingrese el id: ";
            cin >> add.id;
            cout << "Ingrese el DNI: ";
            cin >> add.dni;
            cout << "Ingrese las ventas: ";
            cin >> add.ventas; // Modificado para que ingrese las ventas del vendedor
            cin.ignore();

            info.push_back(add);
        }
    }   
};



class Producto : public Vendedor {
private:
    int id_producto;
    string tipo;
    string fecha;
    double precio;
public:
    Producto(vector<Vendedor>& info) : Vendedor(info) {} // Se requiere la referencia al vector de Vendedores

    void venta_productos(vector<Producto>& prod) {
        cout << "Las ventas registradas: " << ventas << endl;
        for (int i = 0; i < ventas; ++i) {
            Producto ag;
            cout << "Ingrese el nombre del producto " << i + 1 << " :";
            getline(cin, ag.tipo);
            cout << "Ingrese el id del producto:";
            cin >> ag.id_producto;
            cin.ignore();
            cout << "Ingrese su precio:";
            cin >> ag.precio;
            cin.ignore();
            cout << "Ingrese la fecha:";
            getline(cin, ag.fecha);
            prod.push_back(ag);
        }
    }
};

int main() {
    vector<Vendedor> info_vendedores;
    vector<Producto> productos;
    Vendedor vendedor;
    Producto producto(info_vendedores);

    vendedor.datos_ventas(info_vendedores);
    producto.venta_productos(productos);

    return 0;
}
