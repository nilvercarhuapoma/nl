#include<iostream>
#include<string>
using namespace std;
class Date{
private:
int var1;
int var2;
public:
Date(int _var1,int _var2):var1(_var1),var2(_var2){};
void mostrar(){
cout<<"var1:"<<var1<<endl;
cout<<"var2:"<<var2<<endl;
}
int getvar2(){
return var2;
}
void setvar2(int _var2){
var2=_var2;
}
};
int main(){
Date d1(5,6);
d1.setvar2(2);
d1.mostrar();
return 0;
}