#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;

// Todos los datos del usuario
struct Usuario {
    string nombre;
    int edad;
    int DNI;
    int telefono;
    string correo;
    string nombre_parcela;
};

// Datos respecto a su origen y coordenadas
struct Zona {
    string tipo;
    string punto_central;
    string punto_cauce;
    double metros_madera;
};

struct Origen {
    string Departamento;
    string Provincia;
    string Distrito;
    string ubicacion_georeferenciada;
    Zona zona_dph;
    Zona zona_policial;
};

// Datos importantes de la madera
struct Madera {
    string nombre_M;
    string trabajo;
    int cantidad;
    double tamaño_parcela;
};

// Datos de la tala a realizar
struct Tala : public Madera {
    int id_arbol;
    int numero_arbol;
    double densidad;
    double superficie_cortar;
    string fecha_de_corte;
};

// Destino de la madera que se taló
struct Destino : public Usuario {
    string lugar;
    string fechaHorasalida;
    string destinofinal;
    string nombreConductor;
    string dniConductor;
    string placaVehiculo;
    double venta;
    string otros;
    string observacion;
    string cantidad;
};

// Datos del representante y el respectivo permiso
struct Representante {
    string nombre_repte;
    string dni;
};

struct Permiso {
    string fechaOtorgamiento;
    string fechaVencimiento;
    Representante representanteLegal;
    string documentacion_adjunta[6];
    string organizacion;
};

// Función para ingresar los datos de la zona
void ingresarZona(Zona &zona, bool es_dph) {
    cout << "Coordenadas UTM (x)(y)(HUSO)" << endl;
    cout << "Punto central:";
    getline(cin >> ws, zona.punto_central);
    cout << "Punto mas cercano al cauce:";
    getline(cin >> ws, zona.punto_cauce);

    if (es_dph) {
        cout << "M3 de madera:";
        cin >> zona.metros_madera;
        cin.ignore();
    }
}

// Función para ingresar los datos de origen
void ingresarOrigen(vector<Origen> &direcciones) {
    Origen from;
    cout << "Ingrese el departamento: ";
    getline(cin >> ws, from.Departamento);
    cout << "Ingrese la provincia: ";
    getline(cin >> ws, from.Provincia);
    cout << "Ingrese el distrito: ";
    getline(cin >> ws, from.Distrito);
    cout << "Ubicacion georeferenciada: ";
    getline(cin >> ws, from.ubicacion_georeferenciada);

    int opcion_zona;
    cout << endl;
    cout << "Seleccione la zona de actuacion:" << endl;
    cout << "[1] ZONA DE D.P.H" << endl;
    cout << "[2] ZONA POLICIAL" << endl;
    cout << "[3] Ambas" << endl;
    cout << ":";
    cin >> opcion_zona;
    cin.ignore();

    switch (opcion_zona) {
        case 1:
            from.zona_dph.tipo = "ZONA DE D.P.H";
            ingresarZona(from.zona_dph, true);
            break;
        case 2:
            from.zona_policial.tipo = "ZONA POLICIAL";
            ingresarZona(from.zona_policial, false);
            break;
        case 3:
            from.zona_dph.tipo = "ZONA DE D.P.H";
            from.zona_policial.tipo = "ZONA POLICIAL";
            cout << "Datos para la zona de D.P.H:" << endl;
            ingresarZona(from.zona_dph, true);
            cout << "Datos para la zona policial:" << endl;
            ingresarZona(from.zona_policial, false);
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
    }

    direcciones.push_back(from);
}

