#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    cout<<"\f\f\f\f\f\ffiguras en c++";

    int i,j,filas;
    cout<<"\n\nIngrese el numero de filas de la figura= ";
    cin>>filas;
    cout<<"\n\n";

    for(i=0; i<filas; i++)
    {
        for(j=0; j<filas-i; j++)
        {
            cout<<" ";
        }
       for(j=0; j<i*2+1; j++)
       {
           cout<<"*";
       }
        cout<<"\n";   
    }
   
    getch();
    return 0;
    
}