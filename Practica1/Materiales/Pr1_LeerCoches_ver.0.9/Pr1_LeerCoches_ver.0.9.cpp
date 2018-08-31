/****** Pr1_pre.1.0.cpp ****************************************************/ /**
 *
 * @file Pr1_pre.1.0.cpp
 *
 * @brief Prácticas de Programacion. Tarea 0
 *
 * Lee la informacion de los coches guardada en un fichero y los pone en un 
 * registro.
 *
 * La informacion que tenemos de cada coche es:
 * - Matricula.
 * - Marca.
 * - Modelo.
 * - Fecha de adquisicion del vehiculo.
 * - Nombre y apellidos del propietario.
 *
 * @version 1.0
 * @author Ricardo Ferris
 * @date 12-02-2018
 *
 */ /***************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Maximo de libros que es posible guardar en la estructura
 */
const int MAX = 5100;

const string NOM_FICH = "coches.ordenados.dat";  ///< Nombre del fichero a leer
/**
 * Nombre del fichero de pruebas de 7 elementos a leer
 */

/**
 * Registro Fecha donde guardar dia, mes y anyo.
 */
struct Fecha
{
    unsigned short dia,
                   mes,
                   anyo;
};

/**
 * Registro Propiestario donde guardar nombre y apellidos.
 */
struct Propietario
{
    string nom,
           ape1,
           ape2;
};

/**
 * Registro Coche donde guardamos la informacion relativa a cada uno de los coches.
 */
struct Coche
{
    string matricula;           ///< Matricula del vehiculo
    string marca;               ///< Marca del vehidulo
    string modelo;              ///< Modelo del vehiculo
    Fecha f_adquisicion;        ///< Fecha en que la empresa adquirio el vehiculo
    Propietario propietario;   ///< Datos del propiestario del vehiculo
};
   
/**
 * Tipo vector de coches: Estructura auxiliar para construir el registro Coches
 */ 
typedef Coche VCoches[MAX];

/**
 * Registro Coches donde guardar toda la informacion de los coches (la informacion de cada coche, asi como
 * el numero de coches)
 */
struct Coches
{
    VCoches info;
    int num;
};

/*
 * Prototipos de funciones.
 */
Coches LeerCochesFichero (string);
bool LeerCocheFichero (ifstream &, Coche &);
bool LeerFechaFichero (ifstream &, Fecha &);
Propietario LeerPropietarioFichero (ifstream &);
void ConstruirId (Coche &);
void MostrarCoches (Coches);
void MostrarCoche (Coche);
void MostrarFecha (Fecha);
void MostrarPropietario (Propietario);

/*
 * Programa principal.
 */
int main (void)
{
    Coches coches;

    coches = LeerCochesFichero (NOM_FICH);

    MostrarCoches (coches);

    cout << "Coches leidos: " << coches.num;

    return 0;
}

/**********************************************************************/ /**
 *
 *  Lee la informacion de los coches contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Coches de forma
 *  adecuada.
 *
 *  @param [in]  nom_fich  Nombre del fichero donde esta la informacion de
 *               los coches.
 *
 *  @return  El registro Coches debidamente rellenado.
 *
 */ /**********************************************************************/
Coches LeerCochesFichero (string nom_fich)
{
    Coches coches;
    ifstream f;
    int contador = 0;
    
    f.open(NOM_FICH.c_str());
    if(!f)
        cout << "Error abriendo fichero en funcion LeerCochesFichero" << endl;
    else
    {
        while (LeerCochesFichero(f, coches[contador]))
        {
            contador++;
        }
        coches.
        f.close();
    }

    return coches;
}

