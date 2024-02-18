#include <iostream>
#include <string>
using namespace std;
int suma(int n,int i,int l,int v,int e,int r,int S){
n=4;
i=6;
l=7,
v=4;
e=v;
r=8;
return S=n+i+l+v+e+r;
}

int resta(int &n,int &i,int &l,int &v,int &e,int &r,int &R)
{

return R=n-i-l-v-e-r;
}
void llenar(int &n,int &i,int &l,int &v,int &e,int &r)
 {

cout<<" ingrese los numeros:";
cin>>n;
cout<<" ingrese los numeros:";
cin>>i;
cout<<" ingrese los numeros:";
cin>>l;
cout<<" ingrese los numeros:";
cin>>v;
cout<<" ingrese los numeros:";
cin>>e;
cout<<" ingrese los numeros:";
cin>>r;

}
void mostrar(int S,int &R){
cout<<" las suma por valor:"<<S<<endl;
cout<<" La resta por referencia:"<<R<<endl;


}
int main(){
int n,i,l,v,e,r;
llenar(n,i,l,v,e,r);
int S=suma(n,i,l,v,e,r,S);
int R=resta(n,i,l,v,e,r,R);
mostrar(S,R);

}