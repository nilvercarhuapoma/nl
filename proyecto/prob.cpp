#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <stdexcept> //
#include <limits>
#include <iomanip>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;

class Usuario
{

private:
    string nombre;
    int DNI;
    int telefono;
    string correo;
    string Ubicacion;

public:
    Usuario() {}
    Usuario(string n, int dni, int telf, string cor) : nombre(n), DNI(dni), telefono(telf), correo(cor) {}
    void add_usuario(vector<Usuario> &date_usuario);

    friend class Representante;
    string getn() const { return nombre; }
    int getdni() const { return DNI; }
    int gettelf() const { return telefono; }
    string getcor() const { return correo; }
};

void Usuario::add_usuario(vector<Usuario> &date_usuario)
{
    cout << "              | SISTEMA DE VERIFICACION Y SEGUIMIENTO LEGAL DE MADERA |" << endl;
    cout << "Registrese correctamente" << endl;
    cout << endl;
    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE USUARIO |" << endl;
    cout << "  ----------------------" << endl;

    // Registro de Usuario
    Usuario user;
    cout << "Ingrese apellidos y nombres:";
    getline(cin, user.nombre);

    // Solicitar y validar el DNI
   do {
    
        if (!(cin >> DNI) || cin.peek() != '\n' || to_string(DNI).length() != 8) {
            cout << "\r Intentalo de nuevo.                   \r"; // Limpia la línea antes de imprimir el nuevo mensaje
            cout << "Ingrese su DNI: "; // Imprime el mensaje nuevamente
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
    cin.ignore();
    cout << "Ingrese su telefono:";
    cin >> user.telefono;
    cin.ignore();
    cout << "Ingrese su correo electronico:";
    getline(cin, user.correo);

    cout << "\n";
    date_usuario.push_back(user);
}
class Representante : public Usuario
{
private:
    string ubicacion;

public:
    Representante() : Usuario() {}
    Representante(string u) : ubicacion(u) {}
    string get_u() const { return ubicacion; }
    void ingresar_representante(vector<Representante> &representante);
};
void Representante::ingresar_representante(vector<Representante> &representante)
{
    Representante represt;
    cout << "Ingrese los apellidos y nombres del representate:" << endl;
    cout << "Ingrese apellidos y nombres:";
    getline(cin, represt.nombre);
    bool validInput = false;
    do
    {
        try
        {
            cout << "Ingrese su DNI : ";
            cin >> represt.DNI;
            if (cin.fail() || to_string(represt.DNI).length() != 8)
            {
                throw runtime_error(" ");
            }
            validInput = true; // Si llega aquí sin lanzar una excepción, la entrada es válida
        }
        catch (const exception &e)
        {
            cout << e.what() << " Inténtalo de nuevo." << endl;
            cin.clear();                                         // Restaura el estado del flujo de entrada después de un error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el búfer de entrada
        }
    } while (!validInput);

    cin.ignore();
    cout << "Ingrese su telefono:";
    cin >> represt.telefono;
    cin.ignore();
    cout << "Ingrese su correo electronico:";
    getline(cin, represt.correo);
    cout << "Ingrese una ubicaion georreferenciada:";
    getline(cin, represt.ubicacion);
    representante.push_back(represt);
    cout << "\n";
}
class Zona
{
private:
    string tipo;
    double metros_madera;
    string punto_cauce;
    string punto_central;

public:
    Zona() {}
    Zona(string ti, double m_m, string p_c, string p_cent) : tipo(ti), metros_madera(m_m), punto_cauce(p_c), punto_central(p_cent) {}
    friend class Origen;
    void ingresarZona(Zona &zona, bool es_dph);
    string gett() const { return tipo; }
    double getm_m() const { return metros_madera; }
    string getp_c() const { return punto_cauce; }
    string getp_cent() const { return punto_central; }
};

void Zona::ingresarZona(Zona &zona, bool es_dph)
{
    cout << "Coordenadas UTM (x)(y)(HUSO)" << endl;
    cout << "Punto central:";
    getline(cin >> ws, punto_central);
    cout << "Punto mas cercano al cauce:";
    getline(cin >> ws, punto_cauce);

    if (es_dph)
    {
        cout << "Metros cubicos de madera:";
        cin >> metros_madera;
        cin.ignore();
    }
}

class Origen
{
private:
    Zona zona_dph;
    Zona zona_policial;
    string Departamento;
    string Provincia;
    string Distrito;
    string ubicacion_georeferenciada;

public:
    Origen() {}
    Origen(string D, string P, string dis, string U_b, Zona a_dph, Zona a_p) : zona_dph(a_dph), zona_policial(a_p), Departamento(D), Provincia(P), Distrito(dis),
                                                                               ubicacion_georeferenciada(U_b) {}
    void ingresarOrigen(vector<Origen> &direcciones);
    Zona geta_dph() const { return zona_dph; }
    Zona geta_p() const { return zona_policial; }
    string getD() const { return Departamento; }
    string getP() const { return Provincia; }
    string getdis() const { return Distrito; }
    string getU_b() const { return ubicacion_georeferenciada; }
};

void Origen::ingresarOrigen(vector<Origen> &direcciones)
{

    cout << "  -----------------------" << endl;
    cout << "  | REGISTRO DE ORIGEN |" << endl;
    cout << "  ----------------------" << endl;
    Origen from;
    cout << "        Origen de usuario" << endl;
    cout << "Ingrese el departamento: ";
    getline(cin >> ws, from.Departamento);
    cout << "Ingrese la provincia: ";
    getline(cin >> ws, from.Provincia);
    cout << "Ingrese el distrito: ";
    getline(cin >> ws, from.Distrito);
    cout << "Ubicacion georeferenciada: ";
    getline(cin >> ws, from.ubicacion_georeferenciada);
    cout << endl;
    cout << "       Zona en la que actuara(origen)" << endl;
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
        from.zona_dph.ingresarZona(from.zona_dph, true);
        break;
    case 2:
        from.zona_policial.tipo = "ZONA POLICIAL";
        from.zona_policial.ingresarZona(from.zona_policial, false);
        break;
    case 3:
        from.zona_dph.tipo = "ZONA DE D.P.H";
        from.zona_policial.tipo = "ZONA POLICIAL";
        cout << "Datos para la zona de D.P.H:" << endl;
        from.zona_dph.ingresarZona(from.zona_dph, true);
        cout << "Datos para la zona policial:" << endl;
        from.zona_policial.ingresarZona(from.zona_policial, false);
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }

    direcciones.push_back(from);
}

class Madera
{
protected:
    string nombre_M;
    string trabajo;
    int cantidad;
    double superficie;

public:
    Madera() {}
    Madera(string n, string t, int cant, double supfc) : nombre_M(n), trabajo(t), cantidad(cant), superficie(supfc) {}
    void ingresar_madera(vector<Madera> &datos_madera);
    string getn_M() const { return nombre_M; }
    string getT() const { return trabajo; }
    int getcant_M() const { return cantidad; }
    double getsuprf() const { return superficie; }
};

void Madera::ingresar_madera(vector<Madera> &datos_madera)
{
    cout << endl;
    cout << "  -------------------------" << endl;
    cout << "  | REGISTRO DE MADERA     |" << endl;
    cout << "  -------------------------" << endl;

    int information;
    // Solicitar y validar la cantidad de tipos de madera
    do
    {
        cout << "Cuantos tipos de madera está trabajando: ";
        if (!(cin >> information) || cin.peek() != '\n' || information <= 0)
        {
            cout << "Datos incorrectos. Inténtalo de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    } while (true);

    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < information; ++i)
    {
        Madera tree;
        cout << "Ingrese el nombre de la madera " << i + 1 << ": ";
        getline(cin, tree.nombre_M);
        cout << "Ingrese la cantidad de madera: ";
        cin >> tree.cantidad;
        cin.ignore();
        cout << "Ingrese el tamaño del arbol (hectareas): ";
        cin >> tree.superficie;
        cin.ignore();
        cout << "Fueron plantados por usted (si/no): ";
        getline(cin, tree.trabajo);
        cout << "\n";
        datos_madera.push_back(tree);
    }
    cout << endl;
}

class Tala : public Madera
{
private:
    int id_arbol;
    int numero_arbol;
    double densidad;
    string fecha_de_corte;

public:
    Tala() : Madera() {}
    Tala(string n, string t, int cant, double supfc, int id, int N_a, double densd, string f_c)
        : Madera(n, t, cant, supfc), id_arbol(id), numero_arbol(N_a), densidad(densd), fecha_de_corte(f_c) {}
    int getid() const { return id_arbol; }
    int getN_a() const { return numero_arbol; }
    double getdensd() const { return densidad; }
    string getf_c() const { return fecha_de_corte; }

    void ingresar_tala(vector<Tala> &info_tala);

    double suma_superficie(vector<Tala> &info_tala);
};

void Tala::ingresar_tala(vector<Tala> &info_tala)
{
    cout << "  -------------------" << endl;
    cout << "  | REGISTRO DE TALA |" << endl;
    cout << "  -------------------" << endl;

    int cant_tala;
    cout << "CARACTERISTICAS DE LOS ARBOLES A CORTAR" << endl;
    cout << "Cuantas variedades se cortaran: ";
    cin >> cant_tala;
    cin.ignore();
    for (int i = 0; i < cant_tala; ++i)
    {
        Tala cut;
        cout << "Asignar un ID al arbol " << i + 1 << " : ";
        cin >> cut.id_arbol;
        cin.ignore();
        cout << "Nombre de la madera: ";
        getline(cin, cut.nombre_M);
        cout << "Fueron plantados por ustedes (si/no):";
        cin >> cut.trabajo;
        cout << "Ingrese la fecha de corte: ";
        cin >> cut.fecha_de_corte;
        cin.ignore();
        cout << "Número total de arboles: ";
        cin >> cut.numero_arbol;
        cin.ignore();
        cout << "Ingrese la densidad: ";
        cin >> cut.densidad;
        cin.ignore();
        cout << "Superficie a cortar (hectareas): ";
        cin >> cut.superficie;
        cin.ignore();
        cout << "\n";
        info_tala.push_back(cut);
    }
    cout << endl;
}
double Tala::suma_superficie(vector<Tala> &info_tala)
{
    double sumaSuperficie = 0.0;
    for (const auto &tala : info_tala)
    {
        sumaSuperficie += tala.getsuprf();
    }
    return sumaSuperficie;
}
class Conductor
{

private:
    string nombreConductor;
    int dniConductor;
    string placaVehiculo;
    int idarbol;
    double cantidad;
    double ventas;

public:
    Conductor() {}
    Conductor(string n_c, int dni_c, string plc, int id_a, double cant, double vent) : nombreConductor(n_c),
                                                                                       dniConductor(dni_c), placaVehiculo(plc), idarbol(id_a), cantidad(cant), ventas(vent) {}

    string getn_c() const { return nombreConductor; }
    int getdni_c() const { return dniConductor; }
    string getplc() const { return placaVehiculo; }
    int getid_a() const { return idarbol; }
    double geticant() const { return cantidad; }
    double getvent() const { return ventas; }

    void Conductor_destino(vector<Conductor> &conduct);
    double suma_ventas(vector<Conductor> &conduct);
};
void Conductor::Conductor_destino(vector<Conductor> &conduct)
{
    int vh;

    int venta;
    cout << "Cuantos vehiculos se llevaran de madera:";
    cin >> vh;
    cin.ignore();
    for (int i = 0; i < vh; ++i)
    {
        Conductor cdtr;
        cout << "Ingrese apellidos y nombres del conductor del vehiculo " << i + 1 << " :";
        getline(cin, cdtr.nombreConductor);
        // Solicitar y validar el DNI
        do
        {
            cout << "Ingrese su DNI (8 dígitos): ";
            if (!(cin >> cdtr.dniConductor) || cin.peek() != '\n' || to_string(cdtr.dniConductor).length() != 8)
            {
                cout << "Datos incorrectos. El DNI debe tener 8 dígitos numéricos. Inténtalo de nuevo." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        } while (true);
        cin.ignore();
        cout << "Ingrese la placa del vehiculo:";
        getline(cin, cdtr.placaVehiculo);
        cout << "Ingrese el ID de la madera a llevar: ";
        cin >> cdtr.idarbol;
        cin.ignore();
        cout << "Cantidad a llevar (Toneladas):";
        cin >> cdtr.cantidad;
        cout << "Total de costo a llevar de madera:";
        cin >> cdtr.ventas;
        cin.ignore();

        cout << endl;
        conduct.push_back(cdtr);
    }
}
double Conductor::suma_ventas(vector<Conductor> &conduct)
{
    double suma = 0.0;
    for (const auto &cdtr : conduct)
    {
        suma += cdtr.getvent();
    }
    return suma;
}
class Destino
{
private:
    Conductor conductor;
    string lugar;
    string fechasalida;
    string destinofinal;
    string observacion;
    vector<Conductor> conductores;

public:
    Destino() {}
    Destino(vector<Conductor> &conduct, string n_c, int dni_c, string plc, int id_a, double cant, double vent, string l,
            string f_s, string d_f, string obs) : conductor(n_c, dni_c, plc, id_a, cant, vent), conductores(conduct), lugar(l), fechasalida(f_s), destinofinal(d_f),
                                                  observacion(obs) {}
    Conductor getcd() const { return conductor; }
    string getl() const { return lugar; }
    string getf_s() const { return fechasalida; }
    string getd_f() const { return destinofinal; }
    string getobs() const { return observacion; }

    void Ingresar_datosdestino(vector<Destino> &dest, vector<Conductor> &conduct);
};

void Destino::Ingresar_datosdestino(vector<Destino> &dest, vector<Conductor> &conduct)
{
    Destino destino;
    cout << "  --------------------------------" << endl;
    cout << " | REGISTRO DEL DESTINO DE MADERA |" << endl;
    cout << "  ---------------------------------" << endl;
    cout << "Ingrese el lugar de inicio(coordenadas UTM(x,y,huso)): ";
    getline(cin, destino.lugar);
    cout << "Ingrese la fecha de salida: ";
    getline(cin, destino.fechasalida);
    cout << "Ingrese el destino final(georeferencial): ";
    getline(cin, destino.destinofinal);
    cout << endl;
    destino.conductor.Conductor_destino(conduct);

    cout << "Total de costo:" << destino.conductor.suma_ventas(conduct);
    cin.ignore();
    cout << "Alguna observacion:";
    getline(cin, destino.observacion);
    dest.push_back(destino);
    cout << endl;
}
class Permiso
{
private:
    string documentacion[5];
    string organizacion;

public:
    Permiso() {}

    string getdoc(int index) const { return documentacion[index]; }

    string getorganizacion() const { return organizacion; }

    void Ingresar_permiso(vector<Permiso> &perms, int &diaslaborales);
    string get_FechaActual()
    {
        time_t now = time(0);
        tm *timeinfo = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
        return string(buffer);
    }

    string obtenerFechaVencimiento(int &diaslaborales);
};

string Permiso::obtenerFechaVencimiento(int &diaslaborales)
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    // Sumar los días laborales a la fecha actual
    int diasSumados = 0;
    while (diasSumados < diaslaborales)
    {
        timeinfo->tm_mday++;
        mktime(timeinfo);
        // No contar los fines de semana (sábado y domingo)
        if (timeinfo->tm_wday != 0 && timeinfo->tm_wday != 6)
        {
            diasSumados++;
        }
    }

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return string(buffer);
}

void Permiso::Ingresar_permiso(vector<Permiso> &perms, int &diaslaborales)
{
    Permiso permiso;
    cout << "  ----------------------" << endl;
    cout << "  | REGISTRO DE PERMISOS |" << endl;
    cout << "  ----------------------" << endl;

    int numDocumentos = 0;
    // Incrementar el contador de documentos
    numDocumentos++;
    cout << endl;
    cout << "Adjunte los siguientes documentos:" << endl;
    cout << "CIF de la Entidad: ";
    getline(cin, permiso.documentacion[0]);
    cout << "Representación que ostenta: ";
    getline(cin, permiso.documentacion[1]);
    cout << "Croquis de la zona de corta: ";
    getline(cin, permiso.documentacion[2]);
    cout << "Informe sobre los efectos nocivos para el medio: ";
    getline(cin, permiso.documentacion[3]);
    cout << "Otra documentación: ";
    getline(cin, permiso.documentacion[4]);

    cout << "Ingrese la organizacion:";
    getline(cin, permiso.organizacion);
    cout << endl;
    cout << "Fecha inicial del permiso : " << permiso.get_FechaActual();
    cout << endl;
    cout << "Cunatos dias necesita para realizar dicha TALA:";
    cin >> diaslaborales;
    cout << "Fecha final del permiso : " << permiso.obtenerFechaVencimiento(diaslaborales);
    perms.push_back(permiso);
    cout << endl;
}

void archivo_txt(vector<Usuario> &date_usuario, vector<Representante> &representante, vector<Origen> &direcciones, vector<Conductor> &conductores, vector<Madera> &datos_madera,
                 vector<Tala> &info_tala, vector<Destino> &dest, vector<Permiso> &perms, int &diaslaborales)
{
    ofstream archivo("sistema de verificacion y seguimineto legal de madera.txt");
    if (archivo.is_open())
    {
        int document = 0;
        document++;
        archivo << "\t\t\t              SISTEMA DE VERIFICACION Y SEGUIMIENTO LEGAL DE MADERA" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "|FECHA DE INICIO:" << perms[0].get_FechaActual() << "                       | FECHA DE VENCIMIENTO:" << perms[0].obtenerFechaVencimiento(diaslaborales) << endl;
        archivo << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "|AUTORIZADO POR LA ORGANIZACION:";
        archivo << "|" << perms[0].getorganizacion() << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "                                                                         |DOCUMENTO Nro:" << document++ << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "| 1 | DATOS DE LA PERSONA SOLICITANTE Y DE SU REPRESENTACION LEGAL" << endl;
        // Iterar sobre los datos de usuario
        for (const auto &user : date_usuario)
        {
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|APELLIDOS Y NOMBRES: " << user.getn() << "     | DNI:" << user.getdni() << "             |" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            // Suponiendo que solo hay un origen por usuario
            for (const auto &origen : direcciones)
            {
                archivo << "|Departamento:" << origen.getD() << "  |Provincia: " << origen.getP() << " | Distrito: " << origen.getdis() << "|Ubicacion georeferenciada: " << origen.getU_b() << "|" << endl;
            }
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Telefono: " << user.gettelf() << "|Correo electronico: " << user.getcor() << "|" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        // Imprimir datos de representante legal
        for (const auto &repres : representante)
        {
            archivo << "|NOMBRES COMPLETOS DEL/DE LA REPRESENTANTE LEGAL:" << repres.getn() << "| DNI:" << repres.getdni() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Telefono: " << repres.gettelf() << "|Correo electronico: " << repres.getcor() << "|" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Ubicacion georreferenciada:" << repres.get_u() << "|" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << endl;
            archivo << "|2|          LOCALIZACION DE TALA                                 |" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        for (const auto &origen : direcciones)
        {
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|coordenas UTM" << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            if (origen.geta_dph().gett() == "ZONA DE D.P.H")
            {
                archivo << "|           ZONA D.P.H                                            |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto central: " << origen.geta_dph().getp_cent() << "                             |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto más cercano al cauce: " << origen.geta_dph().getp_c() << "                |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Metros cubicos de madera: " << origen.geta_dph().getm_m() << "                        |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            }
            if (origen.geta_p().gett() == "ZONA POLICIAL")
            {
                archivo << "|             ZONA POLICIAL                                       |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto central: " << origen.geta_p().getp_cent() << "   |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
                archivo << "|Punto más cercano al cauce: " << origen.geta_p().getp_c() << "  |" << endl;
                archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            }
        }

        archivo << endl;

        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        archivo << "|3|CARACTERISTICAS DE LOS ARBOLES A CORTAR                        |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        for (const auto &tala : info_tala)
        {
            archivo << "|Fueron plantados por ustedes:" << tala.getT() << endl;
            archivo << "|Fecha de corte :" << tala.getf_c() << "  |" << endl;
            archivo << "|-------------------------------------|" << endl;
            archivo << "|        Variedad  :" << tala.getn_M() << endl;
            archivo << "|Numero de arboles :" << tala.getN_a() << endl;
            archivo << "|         Densidad :" << tala.getdensd() << endl;
            archivo << "|Superficie a cortar(hectareas):" << tala.getsuprf() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }

        archivo << "|                                    |Superficie total: " << info_tala[0].Tala::suma_superficie(info_tala) << " |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        archivo << endl;
        archivo << "|4|    DESTINO DE LA MADERA                                       |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        for (const auto &finales : dest)
        {
            archivo << "|Coordenadas de inicio UTM(X,Y,HUSO):" << finales.getl() << "| Fecha de salida:" << finales.getf_s() << endl;
            archivo << "|----------------------------------------------------------------------------------|" << endl;

            archivo << "|Ubicacion georeferenciada(final) :" << finales.getd_f() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        archivo << "|------------------------ |" << endl;

        archivo << "|Datos del transporte:" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        for (const auto &finales : conductores)

        {

            archivo << "|Nombre y apellidos del conductor:" << finales.getn_c() << "| DNI:" << finales.getdni_c() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|Placa de vehiculo:" << finales.getplc() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;

            archivo << "|ID de madera a llevar:" << finales.getid_a() << "| Toneladas a llevar de madera:" << finales.geticant() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
            archivo << "|Total de costo a llevar:" << finales.getvent() << endl;
            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }
        archivo << "                                                |Total de venta a llevar(s/):" << conductores[0].Conductor::suma_ventas(conductores) << endl;
        archivo << "|Alguna observacion:" << dest[0].getobs() << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;

        archivo << endl;
        archivo << "|5|              VALIDEZ DEL PERMISO                                |" << endl;
        archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        for (const auto &validez : perms)
        {
            archivo << "| DOCUMENTACION ADJUNTA|" << endl;
            archivo << "|----------------------|" << endl;
            archivo << "| CIF de la Entidad:" << validez.getdoc(0) << endl;
            archivo << "| Representacion que ostenta:" << validez.getdoc(1) << endl;
            archivo << "| Croquis de la zona de corta:" << validez.getdoc(2) << endl;
            archivo << "| Informe sobre los efectos nocivos para el medio:" << validez.getdoc(3) << endl;
            archivo << "| Otra documentacion:" << validez.getdoc(4) << endl;

            archivo << "|------------------------------------------------------------------------------------------------|" << endl;
        }

        archivo << "              GRACIAS POR SU CONFIANZA" << endl;
        archivo.close();
        cout << endl;
        cout << "Datos guardados exitosamente en 'sistema_de_verificacion_legal.txt'" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main()
{
    Usuario u;
    vector<Usuario> date_usuario;
    Representante r;
    vector<Representante> representante;
    Origen o;
    vector<Origen> direcciones;
    Madera m;
    vector<Madera> datos_madera;
    Tala t;
    vector<Tala> info_tala;
    vector<Conductor> conductores;
    Destino d;
    vector<Destino> dest;

    Permiso p;
    vector<Permiso> perms;
    int diaslaborales;
    int opcion;
    do
    {
        cout << endl;
        cout << "\t--------------------------------------------------------" << endl;
        cout << "\t| SISTEMA DE VERIFICACION Y SEGUIMIENTO LEGAL DE MADERA|" << endl;
        cout << "\t--------------------------------------------------------" << endl;
        cout << "\t| 1. REGISTRAR USUARIO                                 |" << endl;
        cout << "\t| 2. REGISTRAR ORIGEN                                  |" << endl;
        cout << "\t| 3. REGISTRAR MADERA                                  |" << endl;
        cout << "\t| 4. REGISTRAR TALA                                    |" << endl;
        cout << "\t| 5. REGISTRAR DESTINO DE LA MADERA                    |" << endl;
        cout << "\t| 6. REGISTRAR PERMISO DE TALA                         |" << endl;
        cout << "\t| 7. SALIR Y MOSTRAR DATOS                             |" << endl;
        cout << "\t|                                                      |" << endl;
        cout << "\t--------------------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        system("cls");

        cout << endl;

        switch (opcion)
        {
        case 1:
            u.add_usuario(date_usuario);
            r.ingresar_representante(representante);
            system("cls");

            break;
        case 2:
            o.ingresarOrigen(direcciones);
            system("cls");
            break;
        case 3:
            m.ingresar_madera(datos_madera);
            system("cls");
            break;
        case 4:
            t.ingresar_tala(info_tala);
            system("cls");
            break;
        case 5:
            d.Ingresar_datosdestino(dest, conductores);
            system("cls");
            break;
        case 6:
            p.Ingresar_permiso(perms, diaslaborales);
            system("cls");
            break;
        case 7:
            archivo_txt(date_usuario, representante, direcciones, conductores, datos_madera, info_tala, dest, perms, diaslaborales);

            cout << "Saliendo..." << endl;
            break;
        default:

            cout<< "Opcin incorrecta. Intentalo de nuevo.";

            break; // Sale del bucle si la opción es válida
        }
    } while (opcion != 7);

    return 0;
}