/**********************************************************************/ /**
 *
 *  Lee, si es posible, UN coche del fichero del que se pasa el descriptor
 *  y devuelve el registro Coche debidamente rellenado y si ha podido o no
 *  rellenarlo adecuadamente.
 *
 *  @pre  El descriptor del fichero debe referirse a un fichero previamente
 *        abierto de forma correcta.
 *
 *  @param [in/out]  fichero  Descriptor del fichero del que vamos a leer
 *                            la informacion.
 *
 *  @param [out]     coche    Registro Coche debidamente rellenado con la
 *                            informacion leida del fichero.
 *
 *  @retval  true   La informacion ha podido ser leida de forma correcta.
 *
 *  @retval  false  La informacion no ha podido ser leida de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool LeerCocheFichero (ifstream & fich_in, Coche & coche)
{
    // Rellenar con lo desarrollado en la Tarea 1

}

/**********************************************************************/ /**
 *
 *  Lee una fecha del fichero del que se pasa el descriptor y devuelve el 
 *  registro Fecha debidamente rellenado.
 *
 *  @pre  El descriptor del fichero debe estar situado en la posicion en
 *        la que haya una fecha (dia mes anyo) para leer, ya que no se
 *        realiza ningun tipo de comprobacion (salvo final de lectura de
 *        fichero).
 *
 *  @param [in,out]  fichero  Descriptor del fichero del que vamos a leer
 *                            la informacion.
 *  @param [out]  fecha  Fecha leida del fichero
 *
 *  @retval  true   La informacion ha podido ser leida de forma correcta.
 *
 *  @retval  false  La informacion no ha podido ser leida de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool LeerFechaFichero (ifstream & fich_in, Fecha & fecha)
{
    // Rellenar con lo desarrollado en la Tarea 1

}

/**********************************************************************/ /**
 *
 *  Lee un propietario del fichero del que se pasa el descriptor y devuelve
 *  el registro propietario debidamente rellenado.
 *
 *  @pre  El descriptor del fichero debe estar situado en la posicion en
 *        la que haya un propietario (nombre y apellidos en lineas distintas)
 *        para leer, ya que no se realiza ningun tipo de comprobacion.
 *
 *  @param [in,out]  fichero  Descriptor del fichero del que vamos a leer
 *                            la informacion.
 *
 *  @return  La informacion del Propietario leida del fichero
 *
 */ /**********************************************************************/
Propietario LeerPropietarioFichero (ifstream & fich_in)
{
    // Rellenar con lo desarrollado en la Tarea 1

}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de todos los coches por pantalla.
 *
 *  @pre  El regsitro Coches tiene que estar debidamente rellenada con
 *        informacion correcta.
 *
 *  @param [in]  coches  Registro Coches debidamente rellenado
 *
 */ /**********************************************************************/
void MostrarCoches (Coches coches)
{
    int i;
    
    for (i = 0; i < coches.num; i++)
        MostrarCoche (coches.info[i]);

    return; 
}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de un coche por pantalla.
 *
 *  @param [in]  coche  Registro Coche a mostrar
 *
 */ /**********************************************************************/
void MostrarCoche (Coche coche)
{
    cout << "------------------------------------------------------------\n";
    cout << coche.matricula << ": ";
    cout << coche.marca << " - ";
    cout << coche.modelo << endl;
    cout << "\tFecha adquisicion: ";
    MostrarFecha (coche.f_adquisicion);
    cout << endl;
    cout << "\tPropietario: ";
    MostrarPropietario (coche.propietario);
    cout << endl;
    
    return;
}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de una fecha por pantalla.
 *
 *  @param [in]  fecha  Registro Fecha a mostrar
 *
 */ /**********************************************************************/
void MostrarFecha (Fecha fecha)
{
    cout << fecha.dia << '/' << fecha.mes << '/' << fecha.anyo;
    
    return;
}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de un propietario por pantalla.
 *
 *  @param [in]  propietario  Registro Propietario a mostrar
 *
 */ /**********************************************************************/
void MostrarPropietario (Propietario propietario)
{
    cout << propietario.nom << '\t';
    cout << propietario.ape1 << ' ' << propietario.ape2;
    
    return;
}

