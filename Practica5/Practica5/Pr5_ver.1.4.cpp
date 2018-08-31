/******* Pr5_ver.1.4.cpp ***************************************************/ /**
 *
 * @file Pr5_ver.1.4.cpp
 * @brief Prácticas de Programacion. Práctica 2.
 * @brief Clase para el manejo de vehiculos
 *
 * @version 1.4
 * @author Emiliano Torres
 * @date 10/04/2018
 *  
 ***************************************************************************/
#include <fstream>
#include "Vehiculo.h"
#include "Coche.h"
#include "Camion.h"

using namespace std;

/**
 * Maximo de vehiculos que es posible guardar en la estructura
 */
const int MAX = 5100;

/**
 * Nombre de los ficheros
 */
const string NOM_FICH_COCHES = "coches.dat";  // Nombre del fichero a leer
const string NOM_FICH_CAMIONES = "camiones.dat";  // Nombre del fichero a leer
   
/**
 * Tipo vector de objetos de tipo coches: Estructura auxiliar para construir el registro Coches
 */ 
typedef Coche VCoches[MAX+1];

/**
 * Registro Coches donde guardar toda la informacion de los coches (la informacion de cada coche, asi como
 * el numero de coches)
 */
struct Coches
{
    VCoches info;
    int num;
};
/**
 * Tipo vector de objetos de tipo coches: Estructura auxiliar para construir el registro Coches
 */ 
typedef Camion VCamiones[MAX+1];

/**
 * Registro Coches donde guardar toda la informacion de los coches (la informacion de cada coche, asi como
 * el numero de coches)
 */
struct Camiones
{
    VCamiones info;
    int num;
};

void BuscarMatricula(string, Coches&, Camiones&);
void BuscarDNI(string, Coches&, Camiones&);
template <class C> void MuestraVehiculo(C [], int);
template <class C> void MuestraVehiculo2(C [], int);
template <class C> void LeerFichero(string, C [], int&);
template <class C> bool LeerFichero2(ifstream&, C &);
template <class C> bool BusquedaBinariaPorMatricula (C [], int, string, int&);
template <class C> bool BusquedaConCentinelaPorDNI (C [], int, string, int&);
/*
 * Programa principal.
 */
int main (void)
{
    int op = 0;
    string matricula, dni;
    Coches coches;
    Camiones camiones;
    
    camiones.num = 0;
    LeerFichero(NOM_FICH_CAMIONES, camiones.info, camiones.num);
    cout << "\n***************** CAMIONES LEIDOS: " << camiones.num << " *********************\n";
    MuestraVehiculo (camiones.info, camiones.num);
    coches.num = 0;
    LeerFichero(NOM_FICH_COCHES, coches.info, coches.num);
    cout << "\n***************** COCHES LEIDOS: " << coches.num << " *********************\n";
    MuestraVehiculo (coches.info, coches.num);

    setlocale(LC_ALL, "spanish");
    
    cout << "\n\n******************* MENU **********************\n";
    do
    {
        cout << "1. Buscar vehiculos por matricula";
        cout << endl;
        cout << "2. Buscar vehiculos por DNI";
        cout << endl;
        cout << "3. Salir";
        cout << endl;
        cout << "Opcion: ";
        cin >> op;
        
        switch (op)
        {
            case 1:
                cout << endl;
                cout << "Introduce la matricula: ";
                cin >> matricula;
                BuscarMatricula(matricula, coches, camiones);
                cout << endl;
                break;
            case 2:
                cout << endl;
                cout << "Introduce la DNI: ";
                cin >> dni;
                BuscarDNI(dni, coches, camiones);
                cout << endl;
                break;
            case 0:
                break;
            default:
                cout << "Opcion Invalida, intente nuevamente...";
                cout << endl;
                break;
        }
    }
    while (op != 0);
    
    cout << endl;
    
    return 0;
}


/************************ BuscarMatricula *********************************/ /**
*
* Busca en un Vector derivado de la clase Vehiculo, la matricula pasada por
* el usuario
*
* @param [in]  matricula   Matricula a buscar
* @param [in]  coches      Estructura de datos que almacena todos los coches
* @param [in]  camiones    Estructura de datos que almacena todos los camiones
*
*/ /****************************************************************************/
void BuscarMatricula(string matricula, Coches & coches, Camiones & camiones)
{
    bool enc_cam, enc_coches;
    int posicion_camion = 0, posicion_coche = 0;
    
    enc_cam = BusquedaBinariaPorMatricula(camiones.info, camiones.num, matricula, posicion_camion);
    
    if (enc_cam)
    {
        cout << endl;
        cout << "Camion encotrado por matricula";
        cout << endl;
        MuestraVehiculo2(camiones.info, posicion_camion);
    }
    else
    {
        cout << endl;
        cout << "Camion no encotrado por matricula";
        cout << endl;
    }

    enc_coches = BusquedaBinariaPorMatricula(coches.info, coches.num, matricula, posicion_coche);
    if (enc_coches)
    {
        cout << endl;
        cout << "Coche encotrado por matricula";
        cout << endl << endl;
        MuestraVehiculo2(coches.info, posicion_coche);
    }
    else
    {
        cout << endl;
        cout << "Coche no encotrado por matricula";
        cout << endl;
    }
}
/***************************** BuscarDNI **************************************/ /**
*
* Busca en un Vector derivado de la clase Vehiculo, el dni pasado por
* el usuario
*
* @param [in]  dni         DNI a buscar
* @param [in]  coches      Estructura de datos que almacena todos los coches
* @param [in]  camiones    Estructura de datos que almacena todos los camiones
*
*/ /****************************************************************************/
void BuscarDNI(string dni, Coches & coches, Camiones & camiones)
{
    bool enc_coches, enc_camion;
    int posicion_coche = 0, posicion_camion = 0;
    
    enc_camion = BusquedaConCentinelaPorDNI(camiones.info, camiones.num, dni, posicion_camion);
    if (enc_camion)
    {
        cout << endl;
        cout << "Camion encontrado por DNI";
        cout << endl;
        MuestraVehiculo2(camiones.info, posicion_camion);
    }
    else
    {
        cout << endl;
        cout << "Camion no encotrado por dni";
        cout << endl;
    }

    enc_coches = BusquedaConCentinelaPorDNI(coches.info, coches.num, dni, posicion_coche);
    if (enc_coches)
    {
        cout << endl;
        cout << "Coche encotrado por DNI";
        cout << endl;
        MuestraVehiculo2(coches.info, posicion_coche);
    }
    else
    {
        cout << endl;
        cout << "Coche no encotrada por dni";
        cout << endl;
    }
}

