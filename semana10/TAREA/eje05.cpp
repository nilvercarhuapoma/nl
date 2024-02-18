#include<iostream>
#include<string>
using namespace std;
class Alimentos{
private:
string nombre;
string tipo;
public:
Alimentos(string _nombre,string _tipo):nombre(_nombre),tipo(_tipo){}
virtual void micronutrientes()=0;
virtual void macronutrientes()=0;
virtual void mostrar(){
cout<<"NOMBRE:"<<nombre<<endl;
cout<<"TIPO:"<<tipo<<endl;
cout<<"MICRONUTRIENTES:";
micronutrientes();
cout<<"MACRONUTRIENTES:";
macronutrientes();
}
};
class Carne:public Alimentos{
public:
Carne(string nombre,string tipo):Alimentos(nombre,tipo){}
virtual void micronutrientes(){
cout<<"Hierro,Zinc,Selenio,Fosforo,etc."<<endl;
}
virtual void macronutrientes(){
    cout<<" Proteina,grasas y agua"<<endl;
}
void crecer(string crece){
    cout<<"ayuda a crecer "<<crece<<endl;
}

};
class Granos:public Alimentos{
public:
Granos(string nombre,string tipo):Alimentos(nombre,tipo){}
virtual void micronutrientes(){
cout<<"Vitaminas del grupo B,Minerales y Antioxidantes."<<endl;
}
virtual void macronutrientes(){
    cout<<" Carbohidratos,Proteinas y fibra"<<endl;
}
void ayudar(string ayuda){
    cout<<"Ayuda en la "<<ayuda<<endl;
}
};
int main(){
Carne c1("Rez","carne");
c1.mostrar();
c1.crecer(" los musculos y reparacion de tejidos");
cout<<endl;
Granos g1("Trigo","granos");
g1.mostrar();
g1.ayudar(" Fuente de energia y salud corporal en general");
}

