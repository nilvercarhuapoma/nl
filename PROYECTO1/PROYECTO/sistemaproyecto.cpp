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

// todos los datos del usuario
struct Usuario
{
    string nombre;
    int edad;
    int DNI;
    int telefono;
    string correo;
    string nombre_parcela;
};
// datos respecto a su origen y coordenadas
struct Zona
{
    string tipo;
    string punto_central;
    string punto_cauce;
    double metros_madera;
};

struct Origen
{
    string Departamento;
    string Provincia;
    string Distrito;
    string ubicacion_georeferenciada;
    Zona zona_dph;
    Zona zona_policial;
};
// datos importantes de la madera
struct Madera
{
    string nombre_M;
    string trabajo;
    int cantidad;
    double tamaño_parcela;
};
// datos de la tala a realizar

struct Tala : public Madera
{
    int id_arbol;
    int numero_arbol;
    double densidad;
    double superficie_cortar;
    string fecha_de_corte;
    string trabajo_tala;
};
// Destino de la madera que se talo
struct Destino : public Usuario
{
    string lugar;
    string fechasalida;
    string destinofinal;
    string nombreConductor;
    int dniConductor;
    string placaVehiculo;
    int idarbol;
    double venta;
    string otros;
    string observacion;
    string cantidad;
};
// Datos del representante y el respectivo permiso
struct Representante
{
    string nombre_repte;
    string dni;
};
struct Permiso
{

    string fechaOtorgamiento;
    string fechaVencimiento;
    Representante representanteLegal;
    string documentacion_adjunta[6];
    string organizacion;
};

// Función para ingresar los datos de la zona
void ingresarZona(Zona &zona, bool es_dph)
{
    cout << "Coordenadas UTM (x)(y)(HUSO)" << endl;
    cout << "Punto central:";
    getline(cin >> ws, zona.punto_central);
    cout << "Punto mas cercano al cauce:";
    getline(cin >> ws, zona.punto_cauce);

    if (es_dph)
    {
        cout << "Metros cubicos de madera:";
        cin >> zona.metros_madera;
        cin.ignore();
    }
}

