#include <iostream>
using namespace std;
class Arboles
{
    private:
    string texto;
    int cantidad;
    public:
    Arboles(string _texto, int _cantidad)
    {
        this-> texto= _texto;
        this-> cantidad= _cantidad;
    }
    string getTexto()
    {
        return texto;
    }
    int getCantidad()
    {
        return cantidad;
    }
    void mostrar();
    
};
void Arboles::mostrar(){
cout<<"los arboles son:"<<texto<<endl;


}
int main()
{

}