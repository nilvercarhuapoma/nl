#include <iostream>
#include <vector>
using namespace std;
int distancia(int t,int v ){

    return(v*t);
}
int llenar(){
    int r;
cout<<"ingrse un valor: ";
cin>>r;
return r;
}
void mostrar(int v,int t,int d){

    cout<<"la distancia es :"<<v<<"*"<<t<<"="<<d;

}
int main(){
    int v,t,d;
    v=llenar();
    t=llenar();
    d=distancia(v,t);
    mostrar(v,t,d);
    
}