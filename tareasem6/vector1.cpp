#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> numeros = {0};
    cout << "Ingrese sus numeros (para terminar ponga un numero negativo): ";
    int valor;
    while(true)
    {	
      cin >> valor;
      if ( valor  < 0)
      	break;
       
      numeros.push_back(valor);
    }
    
    sort(numeros.begin(),numeros.end());
    for (size_t i = 0; i < numeros.size(); i++)
    {
    	cout << numeros[i] << " ";
    }   
    return 0;
}