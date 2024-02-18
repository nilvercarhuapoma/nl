#include <iostream>
#include <string>
using namespace std;
class nilver
{
 private:
 string nombre;
 int age;

 public:
 nilver();
 nilver(string ,int);
 void mostrar();

};
nilver::nilver(string _nombre,int _age){
nombre=_nombre;
age=_age;

}
void nilver:: mostrar(){
cout<<"Mi nombre es"<<nombre<<" y mi edda es "<<age;

}
int main(){
setlocale(LC_ALL, "es_ES.UTF-8");
nilver Nilver1("nilver",20);
Nilver1.mostrar();

return 0;

}