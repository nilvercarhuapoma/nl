#include<iostream>
#include<string>
using namespace std;
class nombre{
private:
string name;
public:
nombre(string _name):name(_name){};
virtual void mostrar(){}

};
class apellido:public nombre{
private:
string spell;
public:
apellido(string name,string _spell):nombre(name),spell(_spell){}

};