#include <iostream>
using namespace std;
int main()
{
	int row = 3 ,column = 2;
  int filas = 2,columnas = 2;
  
  int m[row][column];
  int n[filas][columnas];
  
  for(int i = 0; i < row ; i++)
  {
  	for(int j = 0; i < column; j++)
    {
     cout << "ingrese ["<<i<<"]["<<j<<"] :";
      cin >> m[i][j];
    }
    cout<<" \n";
 }
     
  cout << endl;
  for(int i = 0; i < filas ; ++i)
  {
  	for(int j = 0; i < columnas; ++j)
    {
    	cout << "Ingrese el filas "<<i<<" y columas "<<j<<" es: ";
      cin >> n[i][j];
    }
    cout<<"\n";
  }
  int resultado[row][columnas];
  for(int i = 0; i < row ; ++i)
  {
  	for(int j = 0; j < column; ++j)
    {
    	for(int k = 0; k < columnas; ++k)
      	resultado[i][j]+=n[i][k]*m[k][j];
    }
    cout<<resultado;
  }
  
  
  
  
  
  return 0;
}









