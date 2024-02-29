#include<iostream>
#include<string>
using namespace std;

class Punto {
private:
    int x, y;

public:
    Punto(int _x, int _y) : x(_x), y(_y) {}

    void mostrar() {
        cout << "x: " << x << " y: " << y << endl;
    }

    int get_x(){ // Cambiado de set_x a get_x y añadido const
        return x;
    }

    int get_y() { // Cambiado de set_y a get_y y añadido const
        return y;
    }

    void set_x(int _x) { // Modificado el nombre de la función y eliminado el return
        x = _x;
    }

    void set_y(int _y) { 
        y = _y;
    }
};

void modificar(Punto x) { 
    x.set_x(100);
    x.set_y(200);
}

void modificarreferencia(Punto& x) {
    x.set_x(100);
    x.set_y(200);
}

int main() {
    Punto p1(4, 6);
    p1.mostrar();
    modificarreferencia(p1); // Debes pasar p1 a la función
    p1.mostrar();

    return 0;
}
