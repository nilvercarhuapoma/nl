#include <iostream>
using namespace std;
class Bird
{
public:
    virtual void fly() = 0;
    virtual void eats() = 0;
    virtual void walk() = 0;
};
class Eagle : public Bird
{
public:
    void fly() override
    {
        cout << "Si vuela" << endl;
    }
    void eats() override
    {
        cout << "si come" << endl;
    }
    void walk() override
    {
        cout << "si camina" << endl;
    }
};
class Pinguin : public Bird
{
public:
    void fly() override
    {
    }
    void eats() override
    {
        cout << "si come" << endl;
    }
    void walk() override
    {
        cout << "si camina"<<endl;
    }
};
class Ostrich : public Bird
{
public:
    void fly() override
    {
    }
    void eats() override
    {
        cout << "SI COME" << endl;
    }
    void walk() override
    {
        cout << "SI CAMINA" << endl;
    }
};
int main()
{
    cout<<"Aguila:"<<endl;
    Eagle e1;
    e1.fly();
    e1.eats();
    e1.walk();
    cout<<endl;
    cout<<"Pinguino:"<<endl;
    Pinguin p1;
    p1.fly();
    p1.eats();
    p1.walk();
    cout<<endl;
    cout<<"Avestruz:"<<endl;
    Ostrich o1;
    o1.fly();
    o1.eats();
    o1.walk();
}

