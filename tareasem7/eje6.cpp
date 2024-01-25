#include <iostream>
#include <vector>
#include<string>
using namespace std;
void nombre(string &n,string &N){

cout<<"ingrese el nombre que desea cambiar:";
getline(cin,n);
N=n;
}

void llenar (string &n){
cout<<"ingrese su nombre completo:";
getline(cin,n);

}
void mostrar(string n,string N){
cout<<"\nsu nombre cambiado es:"<< n <<endl;
cout<<"y desde ahora se llamara:"<< N <<endl;

}
int main(){

string N;
string n;
llenar(n);
nombre(n,N);
mostrar(n,N);
return 0;
}