/****** Pr1_ver.0.9.cpp ****************************************************/ /**
 *
 * @file Pr1_ver.0.9.cpp
 *
 * @brief Prácticas de Programacion.
 *
 * Lee la informacion de los coches guardada en un fichero, los pone en un 
 * registro y realiza diferentes busquedas en el mismo para realizar medidas
 * empiricas de esas busquedas.
 *
 * @version 0.9
 * @author Ricardo Ferris
 * @date 12-02-2018
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  //Equivalente C, #include <stdlib.h>
#include <ctime>    //Equivalente C, #include <time.h>

using namespace std;

/**
 * Maximo de libros que es posible guardar en la estructura
 */
const int MAX = 5100;

///< Numero de algoritmos con los que trabajar
const int N_ALGORITMOS = 3;

/**
 * Numero de matriculas aleatorias distintas que vamos a generar
 */
const int MAX_NUM = 500;

///< Codificación de los algoritmos de busqueda
const int SECUENCIAL           = 0;
const int SECUENCIAL_CENTINELA = 1;
const int BUSQUEDA_BINARIA     = 2;

///< Numero de tallas con las que vamos a trabajar
const int N_TALLAS = 4;


const string NOM_FICH = "coches.ordenados.dat";  ///< Nombre del fichero a leer
/**
 * Nombre del fichero de pruebas de 7 elementos a leer
 */
//const string NOM_FICH = "coches.peque.dat";

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
typedef VCoches Vector;

/**
 * Registro Coches donde guardar toda la informacion de los coches
 * (la informacion de cada coche, asi como el numero de coches)
 */
struct Coches
{
    VCoches info;
    int num;
};

///< Tipo para el vector de contadores
typedef int Contadores[N_ALGORITMOS];

///< Tipo para el vector de tallas
typedef int Tallas[N_TALLAS];

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
Coches LeerCochesFichero (string);
bool LeerCocheFichero (ifstream &, Coche &);
bool LeerFechaFichero (ifstream &, Fecha &);
Propietario LeerPropietarioFichero (ifstream &);
void MostrarResultados (const Contadores, int);
bool BusquedaSecuencial (Vector, int, string, int &);
bool BusquedaConCentinela (Vector, int, string, int &);
bool BusquedaBinaria (Vector, string, int, int &);
void RealizarBusquedas (int, Coches, string, Contadores);
int PedirNumero (int min, int max);
int GenerarNumeroAleatorio (int min, int max);
string GenerarMatriculaCocheAleatoria (const Coches &, int min, int max);
/*
 * Programa principal
 */
