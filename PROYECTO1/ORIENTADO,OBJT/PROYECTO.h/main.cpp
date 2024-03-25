#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <limits>
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
#include "Usuario.h"
#include "Representante.h"
#include "Origen.h"
#include "Madera.h"
#include "Tala.h"
#include "Conductor.h"
#include "Destino.h"
#include "Permiso.h"
using namespace std;
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
        cout << "SISTEMA COMPLETADO.... " << endl;
        cout << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
void mostrar_archivo(vector<Usuario> &date_usuario, vector<Representante> &representante, vector<Origen> &direcciones, vector<Conductor> &conductores, vector<Madera> &datos_madera,
                     vector<Tala> &info_tala, vector<Destino> &dest, vector<Permiso> &perms, int &diaslaborales)
{
    ifstream archivo("sistema de verificacion y seguimineto legal de madera.txt");

    if (!archivo.is_open())
    {
        cerr << "No se pudo abrir el archivo para leer.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    // Cierra el archivo
    archivo.close();
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
        try
        {
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
                mostrar_archivo(date_usuario, representante, direcciones, conductores, datos_madera, info_tala, dest, perms, diaslaborales);

                break;
            default:
             
                throw invalid_argument("Opcion no valida.");
            }
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
        }
    } while (opcion != 7);
            ;

     return 0;
 }