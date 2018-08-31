/**********************************************************************/ /**
 *
 * @file Pr2_ver.0.9.cpp
 *
 * @brief Prácticas de Programacion. Práctica 2
 *
 * Lee la informacion de los coches guardada en un fichero y los pone en un 
 * registro.
 *
 * La informacion que tenemos de cada coche es en este orden
 * - Fecha de adquisicion del vehiculo.
 * - Matricula.
 * - Marca.
 * - Modelo.
 * - Nombre y apellidos del propietario.
 *
 * @version 0.9
 * @author Vicente Cerverón
 * @date 20-02-2018
 *
 */ /***************************************************************************/

#include "Pr2_Coche.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

/**
 * Maximo de coches que es posible guardar en la estructura
 */
const int MAX = 800;

/**
 * Numero de ordenaciones aleatorias a realizar
 */
const int N_REPETICIONES = 10;

///< Numero de algoritmos con los que trabajar
const int N_ALGORITMOS = 3;

///< Codificación de los algoritmos de busqueda
const int INSERCION = 0;
const int SELECCION = 1;
const int QUICKSORT = 2;

///< Numero de tallas con las que vamos a trabajar
const int N_TALLAS = 4;

//const string NOM_FICH = "coches.todos.dat";  ///< Nombre del fichero a leer
/**
 * Nombre del fichero de pruebas de 7 elementos a leer
 */
const string NOM_FICH = "coches.todos.dat";
   
///< Tipo para el vector de contadores
typedef int Contadores[N_ALGORITMOS];

///< Tipo para el vector de tallas
typedef int Tallas[N_TALLAS];

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

/*
 * Prototipos de funciones.
 */
int LeerCochesFichero (VCoches, int &);
void MostrarCoches (VCoches, int);
bool Anterior(Coche, Coche);
bool Ordenado(VCoches, int);
void Desordenar(VCoches, int);
void OrdenarInsercion(VCoches, int, int &);
void OrdenarSeleccion(VCoches, int, int &);
void OrdenarQuicksort(VCoches, int, int &); 
void Particion(VCoches, int, int, int &);

void ProbarOrdenaciones(Coches &);
void RealizarExperimentos(Coches &);

void invertirVector(VCoches, int);
void CalcularMedia(Contadores v, int n, Tallas tallas, int i);
/*
 * Programa principal.
 */
int main (void)
{
    Coches coches;
    int cuantos;

    cuantos = LeerCochesFichero (coches.info, coches.num);
    cout << endl << "Coches leidos: " << cuantos << endl;
    
//    ProbarOrdenaciones(coches);
    RealizarExperimentos(coches);
    
    return 0;
}

/**********************************************************************/ /**
*
*  Prueba los diferentes algoritmos de ordenación.
*
*  @param [in/out]  coches  Estructura con vector de coches y número de elementos.
*
*/ /**********************************************************************/
void RealizarExperimentos(Coches & coches)
{
    int i, j;
    Tallas tallas = {100, 200, 400, 800};
//    Contadores total;
    Contadores pasos, media;
    Coches coches_original = coches;
    srand(2018);
  
//    for (i = 0; i < N_TALLAS; i++)
//    {
//        coches_original.num = tallas[i];
//        // Poner contadores a cero
//        for (j = 0; j < N_ALGORITMOS; j++)
//        {
//            total[j] = 0;
//        }
//
//        ProbarOrdenaciones(coches_original);
//
//        coches_original = coches;
//    }
//

    for (i = 0; i < N_TALLAS; i++)
    {
        for (j = 0; j < N_ALGORITMOS; j++)
        {
            media[j] = 0;
        }
        pasos[INSERCION] = 0;
        pasos[QUICKSORT] = 0;
        pasos[SELECCION] = 0;
        //Bucle de repeticiones
        for (j = 0; j < N_REPETICIONES; j++)
        {
            Desordenar(coches_original.info, tallas[i]);
        
//            cout << "\nCOMENZAMOS SEGMENTO DE INSERCION\n";
            coches = coches_original;

            OrdenarInsercion(coches.info, tallas[i], pasos[INSERCION]);
//            if(Ordenado(coches.info, coches.num))
//                cout << endl << "Vector ordenado" << endl;
//            else
//                cout << endl << "Vector desordenado" << endl;
//            cout << " por insercion de " << coches.num << " elementos (ha empleado " << pasos[INSERCION] << " pasos)." << endl;
//            //    MostrarCoches(coches.info, coches.num);
            media[INSERCION] += pasos[INSERCION];
            
//            cout << "\nCOMENZAMOS SEGMENTO DE SELECCION\n";
            coches = coches_original;
            OrdenarSeleccion(coches.info, tallas[i], pasos[SELECCION]);
//            if(Ordenado(coches.info, coches.num))
//                cout << endl << "Vector ordenado" << endl;
//            else
//                cout << endl << "Vector desordenado" << endl;
//            cout << " por seleccion de " << coches.num << " elementos (ha empleado " << pasos[SELECCION] << " pasos)." << endl;
//            //    MostrarCoches(coches.info, coches.num);
            media[SELECCION] += pasos[SELECCION];
            
//            cout << "\nCOMENZAMOS SEGMENTO DE QUICK-SORT\n";
            coches = coches_original;
            OrdenarQuicksort(coches.info, tallas[i], pasos[QUICKSORT]);
//            if(Ordenado(coches.info, coches.num))
//                cout << endl << "Vector ordenado" << endl;
//            else
//                cout << endl << "Vector desordenado" << endl;
//            cout << " por quicksort de " << coches.num << " elementos (ha empleado " << pasos[QUICKSORT] << " pasos)." << endl;
//            //    MostrarCoches(coches.info, coches.num);
            media[QUICKSORT] += pasos[QUICKSORT];
        }
        
        CalcularMedia(media, tallas[i] * N_REPETICIONES, tallas, i);
        
        coches_original = coches;
        
        cout << endl;
    }
     
    return;
}

