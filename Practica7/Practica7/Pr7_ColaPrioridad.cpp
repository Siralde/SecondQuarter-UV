/******* Pr7_ColaPrioridad.cpp ***************************************************/ /**
*
* @file Pr7_Paciente.cpp
*
* Implementacion de los metodos de la clase Cola Prioridad
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 05-05-2018
*
*/ /************************************************************************/

#include "Pr7_ColaPrioridad.h"

/*************************** ColaPrioridad::ColaPrioridad() *************************/ /**
*
* Asigna valores iniciales 'coherentes' a los distintos atributos de la
* clase ColaPrioridad
*
*************************************************************************/
ColaPrioridad::ColaPrioridad()
:prioridades(0)
{}

/************************* ColaPrioridad::ColaPrioridad(int) **************************/ /**
*
* Construye una cola de prioridades con un numero de prioridades (colas) pasadas
* como parametro.
* Cada una de las colas que la componen está inicialmente vacía.
*
*************************************************************************/
ColaPrioridad::ColaPrioridad(int cant_prioridad)
:prioridades(cant_prioridad)
{}

/*************************** ColaPrioridad::Encolar ******************************/ /**
*
* Encola un paciente en la cola de pacientes con la prioridad indicada.
*
* @param[in] paciente   Paciente a encolar en la prioridad indicada
* @param[in] prioridad  Prioridad a encolar el paciente
*
* @retval true  Si existe una cola de pacientes con esa prioridad
* @retval false Si no existe una cola de pacientes con esa prioridad
*
*******************************************************************************/
bool ColaPrioridad::Encolar(Paciente paciente, int prioridad)
{
    bool encolado = false;
    
    if (prioridad - 1 <= prioridades.size())
    {
        encolado = true;
        prioridades[prioridad - 1].Encolar(paciente);
    }
    
    return encolado;
}

/*************************** ColaPrioridad::Desencolar ******************************/ /**
*
* Desencola un paciente de la cola no vacía de mayor prioridad.
*
* @retval true  Si se ha desencolado un paciente de alguna de las colas
* @retval false Si no se ha desencolado un paciente de alguna de las colas
*
*************************************************************************/
bool ColaPrioridad::Desencolar()
{
    bool desencolado = false;
    unsigned int num_colas = 0;
    
    while (!desencolado && num_colas < prioridades.size())
    {
        desencolado = prioridades[num_colas].Desencolar();
        num_colas++;
    }
    
    return desencolado;
}

/*********************** ColaPrioridad::PrimeroCola *************************/ /**
*
* Devuelve el primer paciente de la cola no vacía de mayor prioridad.
*
* @param[out] paciente Primer paciente de la cola no vacia de mayor prioridad
*
* @retval true  Si existe un paciente en alguna de las colas
* @retval false Si no existe un paciente en alguna de las colas
*
*************************************************************************/
bool ColaPrioridad::PrimeroCola(Paciente & paciente)
{
    bool existe;
    int i = 0;
    
    while (prioridades[i].ColaVacia() && i < prioridades.size())
    {
        i++;
    }
    
    if (!prioridades[i].ColaVacia())
    {
        prioridades[i].PrimeroCola(paciente);
        existe = true;
    }
    else
    {
        existe = false;
    }
    
    return existe;
}

/*************************** ColaPrioridad::PrimeroCola ******************************/ /**
*
* Verifica si todas las colas estan vacias
*
* @retval true  Si todas la colas estan vacias
* @retval false Si hay alguna cola no vacia
*
*************************************************************************/
bool ColaPrioridad::ColaVacia()
{
    bool vacias;
    int i = 0;
    
    while (prioridades[i].ColaVacia() && i < prioridades.size())
    {
        i++;
    }
    
    if (i == prioridades.size())
    {
        vacias = true;
    }
    else
    {
        vacias = false;
    }
    
    return vacias;
}

/********************* ostream & operator<< (ostream &, ColaPrioridad ) *********************/ /**
*
*  Sobrecarga del operador '<<' para motrar la información de una Cola
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida              stream por el que vamos a sacar la informacion.
*  @param [in]      colas_pacientes     objeto ColaPrioridad que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /****************************************************************************************/
ostream& operator<< (ostream & salida, ColaPrioridad colas_pacientes)
{
    int i;
    
    for (i = 0; i < colas_pacientes.prioridades.size(); i++)
    {
        salida << colas_pacientes.prioridades[i];
    }
    
    return salida;
}
