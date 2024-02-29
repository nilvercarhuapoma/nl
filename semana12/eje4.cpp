#include<iostream>
using namespace std;
class pet{
private:
int var;
public:
pet(int v):var(v){};
void mostar(){
    cout<<var;
}
void setvar(int v){
var=v;

}
};
void modificar(int p){
cout<<p;

}
int main(){
pet p(3);
p.mostar();
modificar(p);
p.mostar();

}