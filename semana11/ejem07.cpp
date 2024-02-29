#include <iostream>
#include <string>
using namespace std;

class Var {
private:
    int value1;
    int value2;

public:
    Var(int _value1, int _value2) : value1(_value1), value2(_value2) {}

    void mostrar() {
        cout << "El valor de value1 es " << value1 << " y value2 es " << value2 << endl;
    }

    int suma() {
        return value1 + value2;
    }

    int getvalue2() {
        return value2;
    }

    void setvalue2(int _value2) {
        value2 = _value2;
    }
};

int main() {
    Var v1(3, 6);
    v1.mostrar();
    cout << "La suma de value1 y value2 es: " << v1.suma() << endl;
    v1.setvalue2(8);
    

    return 0;
}
