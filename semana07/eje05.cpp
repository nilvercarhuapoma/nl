#include <iostream>
#include <vector>
using namespace std;
 int suma(int a, int b, int c, int d, int e){
       return(a+b+c+d+e);
 }
int llenar( ){
         int r;
cout<<"ingrese los numeros:";
cin>>r;
return r;

}
void mostra(int s ){

    cout<<" la suma es:"<<s;
}


int main(){
int a,b,c,d,e;
a=llenar();
b=llenar();
c=llenar();
d=llenar();
e=llenar();
int s=suma(a,b,c,d,e);
mostra(s);
}