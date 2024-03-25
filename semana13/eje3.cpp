#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Persona {
protected: // Los atributos deberían ser protegidos para que las clases derivadas puedan acceder a ellos
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
    int ventas=0;
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
            cin >> ventas;
            cin.ignore();
            info.push_back(add);
        }
    }
};

class Producto:public Vendedor {
private:
int id_producto;
string tipo;
string fecha;
double precio;
public:
vector<Vendedor>&info;
void venta_productos(vector<Producto>&prod){

cout<<"Las ventas registradas:"<<ventas<<endl;
for(int i=0;i<ventas;++i){
    Producto ag;
    cout<<"Ingrese el nombre del producto "<<i+1<<" :";
    getline(cin,ag.tipo);
    cout<<"Ingrese el id del producto:";
    cin>>ag.id_producto;
    cin.ignore();
    cout<<"Ingrese su precio:";
    cin>>ag.precio;
    cin.ignore();
    cout<<"Ingrese la fecha:";
    getline(cin,ag.fecha);
    prod.push_back(ag);
}
}

};

class Ventas:public Producto {
private:
int id_ventas;
public:
void datos_vnatotal(vector<ventas>&vent){
    cout<<"Cuantas ventas diferentes se hicieron:"<<id_producto<<endl;
for(int i=0;i<id_productos;i++){
Ventas age;
cout<<"Ingrese la id de venta"<<i+1<<":";
cin>>age.id_ventas;
vent.push_back(age);
}


}
void mostrar(vector<ventas>&vent){
for(int i=0;i<vent.size();++i){
cout<<"Nombre del vendedor:"<<i+1<<":"<<vent[i].nombre<<endl;
cout<<"Cantidad de productos vendidos:"<<vent[i].ventas<<endl;
for(int i=0;add.ventas;++i){
    cout<<"Nombre del producto "<<i+1<<" :"<<add.ventas[i].tipo<<endl;
    cout<<"Precio:"<<add.ventas[i].tipo<<endl;
    cout<<"Fecha:"<<add.ventas[i].fecha<<endl;
}
}
}
};





int main() {
    Vendedor v;
    vector<Vendedor> info;
    v.datos_ventas(info);
    cout<<endl;
    Producto p;
    vector<Producto>prod;
    p.venta_productos(prod);
    cout<<endl;
    Ventas v1;
    vector<Ventas>vent;
    v1.datos_vnatotal(vent);
    v1.mostrar(vent);

    return 0;
}
