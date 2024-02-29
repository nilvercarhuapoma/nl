#include<iostream>
#include<string>
using namespace std;
class Lab;
class Aula{

private:
string element;
string encargado;
int cant_pesonas;
public:
friend class Lab;
};
class Lab{
public:
void implemento(){
cout<<"elementos implementados:"<<i.element;
cout<<"Encargado de estos elementos:"<<i.encargado;
cout<<"Numero total de personas:"<<i.cant_pesonas;
}
};
int main(){
Lab l1("laptos","jose manuel",12);
l1.implemento();

}