// Función para ingresar los datos de origen
void ingresarOrigen(vector<Origen> &direcciones)
{
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

    switch (opcion_zona)
    {
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
void ingresarDestino(vector<Destino> &destino_lugar)
{
    Destino destino;
    cout << "Ingrese el lugar de inicio(coordenadas UTM(x,y,huso)): ";
    getline(cin, destino.lugar);
    cout << "Ingrese la fecha de salida: ";
    getline(cin, destino.fechasalida);

    cout << "Ingrese el destino final(georeferencial): ";
    getline(cin, destino.destinofinal);
    cout << endl;
    cout << "  Acerca del transporte" << endl;
    // datos del transporte
    
        cout << "Ingrese los apellidos y nombres del conductor :";
        getline(cin, destino.nombreConductor);
        cout << "Ingrese el DNI del conductor: ";
        cin >> destino.dniConductor;
        cin.ignore();
        cout << "Ingrese la placa del vehiculo: ";
        getline(cin, destino.placaVehiculo);
        cout<<"ID de la madera a llevar:";
        cin>>destino.idarbol;
        cin.ignore();
        cout << endl;
        
    
    cout << "  Otros datos a ingresar" << endl;
    // dato de venta
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
string obtenerFechaActual()
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

string obtenerFechaVencimiento(int diaslaborales)
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    // Sumar los días laborales a la fecha actual
    int diasSumados = 0;
    while (diasSumados < diaslaborales)
    {
        timeinfo->tm_mday++;
        mktime(timeinfo);
        //  no contar los fines de semana
        if (timeinfo->tm_wday != 0 && timeinfo->tm_wday != 6)
        {
            diasSumados++;
        }
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

int main()
{

    vector<Usuario> datos_usuario;
    vector<Origen> direcciones;
    vector<Madera> datos_madera;
    vector<Tala> info_tala;
    vector<Destino> destino_lugar;
    vector<Permiso> acceso;

    cout << endl;
    cout << BLUE_TEXT << "              | SISTEMA DE VERIFICACION LEGAL DE MADERA |" << endl;
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
    cout << "Cuantos tipos de madera esta trabajando: ";
    cin >> information;
    cin.ignore();
    for (int i = 0; i < information; ++i)
    {
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
    for (int i = 0; i < cant_tala; ++i)
    {
        Tala cut;
        cout << "Ingrese el id de la madera " << i + 1 << " :";
        cin >> cut.id_arbol;
        cin.ignore();
        cout << "Fueron plantados por ustedes (si/no): ";
        getline(cin,cut.trabajo_tala);
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
    // Registro de permiso
    cout << "  ----------------------" << endl;
    cout << "  | REGISTRO DE PERMISOS |" << endl;
    cout << "  ----------------------" << endl;

    int diaslaborales;
    int numDocumentos = 0;
    

    // Incrementar el contador de documentos
    numDocumentos++;

    // Declaración de una variable de tipo Permiso
    Permiso permiso;

    // Obtener la fecha actual
    permiso.fechaOtorgamiento = obtenerFechaActual();
      
    cout << "Adjunte los siguintes documentos:" << endl;

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
    permiso.fechaVencimiento = obtenerFechaVencimiento(diaslaborales);
    cout << "Ingrese apellidos y nombres del/de la representante legal: ";
    getline(cin, permiso.representanteLegal.nombre_repte);
    cout << "Ingrese el DNI del representante legal: ";
    getline(cin, permiso.representanteLegal.dni);
    cout << "Organizacion con la que trabaja:";
    getline(cin, permiso.organizacion);
    acceso.push_back(permiso);

    // Guardar datos en un archivo
    ofstream archivo("sistema_de_verificacion_legal.txt");
    if (archivo.is_open())
    {

        archivo << "\t\t\t                 SISTEMA DE VERIFICACION LEGAL" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        archivo << "|FECHA DE INICIO:" << acceso[0].fechaOtorgamiento << "                       | FECHA DE VENCIMIENTO:" << acceso[0].fechaVencimiento << endl;
        archivo << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        archivo << "|AUTORIZADO POR LA ORGANIZACION:";
        archivo << "|" << acceso[0].organizacion << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "                                                                         |DOCUMENTO Nro:" << setfill('0') << numDocumentos++ << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "| 1 | DATOS DE LA PERSONA SOLICITANTE Y DE SU REPRESENTACION LEGAL" << endl;
        // Itegrar sobre los datos de origen
        for (const auto &origen : direcciones)
        {
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|APELLIDOS Y NOMBRES: " << datos_usuario[0].nombre << "     | DNI:" << datos_usuario[0].DNI << "             |" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Distrito: " << origen.Distrito << "| Provincia: " << origen.Provincia << "|Ubicacion georeferenciada: " << origen.ubicacion_georeferenciada << "|" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Telefono: " << datos_usuario[0].telefono << "|Correo electronico: " << datos_usuario[0].correo << "|" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        for (const auto &destino1 : acceso)
        {
            archivo << "|NOMBRES COMPLETOS DEL/DE LA REPRESENTANTE LEGAL:" << destino1.representanteLegal.nombre_repte << "| DNI:" << destino1.representanteLegal.dni << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        archivo << endl;
        archivo << "|2|          LOCALIZACION DE TALA                                 |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        for (const auto &origen : direcciones)
        {
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|coordenas UTM" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            if (origen.zona_dph.tipo == "ZONA DE D.P.H")
            {

                archivo << "|           ZONA D.P.H                                            |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto central: " << origen.zona_dph.punto_central << "                             |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto más cercano al cauce: " << origen.zona_dph.punto_cauce << "                |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Metros cubicos de madera: " << origen.zona_dph.metros_madera << "                        |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            }
            if (origen.zona_policial.tipo == "ZONA POLICIAL")
            {
                archivo << "|             ZONA POLICIAL                                       |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto central: " << origen.zona_policial.punto_central << "   |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto más cercano al cauce: " << origen.zona_policial.punto_cauce << "  |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            }
        }

        archivo << endl;

        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "|3|CARACTERISTICAS DE LOS ARBOLES A CORTAR                        |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        for (const auto &tala : info_tala)
        {
            archivo << "|Fueron plantados por ustedes:" << tala.trabajo_tala << endl;
            archivo << "|Fecha de corte :" << tala.fecha_de_corte << "  |" << endl;
            archivo << "|-------------------------------------|" << endl;
            archivo << "|        Variedad  :" << tala.nombre_M << endl;
            archivo << "|Numero de arboles :" << tala.numero_arbol << endl;
            archivo << "|         Densidad :" << tala.densidad << endl;
            archivo << "|Superficie a cortar(hectareas):" << tala.superficie_cortar << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }

        archivo << "|                                    |Superficie total: " << suma << " |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        archivo << endl;
        archivo << "|4|    DESTINO DE LA MADERA                                       |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        for (const auto &finales : destino_lugar)
        {
            archivo << "|Coordenadas de inicio UTM(X,Y,HUSO):" << finales.lugar << "| Fecha de salida:" << finales.fechasalida << endl;
            archivo << "|----------------------------------------------------------------------------------|" << endl;

            archivo << "|Ubicacion georeferenciada(final) :" << finales.destinofinal << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|Datos del transporte:" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|Nombre y apellidos del conductor:" << finales.nombreConductor << "| DNI:" << finales.dniConductor << endl;
            archivo << "|----------------------------------------------------------------------------------|" << endl;

            archivo << "|ID de madera a llevar:" << finales.idarbol << "| Cantidad en unidades del total:" << finales.cantidad << endl;
            archivo << "|----------------------------------------------------------------------------------|" << endl;

            archivo << "|Placa de vehiculo:" << finales.placaVehiculo << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|                                   Total de venta a llevar(s/):" << finales.venta << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Alguna observacion:" << finales.observacion << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        archivo << endl;
        archivo << "|5|              VALIDEZ DEL PERMISO                                |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        for (const auto &validez : acceso)
        {
            archivo << "| DOCUMENTACION ADJUNTA|" << endl;
            archivo << "|----------------------|" << endl;

            archivo << "| CIF de la Entidad:" << validez.documentacion_adjunta[1] << endl;
            archivo << "| Representacion que ostenta:" << validez.documentacion_adjunta[2] << endl;
            archivo << "| Croquis de la zona de corta:" << validez.documentacion_adjunta[3] << endl;
            archivo << "| Informe sobre los efectos nocivos para el medio:" << validez.documentacion_adjunta[4] << endl;
            archivo << "| Otra documentacion:" << validez.documentacion_adjunta[5] << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }

        archivo << "              GRACIAS POR SU CONFIANZA" << endl;
        archivo.close();
        cout << "Datos guardados exitosamente en 'sistema_de_verificacion_legal.txt'" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout << "\t\t\t\t\tGRACIAS POR SU CONFIANZA" << endl;
    return 0;
}
