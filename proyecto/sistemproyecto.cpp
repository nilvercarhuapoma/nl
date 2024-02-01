#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[34m"
using namespace std;

struct Arboles
{
     string nombre_del_arbol;
     int cantidad;
     string edad;
     string origen_geografico;
     int densidad;
     int resistencia;
     int durabilidad;
     tm corte_cosecha;
     int serie_codigo;
     string GPS;
     string proveedor_doucumentacion;
     string certificaion_forestal;
     string propiedades_fisicas;
     string propiedades_mecanicas;
     string tamanio_parcela;
};

void registrarMadera(vector<Arboles> &datos_informativos)
{
     int x;
     cout << "¿CUANTOS TIPOS DE MADERA DESEA REGISTRAR?: ";
     cin >> x;
     time_t now = time(0);
     tm *timeinfo = localtime(&now);

     for (int i = 0; i < x; i++)
     {
          Arboles agregar;
          int year = 1900 + timeinfo->tm_year;
          int month = 1 + timeinfo->tm_mon;
          int day = 0 + timeinfo->tm_mday;
          cin.ignore();

          cout << "Ingrese el nombre del arbol " << i + 1 << ": ";
          cin >> agregar.nombre_del_arbol;
          cout << "Ingrese la cantidad de plataciones de " << agregar.nombre_del_arbol << ": ";
          cin >> agregar.cantidad;
          cin.ignore();
          cout << "Tamanio o area de la parcela:";
          getline(cin, agregar.tamanio_parcela);
          cout << "Ingrese su edad ( " << agregar.nombre_del_arbol << " ): ";
          getline(cin, agregar.edad);
          cout << "Ingrese su origen geografico: ";
          getline(cin, agregar.origen_geografico);
          cout << "[fecha de registro de su parcela]:" << day << "/" << month << "/" << year << endl;
          cout << "\n";
          if (agregar.nombre_del_arbol == "cedro")
          {
               cout << "    RECOMENDACION ACERCA DEL CEDRO:" << endl;
               cout << "SELECCION DEL SITIO:. " << endl;
               cout << "CLIMA:" << endl;
               cout << "DISTANCIA DE PLANTACION:" << endl;
               cout << "MONITOREO REGULAR:" << endl;
               cout << "\n";
          }

          if (agregar.nombre_del_arbol == "ishpingo")
          {
               cout << "   RECOMENDACION ACERCA DEL ISHPINGO:" << endl;
               cout << "SELECCION DEL SITIO:" << endl;
               cout << "CLIMA:" << endl;
               cout << "DISTANCIA DE PLANTACION:" << endl;
               cout << "MONITOREO REGULAR: " << endl;

               cout << "\n";
          }

          if (agregar.nombre_del_arbol == "caoba")
          {
               cout << "          ACERCA DE LA CAOBA:" << endl;
               cout << "SELECCION DEL SITIO:  " << endl;
               cout << "CLIMA:" << endl;
               cout << "DISTANCIA DE PLANTACION:" << endl;
               cout << "MONITOREO REGULAR: " << endl;

               cout << "\n";
          }

          if (agregar.nombre_del_arbol == "roble")
          {
               cout << "\n";
               cout << " RECOMENDACION ACERCA DEL ROBLE:" << endl;
               cout << "SELECCION DEL SITIO: " << endl;
               cout << "CLIMA:" << endl;
               cout << "DISTANCIA DE PLANTACION: " << endl;

               cout << "\n";
          }

          if (agregar.nombre_del_arbol == "tornillo")
          {

               cout << "               RECOMENDACION ACERCA DEL TORNILLO:" << endl;
               cout << BLUE_TEXT << "SELECCION DEL SITIO:" << RESET_COLOR << "Esta especie tropical generalmente prospera en suelos bien drenados y ricos en nutrientes. " << endl;
               cout << BLUE_TEXT << "CLIMA:" << RESET_COLOR << " El tornillo prefiere climas cálidos y húmedos" << endl;
               cout << BLUE_TEXT << "DISTANCIA DE PLANTACION:" << RESET_COLOR << "Planifica la distancia de plantación adecuada promedio cada 4m" << endl;
               cout << BLUE_TEXT << "MONITOREO REGULAR:" << RESET_COLOR << "Monitore el crecimiento de los árboles, la salud del suelo y la presencia de enfermedades o plagas. " << endl;

               cout << "\n";
          }
          datos_informativos.push_back(agregar);
     }
};

