#include <iostream>
using namespace std;
class Biblioteca
{
private:
    string sala;
    string encargado;

public:
    Biblioteca(string s, string e) : sala(s), encargado(e) {}
    void mostrar()
    {
        cout << "SALA DE:" << sala << endl;
        cout << "ENCARGADO:" << encargado << endl;
    }
};
class Libros : public Biblioteca
{
private:
    string acceso;

public:
    Libros(string sala, string encargado, string a) : Biblioteca(sala, encargado), acceso(a) {}
    void mostrar()
    {
        Biblioteca::mostrar();
        cout << "ACCESO A:" << acceso << endl;
    }
};
class Revistas : public Libros
{
private:
    string tipo;

public:
    Revistas(string sala, string encargado, string acceso, string T) : Libros(sala, encargado, acceso), tipo(T) {}
    void mostrar()
    {
        Libros::mostrar();
        cout << "TEXTO:" << tipo << endl;
    }
};
class Periodicos : public Revistas
{
private:
    string secciones;

public:
    Periodicos(string sala, string encargado, string acceso, string tipo, string sec) : Revistas(sala, encargado, acceso, tipo), secciones(sec) {}
    void mostrar()
    {
        Revistas::mostrar();
        cout << "SECCIONES:" << secciones << endl;
    }
};
int main()
{
    Libros l1("libros", "Manuel Mago", "Estudiantes,otros");
    l1.mostrar();
    cout << endl;
    Revistas r1("Revistas", "Jose Panduro", "estudiantes,otros", "investigacion,Reportaje");
    r1.mostrar();
    cout << endl;
    Periodicos p1("Periodicos", "Antonio Fidel", "Estudiantes,otros", "Informativo", "Noticias");
    p1.mostrar();
}