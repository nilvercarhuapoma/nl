#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct Tala{
int id_arbol;
int fecha_de_corte;
string destino;
string id_encargado;

};
int main(){
vector<Tala>info_tala;
int cant_tala;
cout<<"CUANTOS ARBOLES SE TALO:";
cin>>cant_tala;
ofstream talar("Tala.txt");
if(talar.is_open()){
cout<<"             REGISTRELOS:"<<endl;
for(int i=0;i<cant_tala;++i){
Tala add_tala;
cin.ignore();
cout<<"Ingrese el id de la madera "<<i+1<<" :";
cin>>add_tala.id_arbol;
cout<<"Ingrese la fecha de corte:";
cin>>add_tala.fecha_de_corte;
cin.ignore();
cout<<"Destino de la madera:";
getline(cin,add_tala.destino);
cout<<"Id del Encargado:";
cin>>add_tala.id_encargado;
cin.ignore();
cout<<"\n";
info_tala.push_back(add_tala);
}
for(const Tala &tal1:info_tala ){
cout<<"....................................."<<endl;
talar<<"ID de la madera:"<<tal1.id_arbol<<endl;
talar<<"Fecha de corte:"<<tal1.fecha_de_corte<<endl;
talar<<"Destino de la madera:"<<tal1.destino<<endl;
talar<<"ID del encargado:"<<tal1.id_encargado<<endl;

}
talar.close();
cout<<"Datos guardados"<<endl;
}
}