void Requisitos_de_verificacion(const vector<Arboles> &datos_informativos)
{
     int date = 0;

     do
     {
          cout << "\n";
          cout << "LOS REQUISITOS QUE DEBE TENER PARA SER USUARIO LEGAL EN MADERA" << endl;
          cout << "Lo que debes tener o conseguir: " << endl;
          cout << "[1].DOCUMENTACION LEGAL" << endl;
          cout << "[2].CERTIFICACION FORESTAL" << endl;
          cout << "[3].REGISTRO DE PARCELAS" << endl;
          cout << "[4].CUMPLIMIENTO AMBIENTAL" << endl;
          cout << "[5].FECHA DE CORTE O COSECHA LEGAL" << endl;
          cout << "[6].CERTIFICAION DE PROOVEDORES" << endl;
          cout << "[7].REGISTRO DE DATOS" << endl;
          cout << "[8].COLABORACION CON LAS AUTORIDADES" << endl;
          cout << "0.salir" << endl;
          cout << "Ingrese una opcion para ver requisito:" << endl;
          cin >> date;
          system("cls");
          cout << "\n";
          switch (date)
          {
          case 1:
               cout << "   DOCUMENTACION LEGAL:" << endl;
               cout << " El usuario debe proporcionar documentacion legal que respalde la propiedad ";
               cout << "y gestion sostenible de la parcela de madera " << endl;
               cout << " ";
               break;

          case 2:
               break;
          }
     } while (date != 0);
}
void sistema_de_verificacion(vector<Arboles> &datos_informativos)
{

     int cantidad_madera;
     cout << "       [RELLENE EL SIGUIENTE SISTEMA]" << endl;
     cout << "CUANTOS TIPOS DE MADERA CONTIENE:";
     cin >> cantidad_madera;
     for (int i = 0; i < cantidad_madera; i++)
     {
          Arboles rellene;
          cin.ignore();
          cout << "Nombre de la madera " << i + 1 << ":";
          getline(cin, rellene.nombre_del_arbol);
          cout << "Origen geografico:";
          getline(cin, rellene.origen_geografico);
          cout << "Fecha de corte o cosecha (dd mm yyyy):";
          cin >> rellene.corte_cosecha.tm_mday >> rellene.corte_cosecha.tm_mon >> rellene.corte_cosecha.tm_year;
          rellene.corte_cosecha.tm_mon -= 1;
          rellene.corte_cosecha.tm_year -= 1900;
          cin.ignore();
          cout << "Certificacion forestal:";
          getline(cin, rellene.certificaion_forestal);
          cout << "Numero de serie o codigo unico:";
          cin >> rellene.serie_codigo;
          cin.ignore();
          cout << "Proveedor o ducumentacion legal:";
          getline(cin, rellene.proveedor_doucumentacion);
          cout << "Informacion de GPS(opcional):";
          getline(cin, rellene.GPS);
          cout << "\n";

          datos_informativos.push_back(rellene);
     }
};
void Datos_de_la_madera(vector<Arboles> &datos_informativos)
{
     int number = 0;

     do
     {
          cout << "\n";
          cout << "           LOS ARBOLES MADERABLES" << endl;
          cout << "Esta son una lista de los arboles maderables:" << endl;
          cout << "[1].CEDRO" << endl;
          cout << "[2].ROBLE" << endl;
          cout << "[3].CAOBA" << endl;
          cout << "[4].PINO" << endl;
          cout << "[5].TORNILLO" << endl;
          cout << "[6].MOLLE" << endl;
          cout << "[7].CUMALA" << endl;
          cout << "[8].CAPIRONA" << endl;
          cout << "[9].ISPINGO" << endl;
          cout << "[10].COPAIBA" << endl;
          cout << "[11].TAHUARI" << endl;
          cout << "0.salir" << endl;
          cout << "Ingrese una opcion de su preferencia:" << endl;
          cin >> number;
          system("cls");
          cout<<"\n";

          switch (number)
          {
          case 1:
               cout << "EL CEDRO" << endl;
               cout << RED_TEXT << "---------------" << RESET_COLOR << endl;
               cout << "Es una especie importante en la industria maderera peruana y ";
               cout << "se utiliza para la fabricacion de muebles y carpinteria" << endl;

               break;

          case 2:
               break;
          }
     } while (number != 0);
     cout << "\n";
};

int main()
{
     int opcion = 0;

     vector<Arboles> datos_informativos;
     do
     {
          cout << "\n";
          cout << YELLOW_TEXT << "|---------------------------------------------------|" << endl;
          cout << GREEN_TEXT << "|          MENU DE OPCIONES:                        |" << RESET_COLOR << endl;
          cout << YELLOW_TEXT << "|---------------------------------------------------|" << endl;
          cout << BLUE_TEXT << "1. REGISTRAR MI PARCELA" << RESET_COLOR << endl;
          cout << BLUE_TEXT << "2. REQUISITOS DE VERIFICACION" << RESET_COLOR << endl;
          cout << BLUE_TEXT << "3. SISTEMA DE SEGUIMIENTO" << RESET_COLOR << endl;
          cout << BLUE_TEXT << "4. DATOS DE LA MADERA" << RESET_COLOR << endl;

          cout << "0. Salir" << endl;
          cout << "Ingrese su opcion: " << endl;
          cout << YELLOW_TEXT << "-----------------------------------------------|" << RESET_COLOR << endl;
          cin >> opcion;
          system("cls");

          switch (opcion)
          {
          case 1:
               registrarMadera(datos_informativos);
               break;
          case 2:
               Requisitos_de_verificacion(datos_informativos);
               break;

          case 3:
               sistema_de_verificacion(datos_informativos);
               break;
          case 4:
               Datos_de_la_madera(datos_informativos);

               break;
          }

     } while (opcion != 0);

     return 0;
}