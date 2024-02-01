#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void porvalor(int a,int b){
cout<<"el valor de a:"<<a<<" el valor de b:"<<b<<endl;
}
void porreferencia(int &a,int &b){
a*=b;
b+=a;
} 
void mostrar(int &a,int &b){
cout<<"el valo de a:"<<a<<" y el de b:"<<b<<endl;
}

int main(){
int a=5;
int b=10;
porvalor(a,b);
porreferencia(a,b);
mostrar(a,b);


}