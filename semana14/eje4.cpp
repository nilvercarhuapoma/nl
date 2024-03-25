#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    Bloque() {}
    ~Bloque() {}

    void set_posicion()
    {

        cout << "x:";
        cin >> x;
        cout << "Y:";
        cin >> y;
        cout << "Z:";
        cin >> z;
    }

    void set_base()
    {
        cout << "Bloque:" << endl;

        cout << "Base:";
        cin >> base;
    }

    double get_altura() const
    {
        return altura;
    }

    void dibuja()
    {
        cout << "Se está dibujando" << endl;
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
    Techo() {}
    ~Techo() {}

    void dibuja()
    {
        cout << "Se está dibujando" << endl;
    }

    void set_base()
    {
        cout << "Techo:" << endl;
        cout << "Base:";
        cin >> base;
    }

    void set_posicion()
    {
        cout << "x:";
        cin >> x;
        cout << "Y:";
        cin >> y;
        cout << "Z:";
        cin >> z;
        cout << endl;
    }
};

class Casa
{
private:
    int id;
    string propietario;
    Techo techo;
    Bloque bloque;

public:
    Casa(int _id, const string &_propietario, double b, double a, double _x, double _y, double _z) : id(_id), propietario(_propietario), techo(), bloque()
    {
        techo.set_base();
        techo.set_posicion();
        bloque.set_base();
        bloque.set_posicion();
    }

    ~Casa() {}

    int get_id() const
    {
        return id;
    }

    const string &get_propietario() const
    {
        return propietario;
    }
};

class Urbanizacion
{
private:
    vector<Casa> casas;

public:
    void agregarCasa(int _id, const string &_propietario)
    {
        Casa casa(_id, _propietario, 0, 0, 0, 0, 0);
        casas.push_back(casa);
    }

    void dibuja()
    {
        for (int i = 0; i < casas.size(); ++i)
        {
            cout << "Casa " << i + 1 << ": Propietario - " << casas[i].get_propietario() << ", ID - " << casas[i].get_id() << endl;
        }
    }

    void distribuirCasasEnMatriz(int filas, int columnas)
    {

        vector<vector<Casa *>> matriz(filas, vector<Casa *>(columnas, nullptr));
        srand(time(0));

        for (int i = 0; i < casas.size(); ++i)
        {
            int filaAleatoria = rand() % filas;
            int columnaAleatoria = rand() % columnas;

            while (matriz[filaAleatoria][columnaAleatoria] != nullptr)
            {
                filaAleatoria = rand() % filas;
                columnaAleatoria = rand() % columnas;
            }
            matriz[filaAleatoria][columnaAleatoria] = &casas[i];
        }

        cout << "Matriz de distribucion de casas:" << endl;
        for (int i = 0; i < filas; ++i)
        {
            for (int j = 0; j < columnas; ++j)
            {
                if (matriz[i][j] != nullptr)
                {
                    cout << matriz[i][j]->get_id() << " (" << matriz[i][j]->get_propietario() << ") ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int numCasas;
    cout << "Ingrese el numero de casas que desea agregar: ";
    cin >> numCasas;

    Urbanizacion u;

    for (int i = 0; i < numCasas; ++i)
    {
        int id;
        string propietario;
        cout << "Ingrese los datos para la casa " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Propietario: ";
        cin.ignore();
        getline(cin, propietario);
        u.agregarCasa(id, propietario);
        cout << endl;
    }

    u.dibuja();

    int filas, columnas;
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> columnas;

    u.distribuirCasasEnMatriz(filas, columnas);

    return 0;
}
