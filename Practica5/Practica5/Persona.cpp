/*********************** Camion.cpp ************************/ /**
*
* @file Persona.cpp
*
* Implementacion de los metodos de la clase Persona
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*******************************************************************/
#include "Persona.h"

/************************* Persona::Persona **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase Persona
*
**************************************************************************/
Persona::Persona()
: dni(""), nombre("")
{}

/********************* Persona::Persona *********************/ /**
*
*  Asigna el nombre y el dni a una Persona
*
* @param[in] id     Nombre equipo 1
* @param[in] name   Nombre equipo 2
*
******************************************************************/
Persona::Persona(string id, string name)
: dni(id), nombre(name)
{}

/********************* Persona::GetNombre *********************/ /**
*
*  Asigna el nombre y el dni a una Persona
*
* @return Nombre de la Persona
*
******************************************************************/
string Persona::GetNombre()
{
    return nombre;
}

/********************* Persona::GetDNI *********************/ /**
*
* Devuelve el DNI de la Persona
*
* @return DNI de la Persona
*
******************************************************************/
string Persona::GetDNI()
{
    return dni;
}

/********************* Persona::GetDNI() *********************/ /**
*
* Asigna el Nombre de la Persona
*
* @param[in] name Nombre de la Persona
*
******************************************************************/
void Persona::SetNombre(string name)
{
    nombre = name;
}

/********************* Persona::SetDNI *********************/ /**
*
* Asigna el DNI de la Persona
*
* @param[in] id de la Persona
*
******************************************************************/
void Persona::SetDNI(string id)
{
    dni = id;
}

/*** ostream & operator<< (ostream &, Persona) *************************/ /**
*
*  Sobrecarga del operador '<<' para sacar la información de un Persona
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      persona  objeto Partido que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************/
ostream& operator<< (ostream & salida, Persona persona)
{
    salida << persona.nombre;
    salida << " (" << persona.dni << ")";
    salida << endl;
    
    return salida;
}