// Función para ingresar los datos del destino
void ingresarDestino(vector<Destino> &destino_lugar) {
    Destino destino;
    cout << "Ingrese el lugar de inicio(coordenadas UTM(x,y,huso)): ";
    getline(cin, destino.lugar);
    cout << "Ingrese la fecha y hora: ";
    getline(cin, destino.fechaHorasalida);

    cout << "Ingrese el destino final: ";
    getline(cin, destino.destinofinal);
    cout << endl;
    cout << "  Acerca del transporte" << endl;
    // Datos del transporte
    int vehiculo;
    cout << "Cuantos vehiculos se cargaran:";
    cin >> vehiculo;
    for (int i = 0; i < vehiculo; ++i) {
        cout << "Ingrese los apellidos y nombres del conductor " << i + 1 << ":";
        getline(cin, destino.nombreConductor);

        cout << "Ingrese el DNI del conductor: ";
        getline(cin, destino.dniConductor);

        cout << "Ingrese la placa del vehiculo: ";
        getline(cin, destino.placaVehiculo);
        cout << endl;
    }
    cout << "  Otros datos a ingresar" << endl;
    // Dato de venta
    cout << "Ingrese el monto de la venta: ";
    cin >> destino.venta;

    cin.ignore();
    cout << "Ingrese otros datos: ";
    getline(cin, destino.otros);

    cout << "Ingrese observaciones: ";
    getline(cin, destino.observacion);

    cout << "Ingrese la cantidad por unidad y total: ";
    getline(cin, destino.cantidad);
    destino_lugar.push_back(destino);
}

