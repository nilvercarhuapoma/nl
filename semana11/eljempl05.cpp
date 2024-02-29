#include <iostream>
#include <string>
using namespace std;
class Pila
{
private:
    int sp = 0;
    int date[10];
  
public:
    Pila(int _sp) : sp(_sp) {}
    void push(){
     cout<<"ingrese el valor:";
     
    };
    void pop(){
    cout<<"quite el valor:";
    };
    void mostar();
}

void mostar(int)
{
    cout << "El total  "<<p;
}
int main()
{    Pila p;
    int cont =0,i=0;
     for (;true;){
      if(cont==10) {
        break;
      }else if(i %2==0){
        p.push(i);
        cont ++;

      }
      ++i;
    }    
}