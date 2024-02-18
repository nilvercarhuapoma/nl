#include<iostream>
#include<string>
using namespace std;

class Character {
protected:
    string name;
    int health;
public:
    Character(string _name, int _health): name(_name), health(_health) {}
    virtual void ability() = 0; 
    virtual void mostrar() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Ability: ";
        ability();
    }
};

class Mage : public Character {
public:
    Mage(string name, int health): Character(name, health) {}
    void ability() override {
        cout << "Double shield" << endl;
    }
};

class Warrior : public Character {
public:
    Warrior(string name, int health): Character(name, health) {}
    void ability() override {
        cout << "Orion" << endl;
    }
};

class Archer : public Character {
public:
    Archer(string name, int health): Character(name, health) {}
    void ability() override {
        cout << "Laser beam" << endl;
    }
};

int main() {
    Mage m1("Jaun", 100);
    Warrior w1("Nilver", 150);
    Archer a1("Mese", 80);

    cout << "....<Mage>...." << endl;
    m1.mostrar();
    cout << endl;

    cout << "....<Warrior>...." << endl;
    w1.mostrar();
    cout << endl;

    cout << "....<Archer>...." << endl;
    a1.mostrar();
    cout << endl;

    return 0;
}
