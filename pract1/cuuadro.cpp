#include <iostream>
#include <string>

using namespace std;

// Definición de la clase InfoBox
class InfoBox {
private:
    string title;
    string content;
public:
    InfoBox(string t, string c) : title(t), content(c) {}

    void display() {
        cout << "---------------------" << endl;
        cout << "| " << title << endl;
        cout << "---------------------" << endl;
        cout << content << endl;
        cout << "---------------------" << endl;
    }
};

int main() {
    // Crear un objeto InfoBox
    InfoBox myInfo("Información Importante", "Esto es un ejemplo de un cuadro de información en C++.");

    // Mostrar el cuadro de información
    myInfo.display();

    return 0;
}