int main ()
{
    string matricula;
    Coches coches;     // Registro en el que vamos a buscar
//    int alg;           // Algoritmo con el que se desea buscar
    Contadores total;  // Contadores del total de operaciones, 1 x algoritmo
    Tallas tallas = {10, 500, 2000, 5000};
    int j, i, k;
    srand (2018);

    // Leemos la informacion del conjunto de coches
    coches = LeerCochesFichero (NOM_FICH);
    
//    Pedimos la talla del vector con el que queremos trabajar
//    cout << "Numero de elementos en el vector (max. " << coches.num << ")?\n";
//    coches.num = PedirNumero (1, coches.num + 1);

    
    for (i = 0; i < N_TALLAS; i++)
    {
        coches.num = tallas[i];
        // Poner contadores a cero
        for (j = 0; j < N_ALGORITMOS; j++)
        {
            total[j] = 0;
        }
        
        for (k = 0; k < MAX_NUM; k++)
        {
            matricula = GenerarMatriculaCocheAleatoria (coches, 0, coches.num * 2);
            

//            cout << "Dame algoritmo con el que quieres buscar:\n";
//            cout << " 0: Busqueda Secuencial.\n";
//            cout << " 1: Busqueda Secuencial con Centinela.\n";
//            cout << " 2: Busqueda Binaria.\n";
//
//            alg = PedirNumero (0, N_ALGORITMOS);
//
//            // Buscar matricula en la coleccion de coches mediante alguno de
//            // los 3 metodos:
//            // alg = 0: Busqueda Secuencial
//            // alg = 1: Busqueda Secuencial con Centinela
//            // alg = 2: Busqueda Binaria
            
            RealizarBusquedas (SECUENCIAL, coches, matricula, total);
            RealizarBusquedas (SECUENCIAL_CENTINELA, coches, matricula, total);
            RealizarBusquedas (BUSQUEDA_BINARIA, coches, matricula, total);
        }
        
        // Mostrar numero de operaciones de cada algoritmo
        MostrarResultados (total, coches.num);
    }
    
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
        while (LeerCocheFichero(f, coches.info[contador]))
        {
            contador++;
        }
        coches.num = contador;
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
*  @param [in/out]  fich_in  Descriptor del fichero del que vamos a leer
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
*  @param [in,out]  fich_in  Descriptor del fichero del que vamos a leer
*                            la informacion.
*  @param [out]     fecha   Fecha leida del fichero
*
*  @retval  true   La informacion ha podido ser leida de forma correcta.
*
*  @retval  false  La informacion no ha podido ser leida de forma correcta
*                  (probablemente porque se ha terminado el fichero).
*
*/ /**********************************************************************/
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

/**********************************************************************/ /**
*
*  Lee un propietario del fichero del que se pasa el descriptor y devuelve
*  el registro propietario debidamente rellenado.
*
*  @pre  El descriptor del fichero debe estar situado en la posicion en
*        la que haya un propietario (nombre y apellidos en lineas distintas)
*        para leer, ya que no se realiza ningun tipo de comprobacion.
*
*  @param [in,out]  fich_in Descriptor del fichero del que vamos a leer
*                            la informacion.
*
*  @return  La informacion del Propietario leida del fichero
*
*/ /**********************************************************************/
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
 *  Muestra el numero de operaciones realizadas por cada algoritmo
 *  para buscar en el vector.
 *
 *  @param [in]  contadores  Vector en el que estan los resultados de la
 *                           cuenta de pasos asociados a cada una de las
 *                           busquedas.
 *
 *  @param [in]  tam         Numero de elementos del vector sobre el que
 *                           se ha realizado la busqueda.
 *
 */ /**********************************************************************/
void MostrarResultados (const Contadores contadores, int tam)
{
    
    int media0, media1, media2;
    
    media0 = contadores[0] / tam;
    media1 = contadores[1] / tam;
    media2 = contadores[2] / tam;
    
    cout << endl;
    cout << "Resultados" << endl;
    cout << "Tamano: " << tam << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Busqueda Secuencial:" <<endl;
    cout << "\tTotal pasos = " << media0 << endl;
    cout << "Busqueda Secuencial con Centinela:" <<endl;
    cout << "\tTotal pasos = " << media1 << endl;
    cout << "Busqueda Binaria:" <<endl;
    cout << "\tTotal pasos = " << media2 << endl;
    cout << "-------------------------------------------" << endl;
    system ("PAUSE");
    
    return;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial (sin parada):
 *  Busca 'id' en el campo 'id' de los coches guardados en los primeros
 *  n elementos del vector v.
 *
 *  @pre  n debe ser un valor entero positivo
 *  @pre  pasos debe estar adecuadamente iniciada antes de ser pasada a
 *        la funcion
 *
 *  @param [in]  v          vector que contiene los datos
 *  @param [in]  n          numero de elementos 'validos' en el vector
 *  @param [in]  matricula  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda.
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el libro buscado
 *
 */ /**********************************************************************/
bool BusquedaSecuencial (Vector v, int n, string matricula, int & pasos)
{
    int i;
    bool enc = false;
    
    i = 0;
    while (i < n)
    {
        if (v[i].matricula == matricula)
            enc = true;
    
        // La comparacion del 'if'        
        pasos++;
            
        i = i + 1;
    }
    
    return enc;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con centinela:
 *  Busca 'id' en el campo 'id' de los coches guardados en los primeros
 *  n elementos del vector v.
 *
 *  @pre  n debe ser un valor entero positivo
 *  @pre  pasos debe estar adecuadamente iniciada antes de ser pasada a
 *        la funcion
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  matricula  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda.
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el libro buscado
 *
 */ /**********************************************************************/
bool BusquedaConCentinela (Vector v, int n, string matricula, int & pasos)
{
    int i;
    bool enc;
    
    //fijar centinela antes de buscar
    v[n].matricula = matricula;
    pasos++;

    i = 0;
    while (v[i].matricula != matricula)
    {
        i = i + 1;
        pasos++;
    }
    
     /* Si i ha llegado a n es que hemos localizado al centinela
      * y el 'id' no está en v
      * sino es que nos hemos detenido antes de localizar al centinela
      * y el 'id' si que esta en v
      */
    if (i == n)
        enc = false;
    else
        enc = true;

    return enc;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda binaria:
 *  Busca 'id' en el campo 'id' de los coches guardados en los primeros
 *  n elementos del vector v.
 *
 *  @pre  n debe ser un valor entero positivo
 *  @pre  pasos debe estar adecuadamente iniciada antes de ser pasada a
 *        la funcion
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  n   numero de elementos 'validos' en el vector
 *  @param [in]  matricula  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda.
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el libro buscado
 *
 */ /**********************************************************************/
bool BusquedaBinaria (Vector v, int n, string matricula, int & pasos)
{
    int izq, der, cen;
    /*
     * izq y der delimitan la zona del vector donde se busca
     * cen es la posición del elemento central de esta zona
     */
    bool enc = false;
    
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
    /*
     * Mientras no se encuentre el elemento
     * y existan más de un elemento en el subvector continúa
     * la búsqueda
    */
    while ( (izq <= der) && (v[cen].matricula != matricula) )
    {
        pasos++;
        
        pasos++;
        if (matricula < v[cen].matricula)
        {
            der = cen - 1;
        }
        else
            izq = cen + 1;
            
        cen = (izq + der) / 2;
    }
 
    /*
     * Se puede salir del bucle por haber encontrado el
     * elemento o por haber llegado a un subvector sin elementos
     */
    if (izq > der)
        enc = false;
    else
        enc = true;
 
    return enc;
}

/**********************************************************************/ /**
 *
 *  Permite seleccionar el algoritmo de busqueda emplear para:
 *  Busca 'titulo' en los 'biblio.num' primeros libros guardados en
 *  'biblio.info'. Utiliza un metodo de busqueda u otro dependiendo del
 *  parametro 'alg.
 *
 *  @pre  La biblioteca debe estar correctamente rellenada.
 *  @pre  Los contadores deberian estar correctamente iniciados.
 *
 *  @param [in]  alg     Algoritmo por el que deseamos buscar.
 *                          alg=0: Busqueda Secuencial.
 *                          alg=1: Busqueda Secuencial con Parada.
 *                          alg=2: Busqueda Secuencial con Centinela.
 *                          alg=3: Busqueda Binaria.
 *
 *  @param [in]  coches  Registro de los coches
 *
 *  @param [in]  id  Matricula del coche.
 *
 *  @param [out]  contadores  Vector en donde guardaremos el numero total
 *                            de pasos realizados dependiendo del metodo
 *                            de busqueda seleccionado.
 *
 */ /**********************************************************************/
void RealizarBusquedas (int alg, Coches coches, string id, Contadores contadores)
{
    bool ok = false;
    
//    cout << "\n** Buscando... ";
    switch (alg)
    {
        case 0:
//            cout << "Busqueda secuencial. **\n";
            ok = BusquedaSecuencial (coches.info, coches.num, id, contadores[alg]);
            break;
        case 1:
//            cout << "Busqueda secuencial con centinela. **\n";
            ok = BusquedaConCentinela (coches.info, coches.num, id, contadores[alg]);
            break;
        case 2:
//            cout << "Busqueda binaria. **\n";
            ok = BusquedaBinaria (coches.info, coches.num, id, contadores[alg]);
            break;
    }

//    cout << "** Elemento " << id;
//    if (ok)
//        cout << " encontrado **" << endl;
//    else
//        cout << " NO encontrado **" << endl;
    
    return;
}

/**********************************************************************/ /**
 *
 *  Lee un entero de teclado hasta que este en el rango [min..max - 1] que 
 *  indican los parametros y lo devuelve.
 *
 *  @pre  El parametro min debe ser menor que el parametro max.
 *
 *  @param [in]  min  Valor minimo del rango en el que debe estar el valor
 *                    introducido por el usuario. El valor del usuario debe
 *                    ser mayor o igual que min.
 *
 *  @param [in]  max  Valor maximo del rango en el que debe estar el valor
 *                    introducido por el usuario. El valor del usuario debe
 *                    ser menor estricto que max.
 *
 *  @return  Valor introducido por el usuario en el rango indicad..
 *
 */ /**********************************************************************/
int PedirNumero (int min, int max)
{
    int x;
    
    do
    {
        // Leer el tamanyo del vector
        cout << "Dame entero entre " << min << " y " << max - 1 << " (ambos incluidos): ";
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

/*********************************************************************************
 *                          TABLA A RELLENAR                                     *
 * Se pide:                                                                      *
 * a. rellena la tabla siguiente con los datos del número medio de pasos,        *
 * fijando la semilla de los números aleatorios en el valor 2016;                *
 * b. identifica qué algoritmos tienen coste lineal y cuales coste logarítmico.  *
 *********************************************************************************
 *                                     NUMERO DE ELEMENTOS           *           *
 *                           --------------------------------------------------- *
 *                           *   10    *   500   *   2000  *   5000  *   Coste * *
 *   ALGORIMO                *  PASOS  *  PASOS  *  PASOS  *  PASOS  *    O()  * *
 *   =========================================================================== *
 *   BUSQUEDA SECUENCIAL     |   500   |   500   |   500   |   500    |    n   | *
 *   ------------------------|-------------------------------------------------| *
 *   BUSQUEDA SEC. PARADA    |   405   |   384   |   383   |    382   |    n   | *
 *   ------------------------|-------------------------------------------------| *
 *   BUSQUEDA BINARIA        |   166   |     9   |     3   |     1    |  lg(n) | *
 *   =========================================================================== *
 *                                                                               *
 *********************************************************************************/

