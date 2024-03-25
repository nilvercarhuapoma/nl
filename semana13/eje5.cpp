#include <iostream>
#include <vector>
using namespace std;
class Persona
{
private:
    string identificador;
    string apellidos;
    string nombres;
    string direcction;
    string tipo_contacto[3];

public:
    Persona() {}
    void mostrar()
    {
        cout << "identificador:" << identificador << endl;
        cout << "Apellidos:" << apellidos << endl;
        cout << "Nombres:" << nombres << endl;
        cout << "Contacto 1:" << tipo_contacto[1] << endl;
        cout << "Contacto 2:" << tipo_contacto[2] << endl;
        cout << "Contacto 3:" << tipo_contacto[3] << endl;
    }
};
class Empleado : public Persona
{
private:
    int codigo;
    double costo_hh;
    string departamento[2];
    double salario;

public:
    Empleado() {}
    Empleado(Persona()) {}
    void mostrar()
    {

        double calculara_sal = 0;
        cout << "Codigo:" << codigo << endl;
        ;
        cout << "Costo:" << costo_hh << endl;
        cout << "Departamento:" << departamento << endl;
        cout << "codigo_ded:" << departamento[1] << endl;
        cout << "nombre_dep:" << departamento[2] << endl;
        cout << "Salario:" << salario;
    }
};
class Gerente : public Empleado
{
private:
    double bono;

public:
    Gerente(Empleado()) {}
  virtual  void calcular_salario()=0;
  void mostrar()
    {
        cout << "Salario:" <<salario<< endl;
    }
};
class Inginiero:public Empleado{
    private:
    float horas_extras;
    public:
    Inginiero(){}
    Inginiero(Empleado()){}
    void mostar(){
        cout<<"Horas extras:"<<horas_extras<<endl;

    }
    void carcular_salario(){
cout<<10;
    }
};
int main(){
Empleado p1();


}
