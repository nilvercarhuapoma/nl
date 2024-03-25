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

void set_var(int v){
var=v;

}
};
void modificar(Pet& var){
var.set_var(10);
}
int main(){
pet p(3);
p.mostar();
modificar();
p.mostar();

}