#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura
struct Destino {
    string lugar;
    string nombrePropietario;
    string fechaHora;
    string destinofinal;
    string nombreConductor;
    string dniConductor;
    string placaVehiculo;
    double venta;
    string otros;
    string observacion;
    string cantidad; // Nueva variable para cantidad (unidad y total)
};

// Función para ingresar los datos del destino
void ingresarDestino(Destino &destino) {
    cout << "Ingrese el lugar de inicio(coordenadas UTM(x,y,huso)): ";
    getline(cin, destino.lugar);
    
    cout << "Ingrese apellidos y nombres del propietario: ";
    getline(cin, destino.nombrePropietario);

    cout << "Ingrese la fecha y hora: ";
    getline(cin, destino.fechaHora);
   
    cout << "Ingrese el destino final: ";
    getline(cin, destino.destinofinal);
  //datos del transporte 
    cout << "Ingrese el nombre del conductor: ";
    getline(cin, destino.nombreConductor);

    cout << "Ingrese el DNI del conductor: ";
    getline(cin, destino.dniConductor);

    cout << "Ingrese la placa del vehiculo: ";
    getline(cin, destino.placaVehiculo);
//dato de venta
    cout << "Ingrese el monto de la venta: ";
    cin >> destino.venta;

    cin.ignore(); 
    cout << "Ingrese otros datos: ";
    getline(cin, destino.otros);

    cout << "Ingrese observaciones: ";
    getline(cin, destino.observacion);

    cout << "Ingrese la cantidad por unidad y total: ";
    getline(cin, destino.cantidad);
}
// Función para imprimir los datos del destino
void imprimirDestino(const Destino &destino) {
    cout << "INICIO DEL DESTINO" << endl;
    cout << "Lugar: " << destino.lugar << endl;
    cout << "Nombre del propietario: " << destino.nombrePropietario << endl;
    cout << "Fecha y Hora: " << destino.fechaHora << endl;
    cout << "DESTINO FINAL" << endl;
    cout << "Lugar de llegada: " << destino.destinofinal << endl;
    cout << "Nombre del conductor: " << destino.nombreConductor << endl;
    cout << "DNI del conductor: " << destino.dniConductor << endl;
    cout << "Placa del vehiculo: " << destino.placaVehiculo << endl;
    cout << "Monto de la venta: " << destino.venta << endl;
    cout << "Otros datos: " << destino.otros << endl;
    cout << "Observaciones: " << destino.observacion << endl;
    cout << "Cantidad (unidad y total): " << destino.cantidad << endl; // Nueva variable para cantidad (unidad y total)
}

int main() {
    Destino destino;
    ingresarDestino(destino);
    imprimirDestino(destino);
    return 0;
}


