/****** Pr1_test.cpp ****************************************************/ /**
 *
 * @file Pr1_test.cpp
 *
 * @brief Prácticas de Programacion. Tarea 5
 *
 * Lee la informacion de los coches guardada en un fichero y los pone en un 
 * registro.
 *
 * La informacion que tenemos de cada coche es:
 * - Matricula.
 * - Marca.
 * - Modelo.
 * - Fecha de adquisicion del vehiculo (dia, mes y anyo).
 * - Propietario (nombre y apellidos).
 *
 * Una vez leida la informacion se piden rangos de numeros y se obtienen 
 * matriculas aleatorias entre los margenes indicados.
 *
 * @version 1.0
 * @author Ricardo Ferris
 * @date 12-02-2018
 */ /*************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  //Equivalente C, #include <stdlib.h>
#include <ctime>    //Equivalente C, #include <time.h>
using namespace std;

/**
 * Maximo de coches que es posible guardar en la estructura
 */
const int MAX = 10000;

/**
 * Numero de matriculas aleatorias distintas que vamos a generar
 */
const int MAX_NUM = 8;                           

const string NOM_FICH = "coches.ordenados.dat";  ///< Nombre del fichero a leer

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
 * Registro Coche donde guardamos la informacion relativa a cada uno de los
 * coches.
 */
struct Coche
{
    string matricula;          ///< Matricula del vehiculo
    string marca;              ///< Marca del vehidulo
    string modelo;             ///< Modelo del vehiculo
    Fecha f_adquisicion;       ///< Fecha en que la empresa adquirio el vehiculo
    Propietario propietario;   ///< Datos del propiestario del vehiculo
};
   
/**
 * Tipo vector de coches: Estructura auxiliar para construir el registro Coches
 */ 
typedef Coche VCoches[MAX];

/**
 * Registro Coches donde guardar toda la informacion de los coches
 * (la informacion de cada coche, asi como el numero de coches)
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
void MostrarCoches (Coches);
void MostrarCoche (Coche);
void MostrarSoloIdCoches (Coches);
void MostrarFecha (Fecha);
int PedirNumero (int min, int max);
int GenerarNumeroAleatorio (int min, int max);
string GenerarMatriculaCocheAleatoria (const Coches &, int min, int max);

/*
 * Programa principal.
 */
int main (void)
{
    Coches coches;
    int i, min, max;
    string matricula_aleat;
    
    srand (2018);
    
    coches = LeerCochesFichero (NOM_FICH);

    cout << "Numero de coches leidos correctamente: " << coches.num << endl;

    cout << "Dame limite inferior del rango para determinar matriculas ";
    cout << "aleatorias de cohes:\n";
    cin >> min;

    cout << "Dame limite superior del rango para determinar matriculas ";
    cout << "aleatorias de cohes:\n";
    cin >> max;

    for (i = 0; i < MAX_NUM; i++)
    {
        matricula_aleat = GenerarMatriculaCocheAleatoria (coches, min, max);
        
        cout << " Una matricula en el rango [" << min << ", " <<  max << "] es ";
        cout << matricula_aleat << endl;
    }
        
    return 0;
}

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
        while (LeerCocheFichero(f, coches.info[contador]))
        {
            contador++;
        }
        coches.num = contador;
        f.close();
    }
    
    return coches;
}

bool LeerCocheFichero (ifstream & fich_in, Coche & coche)
{
    bool leido;
    
    if ( LeerFechaFichero(fich_in, coche.f_adquisicion) )
    {
        fich_in >> coche.matricula;
        fich_in.ignore();
        fich_in.ignore();
        getline(fich_in, coche.marca);
        getline(fich_in, coche.modelo);
        coche.propietario = LeerPropietarioFichero (fich_in);
        leido = true;
    }
    else
        leido = false;
    
    return leido;
}


bool LeerFechaFichero (ifstream & fich_in, Fecha & fecha)
{
    bool leido;
    char basura;
    
    if (fich_in >> fecha.anyo)
    {
        fich_in >> basura;
        fich_in >> fecha.mes;
        fich_in >> basura;
        fich_in >> fecha.dia;
        leido = true;
    }
    else
        leido = false;
    
    return leido;
}

Propietario LeerPropietarioFichero (ifstream & fich_in)
{
    Propietario p;
    
    getline (fich_in, p.nom);
    getline (fich_in, p.ape1);
    getline (fich_in, p.ape2);
    
    return p;
}


/**********************************************************************/ /**
 *
 *  Lee un entero de teclado hasta que este en el rango [min..max] y lo
 *  devuelve
 *
 *  @param [in]  min  valor minimo del rango
 *  @param [in]  max  valor maximo del rango
 *
 *  @return  valor leido de teclado
 *
 ************************************************************************/
int PedirNumero (int min, int max)
{
    int x;

    do
    {
        // Leer el tamanyo del vector
        cout << "Dame entero entre " << min << " y " << max - 1;
        cout << " (ambos incluidos): ";
        cin >> x;
    }
    while (x < min || max <= x);

    return x;
}

/**********************************************************************/ /**
 *
 *  Genera un entero aleatorio en el rango [min..max - 1] y lo devuelve
 *
 *  @pre  Se ha debido llamar a la funcion 'srand' previamente con una
 *        semilla adecuada (preferiblemente al inicio del programa
 *        principal)
 *
 *  @param [in]  min  valor minimo del rango
 *  @param [in]  max  valor maximo del rango
 *
 *  @return  valor aleatorio generado
 *
 */ /**********************************************************************/
int GenerarNumeroAleatorio (int min, int max)
{
    int num;
    
    num = min + rand() % (max - min);
    
    return num;
}

/**********************************************************************/ /**
 *
 *  Genera un numero en el rango [min..max[ y determina la matricula
 *  asociado al coche que ocupa esa posicion en el vector de la estructura.
 *  Si se determina un numero externo a los elementos guardados en la 
 *  estructura, se devuelve la matricula 'NoSeEncuentra'
 *
 *  @pre  La estructura coches debe estar debidamente rellenada
 *
 *  @param [in]  coches  Estructura Coches debidamente rellenada.
 *                       Se pasa por referencia constante para no realizar
 *                       la copia de toda la informacion y mejorar la 
 *                       eficiencia
 *  @param [in]  min  valor minimo del rango
 *  @param [in]  max  valor maximo del rango
 *
 *  @return  matricula del coche determinado de forma aleatoria o
 *           'No se encuentra' si el valor aleatorio esta fuera de los
 *           elementos guardados realmente en la estructura
 *
 ************************************************************************/
string GenerarMatriculaCocheAleatoria (const Coches & coches, int min, int max)
{
    int n_aleat;
    string matricula_aleat;
    
    n_aleat = GenerarNumeroAleatorio (min, max);

    // Buscaremos la matricula asociada a esa posicion
    // Si la posicion esta en el rango de coches validos de la coleccion
    // obtenemos la matricula del coche
    if (0 <= n_aleat && n_aleat < coches.num)
        matricula_aleat = coches.info[n_aleat].matricula;
    // Si esta fuera del rango, consideramos una matricula que no esta
    else
        matricula_aleat = "NoSeEncuentra";

    return matricula_aleat;
}