void CalcularMedia(Contadores v, int n, Tallas tallas, int i)
{
    int media_ins, media_sel, media_qs;
    cout << "\nTALLAS -------------------> " << tallas[i];
    cout << "\n MEDIAS: \n";
    media_ins = v[INSERCION] / n;
    cout << "\tInsercion: " << media_ins << endl;
    media_sel = v[SELECCION] / n;
    cout << "\tSeleccion: " << media_sel << endl;
    media_qs = v[QUICKSORT] / n;
    cout << "\tQuickSort: " << media_qs << endl;
}

/**********************************************************************/ /**
 *
 *  Lee la informacion de los coches contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Coches de forma
 *  adecuada.
 *
 *  @param [in/out]  v  Vector de objetos de la clase Coche.
 *
 *  @param [out]  num Número de coches en el vector
 *
 *  @return  El número de coches leídos.
 *
 */ /**********************************************************************/
int LeerCochesFichero (VCoches v, int & num)
{
    // Rellenar con lo desarrollado en la Tarea 1
    ifstream fich_in;
    Coches coches;
    
    fich_in.open (NOM_FICH);
    
    num = 0;
    
    if (fich_in)
    {
        while ( num < MAX && fich_in >> v[num] )
            num++;
            
        fich_in.close ();
    }

    return num;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla la informacion de num coches contenidos en un vector.
 *
 *  @param [in]  v  Vector de objetos de la clase Coche.
 *
 *  @param [in]  num Número de coches en el vector
 *
 */ /**********************************************************************/
void MostrarCoches (VCoches v, int num)
{
    int i;
    
    cout << "-------------------------------\n";
    for (i = 0; i < num; i++)
    {
        cout << v[i];
        cout << "-------------------------------\n";
    }

    return; 
}

/**********************************************************************/ /**
 *
 *  Indica si el primer coche tiene la matrícula anterior al segundo.
 *
 *  @param [in]  coche1  Un objeto de tipo Coche
 *  @param [in]  coche2  Otro objeto de tipo Coche
 *
 *  @return  Verdadero si el primer coche tiene la matrícula anterior al segundo.
 *
 */ /**********************************************************************/
bool Anterior(Coche coche1, Coche coche2)
{
    string matri1, matri2, letras1, letras2, numeros1, numeros2;
    bool respuesta;
    
    matri1 = coche1.DevuelveMatricula();
    matri2 = coche2.DevuelveMatricula();
    letras1 = matri1.substr(4,3);
    letras2 = matri2.substr(4,3);
    numeros1 = matri1.substr(0,4);
    numeros2 = matri2.substr(0,4);
    
    if(letras1 < letras2)
        respuesta = true;
    else if(letras1 == letras2 && numeros1 < numeros2)
        respuesta = true;
    else
        respuesta = false;
    
    return respuesta;
}

/**********************************************************************/ /**
 *
 *  Indica si los primeros num elementos de un vector de coches están en orden creciente
 *
 *  @param [in]  v  Vector de objetos de la clase Coche.
 *
 *  @param [in]  num Número de coches en el vector
 *
 *  @return Verdadero si cada elemento es "menor" que el siguiente
 *
 */ /**********************************************************************/
bool Ordenado(VCoches v, int num)
{
    bool respuesta;
    int i;
    
    i = 0;
    while( i < (num - 1) && Anterior(v[i] , v[i+1]) )
        i++;
        
    if(i == num - 1)
        respuesta = true;
    else
        respuesta = false;
                
    return respuesta;
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo de inserción
 *
 *  @param [in/out]  v      Vector de objetos de la clase Coche.
 *
 *  @param [in]      n      Numero de coches que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarInsercion(VCoches v, int n, int & pasos)
{
    int i, j;

    //la parte ordenada est‡ al final de vector
    for (i = n - 2; i >= 0; i--)
    {
        pasos++;        //Paso v[n] = v[i]
        v[n] = v[i];
        j = i + 1;

        while (Anterior(v[j] , v[n]))
        {
            pasos++;    //Paso de Repeticion/Entrada del bucle
            v[j-1] = v[j];
            pasos++;   //Paso de asignacion v[j-1] = v[j];
            j++;
        }
        pasos++;        //Paso de Salida del bucle while

        v[j-1] = v[n];
        pasos++;        //Paso de asignacion v[j-1] = v[n];
    }

    return;
}

/**********************************************************************/ /**
*
*  Ordena de modo creciente n elementos de un vector por el algoritmo de seleccion
*
*  @param [in/out]  v       Vector de objetos de la clase Coche.
*
*  @param [in]      n       Numero de coches que se ordenan
*
*  @param [in/out]  pasos   incrementa el numero de pasos
*
*/ /**********************************************************************/
void OrdenarSeleccion(VCoches v, int n, int & pasos)
{
    int i, j, pos_min;
    Coche aux;
    
    for (i = 0; i < n - 1; i++)
    {
        pos_min = i;
        for (j = i + 1; j < n; j++)
        {
            pasos ++; //la comparaci—n de la l’nea siguiente
            if (Anterior(v[j] , v[pos_min]))
                pos_min = j;
        }
        
        if (pos_min != i)
        {
            aux = v[i];
            v[i] = v[pos_min];
            v[pos_min] = aux;
            pasos += 3; //las tres asignaciones de las l’neas anteriores
        }
    }
    
    return;
}

/************************ OrdenarQuickSort *********************//**
*
* Ordena un vector mediante el metodo de particion
*
* @param[in] v      Vector
* @param[in] tam    Numero de Elementos del vector
*
*//*************************************************************/
void OrdenarQuicksort(VCoches v, int tam, int &pasos)
{
    Particion (v, 0, tam - 1, pasos);
}

/************************ Particion *********************//**
*
* Ordena un vector mediante el metodo de particion
*
* @param[in] v      Vector
* @param[in] izq    Borde/Limite izquierdo del vector
* @param[in] der    Borde/Limite derecho del vector
*
*//*************************************************************/
void Particion(VCoches v, int izq, int der, int & pasos)
{
    int i, j;
    Coche piv, aux;
    
    i = izq;
    j = der;
    piv = v[(izq + der) / 2];
    pasos++;
    
    while (i <= j)
    {
        while ( Anterior(v[i] , piv) )
        {
            pasos++;
            i++;
        }
        pasos++;
        
        while ( Anterior(piv , v[j]) )
        {
            pasos++;
            j--;
        }
        pasos++;
        
        if (i < j)
        {
            aux  = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            pasos += 3;
        }
        else if (i == j)
        {
            i++;
            j--;
        }
    }
    
    if (der > i)
    {
        Particion(v, i, der, pasos);
    }
    
    if (izq < j)
    {
        Particion(v, izq, j, pasos);
    }
}

/**********************************************************************/ /**
 *
 *  Desordena n elementos de un vector aleatoriamente
 *
 *  @param [in/out]  v  Vector de objetos de la clase Coche.
 *
 *  @param [in]  n Número de coches que se ordenan
 *
 */ /**********************************************************************/
void Desordenar(VCoches v, int n)
{
    int i, cual;
    Coche auxcoche;
    
    for(i=0; i<n; i++)
    {
        cual = rand()%n;
        auxcoche = v[cual];
        v[cual] = v[0];
        v[0] = auxcoche;
    }
    
    return;
}

/**********************************************************************/ /**
*
*  Desordena n elementos de un vector aleatoriamente
*
*  @param [in,out]  v  Vector de objetos de la clase Coche.
*
*  @param [in]  tam Número de coches que se ordenan
*
*/ /**********************************************************************/
void InvertirVector(VCoches v, int tam)
{
    int i, j;
    
    j = tam - 1;
    for (i = 0; i < tam / 2; i++)
    {
        v[tam] = v[i];
        v[i] = v[j];
        v[j] = v[tam];
        j--;
    }
}

/**********************************************************************/ /**
 *
 *  Prueba los diferentes algoritmos de ordenación.
 *
 *  @param [in/out]  coches  Estructura con vector de coches y número de elementos.
 *
 */ /**********************************************************************/
void ProbarOrdenaciones(Coches & coches)
{
    Coches coches_orig, coches_invert;
    Contadores pasos;
    
    coches_orig = coches;
    
    if(Ordenado(coches_orig.info, coches_orig.num))
        cout << endl << "Original ordenado" << endl;
    else
        cout << endl << "Original desordenado" << endl;    
 
    /*
     * Ordenacion por Insercion
     */
    pasos[INSERCION] = 0;
    OrdenarInsercion(coches.info, coches.num, pasos[INSERCION]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;        
    cout << " por insercion de " << coches.num << " elementos (ha empleado " << pasos[INSERCION] << " pasos)." << endl;
//    MostrarCoches(coches.info, coches.num);

    cout << "\nCOMENZAMOS SEGMENTO DE SELECCION\n";
    coches = coches_orig;
    pasos[SELECCION] = 0;
    OrdenarSeleccion(coches.info, coches.num, pasos[SELECCION]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;        
    cout << " por seleccion de " << coches.num << " elementos (ha empleado " << pasos[SELECCION] << " pasos)." << endl;    
//    MostrarCoches(coches.info, coches.num);

    cout << "\nCOMENZAMOS SEGMENTO DE QUICK-SORT\n";
    coches = coches_orig;
    pasos[QUICKSORT] = 0;
    OrdenarQuicksort(coches.info, coches.num, pasos[QUICKSORT]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;        
    cout << " por quicksort de " << coches.num << " elementos (ha empleado " << pasos[QUICKSORT] << " pasos)." << endl;    
//    MostrarCoches(coches.info, coches.num);
    
    
//Tarea 4 Segundo parrafo
    cout << "\n--------------------AHORA INVERTIMOS LOS COCHES----------------\n";
    
    InvertirVector(coches.info, coches.num);
    coches_invert = coches;

    if(Ordenado(coches_invert.info, coches_invert.num))
        cout << endl << "Invertido ordenado" << endl;
    else
        cout << endl << "Invertido desordenado" << endl;
//    MostrarCoches(coches.info, coches.num);
    
    /*
     * Ordenacion por Insercion
     */
    cout << "\nCOMENZAMOS SEGMENTO DE INSERCION\n";
    pasos[INSERCION] = 0;
    OrdenarInsercion(coches.info, coches.num, pasos[INSERCION]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;
    cout << " por insercion de " << coches.num << " elementos (ha empleado " << pasos[INSERCION] << " pasos)." << endl;
    //    MostrarCoches(coches.info, coches.num);
    
    cout << "\nCOMENZAMOS SEGMENTO DE SELECCION\n";
    coches = coches_invert;
    pasos[SELECCION] = 0;
    OrdenarSeleccion(coches.info, coches.num, pasos[SELECCION]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;
    cout << " por seleccion de " << coches.num << " elementos (ha empleado " << pasos[SELECCION] << " pasos)." << endl;
    //    MostrarCoches(coches.info, coches.num);
    
    cout << "\nCOMENZAMOS SEGMENTO DE QUICK-SORT\n";
    coches = coches_invert;
    pasos[QUICKSORT] = 0;
    OrdenarQuicksort(coches.info, coches.num, pasos[QUICKSORT]);
    if(Ordenado(coches.info, coches.num))
        cout << endl << "Vector ordenado" << endl;
    else
        cout << endl << "Vector desordenado" << endl;
    cout << " por quicksort de " << coches.num << " elementos (ha empleado " << pasos[QUICKSORT] << " pasos)." << endl;
    //    MostrarCoches(coches.info, coches.num);
    
    cout << "\n---------------------------------------------------\n\n";
    
    return;
}

/*********************************************************************************
 *                          TABLA A RELLENAR                                     *
 * Se pide:                                                                      *
 * a. rellena la tabla siguiente con los datos del número medio de pasos,        *
 * fijando la semilla de los números aleatorios en el valor 2018;                *
 * b. identifica qué tipo de coste tiene cada algoritmo.  *
 *********************************************************************************
 *                                     NUMERO DE ELEMENTOS           *           *
 *                           --------------------------------------------------- *
 *                           *   100   *   200   *   400   *   800   *   Coste * *
 *   ALGORITMO               *  pasos  *  pasos  *  pasos  *  pasos  *    O()  * *
 *   =========================================================================== *
 *   ordenacion insercion    |    54   |   107   |   203   |   396   |   n/2   | *
 *   --------------------------------------------------------------------------| *
 *   ordenación selección    |    52   |   102   |   202   |   402   |   n/2   | *
 *   ------------------------|-------------------------------------------------| *
 *   ordenación quicksort    |    14   |   016   |   018   |   020   |  log(n) | *
 *   =========================================================================== *
 *                                                                               *
 *********************************************************************************/

