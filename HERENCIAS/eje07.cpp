#include<iostream>
#include<vector>
using namespace std;

class Ropa{
protected:
    string marca;
    string tela;
public:
    Ropa() {}

    // Constructor with parameters
    Ropa(string _marca, string _tela) : marca(_marca), tela(_tela) {}
};

class Ropa_ninos: public Ropa {
private:
    string modelo;
    int tallas[5];
public:
    void registrarropaninños(vector<Ropa_ninos>& date) {
        int n;
        cout << "Cuantas tipos de ropa se registraran:";
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; ++i) {
            Ropa_ninos add;

            cout << "Ingrese el modelo"<<i+1<<":";
            getline(cin, add.modelo);
            cout << "Ingrese la marca:";
            getline(cin, add.marca); // Accessing base class member
            cout << "Ingrese la tela:";
            getline(cin, add.tela); // Accessing base class member
            for (int j = 0; j < 5; ++j) {
                cout << "Ingrese la talla " << j+1 << ": ";
                cin >> add.tallas[j];
            }
            cin.ignore();
            date.push_back(add);
        }
    }

    void mostrar(const vector<Ropa_ninos>& date) {
        for(size_t i = 0; i < date.size(); ++i) {
            cout << "Modelo " << i+1 << ": " << date[i].modelo << endl;
            cout << "Marca: " << date[i].marca << endl; // Accessing base class member
            cout << "Tela: " << date[i].tela << endl; // Accessing base class member
            cout << "Tallas Disponibles: ";
            for (int j = 0; j < 5; ++j) {
                cout << date[i].tallas[j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Ropa_ninos ropa;
    vector<Ropa_ninos> date;
    ropa.registrarropaninños(date);
    ropa.mostrar(date);
    return 0;
}
