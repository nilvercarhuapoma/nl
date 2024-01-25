#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int row = 2, column = 2;
    int n[row][column];
    int m[row][column];

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << "Ingrese sus filas " << i << " y tus columnas " << j << " es: ";
            cin >> n[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << "Ingrese sus filas " << i << " y tus columnas " << j << " es: ";
            cin >> m[i][j];
        }
    }
   
    cout<<"\n";
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {

            cout << n[i][j] << " ";
            
        }
                 
         if (i == row/2)
    {
        cout << "\n + ";
    }
    else
    {
        cout << "   ";
    }
         cout<<" \n";
        
    }
         
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {

            cout << m[i][j] << " ";
        }
        
        cout<<"\n";
        
    }
       
    cout<<endl;
    int suma[row][column];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; j++)
        {
            suma[i][j]= n[i][j] + m[i][j];
            cout << suma[i][j] << " ";
        }
        cout<<"\n";
    }
     return 0;
}