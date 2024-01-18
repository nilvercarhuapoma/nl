// 3-	Matriz Transpuesta:
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n, m;
    int numeros[100][100];
    cout<<"ingrese el numero de filas:";
    cin>>n;
    cout<<"ingrse el numero de columnas:";
    cin>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "ingrese un numero:[" << i << "][" << j << "]:";
            cin >> numeros[i][j];
        }
    }
    cout << "matriz inicial:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << numeros[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "matriz transpuesta:\n";
    for (int i = 0; i<m; i++){
        for (int j = 0; j < n; j++)
        {
            cout << numeros[j][i] << " ";
        }
        cout << "\n";
    }

    
    return 0;
}