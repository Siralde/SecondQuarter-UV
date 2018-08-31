/**************************** Partido.cpp ***************************/ /**
*
* @file Partido.cpp
*
* Implementacion de los metodos de la clase Partido
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
************************************************************************/

#include "Partido.h"

/************************* Partido::Partido() **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase
*
**************************************************************************/
Partido::Partido()
: equipo_1(""), equipo_2(""), goles_1(0), goles_2(0)
{}

/********************* Partido::AsignarEquipos *********************/ /**
*
*  Asigna los nombres de los equipos de un partido
*
* @param[in] e_1 Nombre equipo 1
* @param[in] e_2 Nombre equipo 2
*
*************************************************************************/
void Partido::AsignarEquipos(string e_1, string e_2)
{
    equipo_1 = e_1;
    equipo_2 = e_2;
}

/********************* Partido::AsignarResultado *********************/ /**
*
*  Asigna los goles de los equipos de un partido
*
* @param[in] g_1 Goles equipo 1
* @param[in] g_2 Goles equipo 2
*
*************************************************************************/
void Partido::AsignarResultado(int g_1, int g_2)
{
    if (g_1 < 0 || g_2 < 0)
    {
        cout << "\nNo se pueden asignar resultados negativos\n";
    }
    else
    {
        goles_1 = g_1;
        goles_2 = g_2;
    }
}

/********************* Partido::DevolverEquipo1 *********************/ /**
*
* Devuelve el nombre del equipo 1
*
* @return Nombre del equipo 1
*
*************************************************************************/
string Partido::DevolverEquipo1()
{
    return equipo_1;
}

/********************* Partido::DevolverEquipo2 *********************/ /**
*
* Devuelve el nombre del equipo 2
*
* @return Nombre del equipo 2
*
*************************************************************************/
string Partido::DevolverEquipo2()
{
    return equipo_2;
}

/********************* Partido::DevolverGoles *********************/ /**
*
* Devuelve los goles de un equipo en un partido
*
* @param[in] x Nombre del equipo a buscar
*
* @return Goles del equipo a buscar
*
*************************************************************************/
int Partido::DevolverGoles(string x)
{
    int goles;
    
    if (x == equipo_1)
        goles = goles_1;
    else if (x == equipo_2)
        goles = goles_2;
    else
        goles = -1;
    
    return goles;
}

/*** ostream & operator<< (ostream &, Coche ) *************************/ /**
*
*  Sobrecarga del operador '<<' para sacar la información de un partido
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      partido  objeto Partido que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************/
ostream & operator<< (ostream & salida, Partido partido)
{
    salida << setw(10);
    salida << partido.equipo_1 << " - " << partido.equipo_2;
    salida << endl;
    salida << setw(9);
    salida << "(" << partido.goles_1 << " - " << partido.goles_2 << ")";
    salida << endl;
    
    return salida;
}
