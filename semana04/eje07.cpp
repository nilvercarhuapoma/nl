#include <iostream>
using namespace std;
int main()
{
    int contador=0;
    double sum=0;
    double numero;
    while(contador<8)
    {
    cout<<"ingrese el numero:"<<contador + 1<<" : ";
    
    cin>>numero;
    sum+=numero;
       contador++;
           
   
    }
    cout<<" la suma de los 7 numeros es:"<<sum<<endl;
    return 0;
}