#include <iostream>
using namespace std;
class pet
{
private:
    string name;

public:
    pet(string a) : name(a) {}
    void run()
    {
        cout << "Corriendo!!!\n";
    }
};
class cat : public pet
{
public:
    cat(string n) : pet(n) {}
    void soundMio()
    {
        cout << "miauuu\n";
    }
};
class dog : public pet
{
public:
    dog(string n) : pet(n) {}
    void soundMio()
    {
        cout << "Wauuuu\n";
    }
};
int main()
{
    pet *a = new cat("cat1");
    pet *b = new dog("dog1");
    a->run();
    static_cast<cat *>(a)->soundMio();
    b->run();
    static_cast<dog *>(b)->soundMio();
}