// Función para obtener la fecha actual del permiso
string obtenerFechaActual() {
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

string obtenerFechaVencimiento(int &diaslaborales) {
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    // Sumar los días laborales a la fecha actual
    int diasSumados = 0;
    while (diasSumados < diaslaborales) {
        timeinfo->tm_mday++;
        mktime(timeinfo);
        // No contar los fines de semana
        if (timeinfo->tm_wday != 0 && timeinfo->tm_wday != 6) {
            diasSumados++;
        }
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

int main() {
    vector<Usuario> datos_usuario;
    vector<Origen> direcciones;
    vector<Madera> datos_madera;
    vector<Tala> info_tala;
    vector<Destino> destino_lugar;
    vector<Permiso> acceso;

    cout << endl;
    cout << "              | SISTEMA DE VERIFICACION LEGAL DE MADERA |" << endl;
    cout << "Registrese correctamente" << endl;
    cout << endl;
    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE USUARIO |" << endl;
    cout << "  ----------------------" << endl;

    // Registro de Usuario
    Usuario user;
    cout << "Ingrese apellidos y nombres:";
    getline(cin, user.nombre);
    cout << "Ingrese su edad:";
    cin >> user.edad;
    cin.ignore();
    cout << "Ingrese su DNI:";
    cin >> user.DNI;
    cin.ignore();
    cout << "Ingrese su telefono:";
    cin >> user.telefono;
    cin.ignore();
    cout << "Ingrese su correo electronico:";
    getline(cin, user.correo);
    cout << "Ingrese el nombre de su fundo: ";
    getline(cin, user.nombre_parcela);
    cout << "\n";
    datos_usuario.push_back(user);

    // Ingreso de Origen
    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE ORIGEN   |" << endl;
    cout << "  -----------------------" << endl;

    ingresarOrigen(direcciones);

    // Registro de Madera
    cout << endl;
    cout << "  -------------------------" << endl;
    cout << "  | REGISTRO DE MADERA     |" << endl;
    cout << "  -------------------------" << endl;

    int information;
    cout << "Cuantos tipos de madera desea registrar: ";
    cin >> information;
    cin.ignore();
    for (int i = 0; i < information; ++i) {
        Madera tree;
        cout << "Ingrese el nombre del madera " << i + 1 << ": ";
        getline(cin, tree.nombre_M);
        cout << "Ingrese el tamanio del terreno (hectareas): ";
        cin >> tree.tamaño_parcela;
        cin.ignore();
        cout << "Fueron plantados por ustedes (si/no): ";
        cin >> tree.trabajo;
        cin.ignore();
        cout << "\n";
        datos_madera.push_back(tree);
    }
    cout << endl;

    // Registro de Tala
    cout << "  -------------------" << endl;
    cout << "  | REGISTRO DE TALA |" << endl;
    cout << "  -------------------" << endl;

    double suma = 0;
    int cant_tala;
    cout << "CARACTERISTICAS DE LOS ARBOLES A CORTAR" << endl;
    cout << "Cuantas variedades se cortaran: ";
    cin >> cant_tala;
    for (int i = 0; i < cant_tala; ++i) {
        Tala cut;
        cout << "Ingrese el id de la madera " << i + 1 << " :";
        cin >> cut.id_arbol;
        cin.ignore();
        cout << "Nombre de la madera:";
        getline(cin, cut.nombre_M);
        cout << "Ingrese la fecha de corte:";
        cin >> cut.fecha_de_corte;
        cin.ignore();
        cout << "Numero total de arboles:";
        cin >> cut.numero_arbol;
        cin.ignore();
        cout << "Ingrese la densidad:";
        cin >> cut.densidad;
        cin.ignore();
        cout << "Superficie a cortar (hectareas):";
        cin >> cut.superficie_cortar;
        cin.ignore();

        cout << "\n";
        info_tala.push_back(cut);
        suma += cut.superficie_cortar;
    }
    cout << endl;

    // Registro de destino
    cout << "  --------------------------------" << endl;
    cout << " | REGISTRO DEL DESTINO DE MADERA |" << endl;
    cout << "  ---------------------------------" << endl;

    Destino destino;
    ingresarDestino(destino_lugar);

    cout << endl;

    char continuar;
    do {
        int diaslaborales;
        int numDocumentos = 0;

        // Borrar los datos anteriores de acceso
        acceso.clear();

        // Incrementar el contador de documentos
        numDocumentos++;

        // Declaración de una variable de tipo Permiso
        Permiso permiso;

        // Solicitar datos al usuario

        // Obtener la fecha actual
        permiso.fechaOtorgamiento = obtenerFechaActual();
        permiso.fechaVencimiento = obtenerFechaVencimiento(diaslaborales);
        cout << "Adjunte los siguientes documentos:" << endl;

        cout << "CIF de la Entidad:";
        getline(cin, permiso.documentacion_adjunta[1]);
        cout << "Representacion que ostenta:";
        getline(cin, permiso.documentacion_adjunta[2]);
        cout << "Croquis de la zona de corta:";
        getline(cin, permiso.documentacion_adjunta[3]);
        cout << "Informe sobre los efectos nocivos para el medio:";
        getline(cin, permiso.documentacion_adjunta[4]);
        cout << "Otra documentacion:";
        getline(cin, permiso.documentacion_adjunta[5]);
        cout << "Fecha de otorgamiento: " << permiso.fechaOtorgamiento << endl;
        cout << "Ingrese los dias a trabajar: ";
        cin >> diaslaborales;
        cin.ignore();
        cout << "Fecha de vencimiento:" << permiso.fechaVencimiento << endl;
        cout << "Ingrese apellidos y nombres del/de la representante legal: ";
        getline(cin, permiso.representanteLegal.nombre_repte);
        cout << "Ingrese el DNI del representante legal: ";
        getline(cin, permiso.representanteLegal.dni);
        cout << "Organizacion con la que trabaja:";
        getline(cin, permiso.organizacion);
        acceso.push_back(permiso);

        // Preguntar al usuario si desea continuar ingresando datos
        cout << "\n¿Desea ingresar otro documento? (s/n): ";
        cin >> continuar;
        cin.ignore();

        // Guardar datos en un archivo
        ofstream archivo("sistema_de_verificacion_legal_" + to_string(numDocumentos) + ".txt");
        if (archivo.is_open()) {
            archivo << "\t\t\tSISTEMA DE VERIFICACION LEGAL" << endl;
            // Escribir los datos en el archivo...
            archivo.close();
            cout << "Datos guardados exitosamente en 'sistema_de_verificacion_legal_" << numDocumentos << ".txt'" << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    } while (continuar == 's' || continuar == 'S');

    cout << "\t\t\t\t\tGRACIAS POR SU CONFIANZA" << endl;
    return 0;
}
