#include <iostream>
#include <vector>
using namespace std;

class Bloque
{
private:
    double base;
    double altura;
    double x;
    double y;
    double z;

public:
    Bloque(double b, double a, double _x, double _y, double _z) : base(b), altura(a), x(_x), y(_y), z(_z) {}
    ~Bloque() {}
  

    void set_posicion()
    {
        cout << "x:" << x << endl;
        cout << "Y:" << y << endl;
        cout << "Z:" << z << endl;

    }

    void set_base()
    {
        cout << "Base:" << base << endl;
    }

    double get_altura(double a)
    {
        return a;
    }

    void dibuja()
    {
        cout << "Se esta dibujando" << endl;
    }

    void set_altura(double a)
    {
        altura = a;
    }
};

class Techo
{
private:
    double base;
    double x;
    double y;
    double z;

public:
    Techo(double b, double _x, double _y, double _z) : base(b), x(_x), y(_y), z(_z) {}
    ~Techo() {}

    void dibuja()
    {
        cout << "Se esta dibujando" << endl;
    }

    void set_base()
    {
        cout << "Base:" << base << endl;
    }

    void set_posicion()
    {
        cout << "x:" << x << endl;
        cout << "Y:" << y << endl;
        cout << "Z:" << z << endl;
        

    }
};

class Casa
{
private:
    Techo techo;
    Bloque bloque;

public:
    Casa(double b, double a, double _x, double _y, double _z) : techo(b, _x, _y, _z), bloque(b, a, _x, _y, _z) {}
    ~Casa() {}
    void set_posicion()
    {
        techo.set_posicion();
        bloque.set_posicion();
    }

    void dibuja()
    {
        cout << "Dibujando el techo:" << endl;
        techo.set_posicion();
        techo.set_base();
        cout << "Dibujando el bloque:" << endl;
        bloque.set_posicion();
        bloque.set_base();
        bloque.set_altura(5);
        cout << "Casa hecha" << endl;
    }
};

class Urbanizacion
{
private:
    vector<Casa> casas;

public:
    void agregarCasa(double b, double a, double _x, double _y, double _z)
    {
        Casa casa(b, a, _x, _y, _z);
        casas.push_back(casa);
    }

    void dibuja()
    {
        for (int i = 0; i < casas.size(); ++i)
        { 
          
          casas[i].dibuja();
            
        }
    }
};
void mostrar_ubic(int row,int column){
int n[row][column];
cout<<"De cuanto sera la matriz:";
cin>>row;
cout<<"x ";
cin>>column;

for(int i=0;row<i;++i){
  for(int j=0;column<1;++j){
    cout<<"Ingrese ["<<i<<"]["<<j<<"]:";
    cin>>n[i][j];
  }

}
}
int main()
{    
    int row,column;
    mostrar_ubic(row,column);
    Urbanizacion u;
    cout<<"Casa 1"<<endl;
    u.agregarCasa(10, 5, 7, 3, 6);
    cout<<endl;
    cout<<"Casa 2"<<endl;
    u.agregarCasa(8, 4, 20, 4, 4);
    cout<<endl;
    cout<<"Casa 3"<<endl;
    u.agregarCasa(12, 6, 40, 4, 6);
    u.dibuja();
    return 0;
}
