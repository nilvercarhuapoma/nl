#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct libro
{
    string titulo;
    string autor;
    int publicaion;
};
int main()
{
    int n;
    cout << "ingrese la cantidad de libros:";
    cin >> n;
    vector<libro> Libreria;
    for (int i = 0; i < n; ++i)
    {    
        libro nuevolibro;
        cout << "ingrese el titulo del libro " << i +1<<":";
        cin.ignore();
        getline(cin,nuevolibro.titulo);

        cout << "ingrese el nombre del autor " << i+1<<":";
        getline(cin,nuevolibro.autor);

        cout << "ingrese el anio de publicaion " << i+1<<":";
        cin >>nuevolibro.publicaion;
        
        Libreria.push_back(nuevolibro);
    }
    for (int i = 0; i < n; ++i)
        {
            cout << "\ntitulo:" << Libreria[i].titulo;
            cout << "\nautor:" << Libreria[i].autor ;
            cout << "\nanio de publicaion:" << Libreria[i].publicaion<<endl;
        }
    
}
