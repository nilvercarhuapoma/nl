#include<iostream>
#include<vector>
using namespace std;
class Persona{
protected:
string nombre;
int edad;
public:
Persona(string n,int e):nombre(n),edad(e){};
void mostrar();
};
void Persona::mostrar(){
cout<<"Mi nombre es "<<nombre<<endl;
cout<<" y tengo "<<edad<<" anios "<<endl;

}
class Estudiante:public Persona{
private:
int codigo;
public:
Estudiante(string nombre ,int edad,int c ):Persona(nombre,edad),codigo(c){};
void mostrar1(){
    Persona::mostrar();
    cout<<"y mi codigo es "<<codigo<<endl;
}
void estudiar(){
cout<<" y en estos momentos estoy estudiando"<<endl;

}

};
class profesor:public Estudiante{
private:
string grado_estdudio;
public:
profesor(string nombre,int edad,int codigo,string g):Estudiante(nombre,edad,codigo),grado_estdudio(g){};

void enseñar(){
     
    cout<<"y soy profesor de "<<grado_estdudio<<" ensenio a la facultadad de sistemas"<<endl;
} 

};
int main(){
    Estudiante e1("Jose",21,20240029);
    e1.mostrar1();
    e1.estudiar();
    cout<<endl;
    profesor p1("david",32,333302,"sotware");
    p1.mostrar1();
    p1.enseñar();
}