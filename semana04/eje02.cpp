#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"ingrese un numero:";
    cin>>a;
    cout<<"ingrese otro numero:";
    cin>>b;
    if(a<b){
        cout<<a<<" "<< "es menor que :"<<b<<endl;
    }else{
        cout<<a<<" "<< "es mayor que:"<<b;
    }
    return 0;
}