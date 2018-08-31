/************************** Equipo.cpp *******************************/ /**
*
* @file Equipo.cpp
*
* @brief Implementacion de la clase Equipo
*
* Implementacion de los metodos de la clase Equipo
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
***************************************************************************/

#include "Equipo.h"

/************************* Equipo::Equipo() **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase
*
**************************************************************************/
Equipo::Equipo()
: nombre_equipo(""), nombre_capitan(""), goles_favor(0), goles_contra(0), partidos_jugados(0), partidos_ganados(0), partidos_empatados(0), partidos_perdidos(0), puntuacion(0)
{}

/************************* Equipo::Equipo(string) **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase
*
*****************************************************************************/
Equipo::Equipo(string x)
: nombre_equipo(x), nombre_capitan(""), goles_favor(0), goles_contra(0), partidos_jugados(0), partidos_ganados(0), partidos_empatados(0), partidos_perdidos(0), puntuacion(0)
{}

/************************* Equipo::AsignarNombre **************************/ /**
*
* Asigna el nombre del equipo
*
* @param[in] nombre_e Nombre que se le va asignar al equipo
*
*****************************************************************************/
void Equipo::AsignarNombre(string nombre_e)
{
    nombre_equipo = nombre_e;
}

/************************* Equipo::AsignarCapitan **************************/ /**
*
* Asigna el capitan del equipo
*
* @param[in] capitan Nombre que se le va asignar al capitan del equipo
*
*****************************************************************************/
bool Equipo::AsignarCapitan(string capitan)
{
    bool ya_esta;
    nombre_capitan = capitan;
    
    ya_esta = BusquedaSecuencialCapitan(nombre_jugadores, capitan);

    if (!ya_esta)
    {
        nombre_jugadores.push_back(capitan);
    }
    
    return ya_esta;
}

/************************* Equipo::DevolverNombre **************************/ /**
*
* Devuelve el nombre del equipo
*
* @return Nombre del equipo
*
*****************************************************************************/
string Equipo::DevolverNombre()
{
    return nombre_equipo;
}

/*** istream & operator>> (istream &, Equipo &) ************************/ /**
*
*  Sobrecarga del operador '>>' para asignar el nombre de todos los jugadores
*  del equipo desde un stream (fichero, teclado, ...).
*
*  @param [in,out]  entrada  stream del que vamos a obtener la informacion.
*  @param [out]     equipo   objeto Equipo que queremos rellenar con la
*                            informacion obtenida del stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
istream& operator>>(istream & entrada, Equipo & equipo)
{
    int i, num_jugadores;
    string nuevo_jugador;
    
    do
    {
        cout << "Cuantos jugadores conforman el equipo (MAX 10, MIN 6): ";
        entrada >> num_jugadores;
        entrada.ignore();
    }
    while (num_jugadores < 6 || num_jugadores > 10);

    for(i = 0; i < num_jugadores - 1; i++)
    {
        cout << "Introduce el nombre del jugador " << i + 1 << ": ";
        getline(entrada, nuevo_jugador);
        equipo.nombre_jugadores.push_back(nuevo_jugador);
    }
    
    return entrada;
}

/*** ostream & operator<< (ostream &, Equipo ) ********************/ /**
*
*  Sobrecarga del operador '<<' para motrar la información de un Equipo
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      equipo  objeto Equipo que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
ostream& operator<<(ostream & salida, Equipo equipo)
{
    int i;
    
    cout << "Equipo: \"" << equipo.nombre_equipo << "\"";
    cout << endl;
    cout << "Capitan: \"" << equipo.nombre_capitan << "\"";
    cout << endl;
    cout << "Jugadores: ";
    
    for (i = 0; i < equipo.nombre_jugadores.size(); i++)
    {
        cout << endl;
        cout << i + 1 << "\t " << equipo.nombre_jugadores[i];
    }
    
    cout << endl;
    
    return salida;
}

/******************** Equipo::BusquedaBinariaCapitan *************************/ /**
*
*  Implementa el metodo de busqueda binaria: Busca en el vector de jugadores el
*  nombre del capitan n elementos del vector v.
*
*  @param [in]  v           vector que contiene los datos
*  @param [in]  equipo     clave del elemento a buscar
*
*  @retval  True   Si hemos concluido la busqueda con exito
*  @retval  False  Si no hemos conseguido encontrar el libro buscado
*
*/ /******************************************************************************/
bool Equipo::BusquedaSecuencialCapitan (vector<string> v, string equipo)
{
    int i;
    bool enc = false;
    
    i = 0;
    while (i < v.size())
    {
        if (v[i] == equipo)
            enc = true;
        
        i = i + 1;
    }
    
    return enc;
}

/******************** Equipo::ModificarGoles *************************/ /**
*
*  Modifica los goles de un equipo
*
*  @param [in]  g_favor     Goles a favor a anadir
*  @param [in]  g_contra    Goles en contra a anadir
*
*/ /*********************************************************************/
void Equipo::ModificarGoles(int g_favor, int g_contra)
{
    goles_favor += g_favor;
    goles_contra += g_contra;
}

/******************** Equipo::ModificarPuntajeYPartidos *************************/ /**
*
*  Modifica el puntajes y los datos de los partidos
*
*  @param [in]  puntos Puntos obtenidos por el equipo en un partido
*
*/ /******************************************************************************/
void Equipo::ModificarPuntajeYPartidos(int puntos)
{
    partidos_jugados++;
    puntuacion += puntos;
    
    if (puntos == 3)
    {
        partidos_ganados++;
    }
    else if (puntos == 0)
    {
        partidos_perdidos++;
    }
    else
    {
        partidos_empatados++;
    }
}

/******************** Equipo::DevolverPuntaje *************************/ /**
*
*  Devuelve el puntaje de un equipo
*
*  @return Devuelvo el puntaje de un equipo en un campeonato
*
*/ /*************************************************************************/
int Equipo::DevolverPuntaje()
{
    return puntuacion;
}

/******************** Equipo::MostrarDatosEquipos *************************/ /**
*
*  Devuelve el puntaje de un equipo
*
*/ /*************************************************************************/
void Equipo::MostrarDatosEquipos()
{
    cout << setw(11);
    cout << nombre_equipo;
    cout << setw(3);
    cout << partidos_jugados;
    cout << setw(3);
    cout << partidos_ganados;
    cout << setw(3);
    cout << partidos_empatados;
    cout << setw(3);
    cout << partidos_perdidos;
    cout << setw(3);
    cout << goles_favor;
    cout << setw(3);
    cout << goles_contra;
    cout << setw(7);
    cout << puntuacion;
}