/**************** template <class C> void MuestraVehiculo *******************/ /**
*
*  Plantilla para mostrar atriburos de la clases vehiculo y sus derivadas
*
*  @param [in]  v           Vector de la clase
*  @param [out] n           Cantidad de elementos leidos
*
*/ /****************************************************************************/
template <class C> void MuestraVehiculo(C v[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        cout << v[i];
    }
}


/**************** template <class C> void MuestraVehiculo2 *******************/ /**
*
*  Plantilla para mostrar atriburos de la clases vehiculo y sus derivadas
*
*  @param [in]  v           Vector de la clase
*  @param [out] n           Cantidad de elementos leidos
*
*/ /****************************************************************************/
template <class C> void MuestraVehiculo2(C v[], int n)
{
        cout << v[n];
}


/********************* template <class C> int LeerFichero *******************/ /**
*
*  Plantilla para leer fichero relacionados a la clase Vehiculo y sus derivadas
*
*  @param [in]  nom_fichero Nombre del fichero a leer
*  @param [in]  v           Vector a Rellenar
*  @param [out] n           Cantidad de elementos leidos
*
*/ /****************************************************************************/
template <class C> void LeerFichero(string nom_fichero, C v[], int & n)
{
    ifstream f;
    
    f.open(nom_fichero.c_str());
    if(!f)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        while (LeerFichero2(f, v[n]))
        {
            n++;
        }
        f.close();
    }
}

/********************* template <class C> bool LeerFichero2 *******************/ /**
*
*  Plantilla para leer fichero relacionados a la clase Vehiculo y sus derivadas
*
*  @param [in]  f           Nombre del fichero a leer
*  @param [in]  v           Vector a Rellenar

*  @return  El stream modificado tras su utilizacion
*
*/ /******************************************************************************/
template <class C> bool LeerFichero2(ifstream & f, C & v)
{
    bool leido = false;
    
    if (f >> v)
        leido = true;
    
    return leido;
}


/******************* BusquedaBinariaPorMatricula *********************//**
*
* Busca un elemento de un vector ordenado
*
* @param[in]  v     Vector
* @param[in]  n     Tamano del vector
* @param[in]  x     Valor buscado
* @param[out] pos   Posicion del elemento buscado dentro del vector
*
*//******************************************************************/
template <class C> bool BusquedaBinariaPorMatricula (C v[], int n, string x, int & pos)
{
    int izq, der, cen;
    bool enc;
    
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
    while ( (izq <= der) && (v[cen].GetMatricula() != x) )
    {
        if (x < v[cen].GetMatricula())
        {
            der = cen - 1;
        }
        else
        {
            izq = cen + 1;
        }
        cen = (izq + der) / 2;
    }
    
    if (izq > der)
    {
        enc = false;
    }
    else
    {
        enc = true;
        pos = cen;
    }
    
    return enc;
}

/************************ BusquedaConCentinelaPorDNI *********************//**
*
* Busca un elemento de un vector no ordenado
*
* @param[in]  v     Vector de Elementos
* @param[in]  n     Tamano del vector
* @param[in]  x     Elemento a encontrar
* @param[out] pos   Posicion del elemento buscado dentro del vector
*
*//**********************************************************************/
template <class C> bool BusquedaConCentinelaPorDNI (C v[], int n, string x, int & pos)
{
    Persona aux(x,"Nadie");
    int i;
    bool enc = false;
    
    v[n].GetPropietaria() = aux; //fijar centinela antes de buscar
    i = 0;

    aux = v[i].GetPropietaria();
    
    while (aux.GetDNI() != x && i != n)
    {
        i = i + 1;
        aux = v[i].GetPropietaria();
    }
    if (i == n) //localizado centinela, x no esta en v
        enc = false;
    else //elemento x localizado antes del centinela
    {
        enc = true;
        pos = i;
    }   

    return enc;
}
