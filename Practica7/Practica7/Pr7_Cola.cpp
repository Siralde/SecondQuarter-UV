/******* Pr7_Cola.cpp ***************************************************/ /**
 *
 * @file Pr7_Cola.cpp
 *
 * Implementación de los métodos de la clase Cola
 *
 * @version 1.0
 * @author Miguel Angel Gamón
 *
 * @date 25-04-2018
 *
 */ /************************************************************************/

#include <stack>
#include "Pr7_Cola.h"

using namespace std;

/*** Cola::Cola () ******************************************************/ /**
 *
 *  Crea una cola vacía
 *
 */ /************************************************************************/
Cola::Cola ()
{
    inicio = NULL;
    fin = NULL;    
    n_elementos = 0;
    identificador = 0;
}

/*** Cola::Cola (unsigned int) ******************************************/ /**
 *
 *  Crea una cola vacía con un identificador
 *
 *  @param [in]	 id  identificador de la cola
 *
 */ /************************************************************************/
Cola::Cola (unsigned int id)
{
    inicio = NULL;
    fin = NULL;	
    n_elementos = 0;
    identificador = id;
}

/*** Cola::Cola (const Cola& c) *****************************************/ /**
 *
 *  Crea una cola a partir de otra ya existente
 *
 *  @param [in]  c  Cola original que contiene los elementos a asignar.
 *
 */ /************************************************************************/
Cola::Cola (const Cola& c)
{
    inicio = NULL;
    fin = NULL;
    
    Copiar (c);
}

/*** Cola::~Cola () *****************************************************/ /**
 *
 *  Destruye la cola vaciando su contenido.
 *
 */ /************************************************************************/
Cola::~Cola ()
{
    Vaciar();
}

/*** const Cola& Cola::operator= (const Cola& c) ************************/ /**
 *
 *   Sobrecarga del operador '=' que asigna el contenido de una cola existente
 *   en la cola que recibe la petición de la operación, igualando sus elementos.
 *
 *  @param [in]  c  Cola original que contiene los elementos a asignar.
 *
 */ /************************************************************************/
const Cola& Cola::operator= (const Cola& c)
{
    Vaciar ();
    Copiar (c);
    
    return *this;
}

/*** bool Cola::ColaVacia () const **************************************/ /**
 *
 *  Determina si la cola tiene o no elementos almacenados.
 *
 *  @retval  Devuelve verdadero si la cola está vacía, o falso en caso
 *           contrario.
 *
 */ /************************************************************************/
bool Cola::ColaVacia () const
{
    return inicio == NULL;
}

/*** void Cola::Encolar (Paciente x) ************************************/ /**
 *
 *  Almacena un elemento al final de la cola
 *
 *  @param [in]  x  Elemento que se almacena en la cola
 *
 */ /************************************************************************/
void Cola::Encolar (Paciente x)
{
    Puntero p_aux;
    
    p_aux = new Nodo;
    p_aux->info = x;
    p_aux->sig = NULL;
    
    if (inicio == NULL)
        inicio = p_aux;
    else    
        fin->sig = p_aux;
    fin = p_aux;
    
    n_elementos++;
    
    return;
}

/*** bool Cola::Desencolar () *******************************************/ /**
 *
 *  Elimina un elemento situado al principio de la cola
 *
 *  @retval  verdadero si se ha podido desencolar un elemento
 *  @retval  falso en caso contrario (si la cola estaba vacía)
 *
 */ /************************************************************************/
bool Cola::Desencolar ()
{
    bool ok;
    Puntero p_aux;
    
    if (inicio == NULL)
        ok = false;
    else
    {
        p_aux = inicio;
        inicio = inicio->sig;
        if (inicio == NULL)
            fin = NULL;
        delete p_aux;
        ok = true;        
        n_elementos--;
    }
    
    return ok;
}

/*** bool Cola::PrimeroCola (Documento & x) *****************************/ /**
 *
 *  Devuelve el elemento situado al principio de la cola
 *
 *  @param [out]  x  Elemento que se encuentra al principio de la cola
 *
 *  @retval  verdadero si hay algun elemento en la cola
 *  @retval  falso en caso contrario (si la cola estaba vacía).
 *
 */ /************************************************************************/
bool Cola::PrimeroCola (Paciente & x)
{
    bool ok;
    
    if (inicio == NULL)
        ok = false;
    else
    {
        x = inicio->info;
        ok = true;
    }
    return (ok);
}

/*** void Cola::Copiar (const Cola& c) **********************************/ /**
 *
 *  Duplica el contenido una cola existente sobre la cola que recibe la
 *  petición de la operación.
 *
 *  @param [in]  c  Cola original que contiene los elementos a copiar
 *
 */ /************************************************************************/
void Cola::Copiar (const Cola& c)
{
    Puntero p_aux, dup;
    
    p_aux = c.inicio;
    while (p_aux != NULL)
    {
        dup = new Nodo;
        dup->info = p_aux->info;
        dup->sig = NULL;
        
        if (inicio == NULL)
            inicio = dup;
        else
            fin->sig = dup;
        fin = dup;
        p_aux = p_aux->sig;
    }
    
    identificador = c.identificador;
    n_elementos = c.n_elementos;
}

/*** void Cola::Vaciar () **********************************************/ /**
 *
 *  Borra todos los elementos de la cola y libera el espacio en memoria
 *  correspondiente.
 *
 */ /***********************************************************************/
void Cola::Vaciar ()
{
    while (Desencolar ());
}

/*** void Cola::EstablecerNombre (string nom) **************************/ /**
 *
 *  Establece el nombre de la cola.
 *
 *  @param [in]        id        identificador de la cola
 *
 */ /***********************************************************************/
void Cola::EstablecerIdentificador (unsigned int id)
{
    identificador = id;
}

/*** void Cola::NumeroElementos () *************************************/ /**
 *
 *  Devuelve el número de elementos de la cola.
 *
 *  @retval  Número de elementos de la cola
 *
 */ /***********************************************************************/
unsigned int Cola::NumeroElementos () const
{
    return n_elementos;
}

/*** void Cola::InvertirCola () ****************************************/ /**
 *
 *  Devuelve una copia de la cola con los elementos en orden inverso.
 *
 *  @retval  La cola invertida
 *
 */ /***********************************************************************/
Cola Cola::InvertirCola () const
{
    Cola cola_inv (*this);
    stack<Paciente> pila_aux;
    Paciente paciente;
    
    while (!cola_inv.ColaVacia ())
    {
        cola_inv.PrimeroCola (paciente);        
        pila_aux.push (paciente);
        cola_inv.Desencolar ();
    }
    
    while (!pila_aux.empty ())
    {
        paciente = pila_aux.top ();
        cola_inv.Encolar (paciente);
        pila_aux.pop ();
    }
        
    return cola_inv;
}

/*** ostream & operator<< (ostream & out, const Cola & c) *************/ /**
 *
 *  Sobrecarga del operador '<<' para sacar la información de cola 
 *  por un stream (fichero, consola, ...).
 *
 *  @param [in, out]  out  stream por el que vamos a sacar la informacion.
 *  @param [in]  cola  objeto Cola que queremos sacar por el stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
ostream & operator<< (ostream &out, const Cola & cola)
{
    Cola::Puntero p_aux = cola.inicio;
    
    while (p_aux != NULL)
    {
        out << p_aux->info;
        if (cola.identificador > 0)
            out << "Prioridad: " << cola.identificador << endl;
        out << "---------------------------------" << endl;
        p_aux = p_aux->sig;
    }

    return out;
}
