#include <iostream>
#include <string>
using namespace std;

class Aula; // Forward declaration

class Lab {
private:
    string element;
    string encargado;
    int cant_personas;

public:
    Lab(const string& elem, const string& enc, int cant) : element(elem), encargado(enc), cant_personas(cant) {}

    void implemento();
    friend class Aula; // Declaring Aula as a friend class
};

class Aula {
public:
    void mostrarElemento(Lab& l) {
        cout << "Elementos en el aula: " << l.element << endl;
        cout << "Encargado del aula: " << l.encargado << endl;
        cout << "Cantidad de personas en el aula: " << l.cant_personas << endl;
    }
};

void Lab::implemento() {
    cout << "Elementos implementados: " << element << endl;
    cout << "Encargado de estos elementos: " << encargado << endl;
    cout << "Numero total de personas: " << cant_personas << endl;
}

int main() {
    Lab l1("laptops", "jose manuel", 12);
    l1.implemento();

    Aula aula;
    aula.mostrarElemento(l1);

    return 0;
}
