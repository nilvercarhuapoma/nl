#include<iostream>
using namespace std;
int main(){
int x;
cout<<"Ingrese un numero:";
cin>>x;
if(x%5==0){
    cout<<"El "<<x<<" es multiplo de 5";
}else{
    cout<<"El "<<x<<" no es multiplo de 5";
}

return 0;
}