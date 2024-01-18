#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    // mostrar y selecionar numeros impares de un rango de 20 numeros
    // y su suma de ellos.
    srand(time(NULL));
    int maximo = 100, minimo = 1, sum=0;
    int v[20];
    for (size_t i = 0; i < 20; i++)
    {
        v[i] = rand() % (maximo - minimo + 1) + minimo;
        
        if (v[i] % 2== 0){
            continue;
        }
        sum += v[i];
        cout << v[i]<<" ";
        
    }
    cout << " la suma es:" << sum;

    return 0;
}