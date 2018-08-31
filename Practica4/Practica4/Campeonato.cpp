/*********************** Campeonato.cpp ************************/ /**
*
* @file Campeonato.cpp
*
* Implementacion de los metodos de la clase Campeonato
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
*******************************************************************/

#include "Campeonato.h"

/********************* Campeonato::Campeonato() **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase
*
**************************************************************************/
Campeonato::Campeonato(string x)
: nombre(x), saldo(0)
{}

/********************* Campeonato::InscribirEquipo ********************/ /**
*
* Anade un equipo al Campeonato
*
* @param[in] equipo Equipo a anadir al campeonato
*
* @retval true  Si se logro inscribir el equipo correctamente
* @retval false Si no se logro inscribir el equipo correctamente
*
**************************************************************************/
bool Campeonato::InscribirEquipo(Equipo equipo)
{
    bool repetido;
    bool inscrito;
    
    repetido = BuscarSecuencialEquipo(equipo.DevolverNombre());
    if (!repetido)
    {
        equipos.push_back(equipo);
        saldo += 100;
        inscrito = true;
        
        cout << "\nSi se pudo inscribir\n";
    }
    else
    {
        inscrito = false;
        cout << "\nNo se pudo inscribir\n";
    }
    
    return inscrito;
}

/********************* Campeonato::AgregarResultadoPartido ********************/ /**
*
* Anade un partido disputado en el Campeonato
*
* @param[in] partido Partido disputado
*
* @retval true  Si se logro anadir el partido disputado
* @retval false Si no se logro anadir el partido disputado
*
**************************************************************************/
bool Campeonato::AgregarResultadoPartido(Partido partido)
{
    bool anadido = false;
    bool partido_repetido, partidos_disputados;
    
    partido_repetido = BuscarSecuencialPartido(partido);
    partidos_disputados = Finalizado();
    if (!partido_repetido && !partidos_disputados)
    {
        ActualizarTabla(partido);
        partidos.push_back(partido);
        saldo -= 30;
        anadido = true;
    }
    
    return anadido;
}

/*************** void operator+(Campeonato c, int x) **********************/ /**
*
* Sobrecarga del operador '+' para sumar una cantidad al saldo de union
* campeonato
*
* @param [in]  c Campeonato al que hay que aumentar su saldo.
* @param [in]  x Cantidad que hay que sumarle al saldo del campeonato.
*
*/ /**********************************************************************/
void operator+(Campeonato & c, int x)
{
    c.saldo = c.saldo + x;
}

/*************** void operator-(Campeonato, int) **********************/ /**
*
* Sobrecarga del operador '-' para restarle una cantidad de euros al saldo de un
* campeonato,  si éste es mayor o igual a 200+x. En ese caso,
* se considera realizado el gasto y el saldo del campeonato disminuirá
* en x euros. Si no se cumple la anterior emite un mensaje por
* pantalla indicando “saldo insuficiente”.
*
* @param [in]  c Campeonato al que hay que disminuir su saldo.
* @param [in]  x Cantidad que hay que restale al saldo del campeonato.
*
*/ /**********************************************************************/
void operator-(Campeonato & c, int x)
{
    int saldo_aux;
    
    saldo_aux = c.saldo - x;
    
    if (saldo_aux >= 200)
    {
        c.saldo -= x;
    }
    else
        cout << "Saldo Insuficiente\n";
}

/****************** Campeonato::DevolverSaldo *********************/ /**
*
* Devuelve el saldo económico que el campeonato tiene en un momento dado.
*
* @return Saldo del Campeonato
*
**************************************************************************/
int Campeonato::DevolverSaldo()
{
    return saldo;
}

/*** ostream & operator<< (ostream &, Equipo ) *********************************/ /**
*
*  Sobrecarga del operador '<<' para motrar la información de todos los
*  equipos que juegan en el campeonato por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida      stream por el que vamos a sacar la informacion.
*  @param [in]      campeonato  objeto Campeonato que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /***********************************************************************************/
ostream& operator<<(ostream & salida, Campeonato campeonato)
{
    int i;
    
    for (i = 0; i < campeonato.equipos.size(); i++)
    {
        salida << "\n---------" << i + 1 << "---------\n";
        salida << campeonato.equipos[i] << endl;
    }
    cout << endl;
    
    return salida;
}

/****************** Campeonato::MostrarPuntuaciones *********************/ /**
*
* Muestra la tabla de puntuaciones, indicando para cada equipo el
* número de puntos, los partidos jugados, los partidos ganados, los
* partidos empatados, los partidos perdidos, los goles a favor y los
* goles en contra. Se mostrarán las puntuaciones de todos los
* equipos en el orden en el que se inscribieron.
*
**************************************************************************/
void Campeonato::MostrarPuntuaciones()
{
    int i;
    
    cout << setw(3);
    cout << "POS";
    cout << setw(11);
    cout << "Equipo";
    cout << setw(3);
    cout << "PJ";
    cout << setw(3);
    cout << "PG";
    cout << setw(3);
    cout << "PE";
    cout << setw(3);
    cout << "PP";
    cout << setw(3);
    cout << "GF";
    cout << setw(3);
    cout << "GC";
    cout << setw(7);
    cout << "Puntos";
    cout << endl;

//    OrdenarQuickSortTablaPorPuntaje();
    
    for (i = 0; i < equipos.size(); i++)
    {
        cout << setw(3);
        cout << i + 1;
        equipos[i].MostrarDatosEquipos();
        cout << endl;
    }
}

/****************** Campeonato::MostrarResultados() *********************/ /**
*
* Muestra la tabla de resultados, en la que se indican únicamente los
* partidos disputados y los goles marcados por los equipos.
*
**************************************************************************/
void Campeonato::MostrarResultados()
{
    int i = 0;
    
    for (i = 0; i < partidos.size(); i++)
    {
        cout << partidos[i];
    }

}

/***************** Campeonato::Finalizado ********************/ /**
*
* A partir del número de equipos que participan en el campeonato y
* del listado de partidos, devuelva verdadero si se han jugado todos
* los partidos o falso en caso contrario.
*
* @retval true  Si se jugaron todos los partidos
* @retval false Si no se jugaron todos los partidos
*
**************************************************************************/
bool Campeonato::Finalizado()
{
    bool fin = false;
    //El número de partidos jugados es igual a combinaciones de los equipos
    //inscritos agrupados de 2 en 2. Partidos_totales = (num_equipos * num_equipos-1) / 2
    //siempre que se hayan inscrito al menos 2 equipos.
    
    if ((equipos.size() > 1) && (partidos.size() == equipos.size()*(equipos.size()-1)/2))
        fin = true;
    
    return fin;
}

/******************** Campeonato::BuscarSecuencialeEquipo ******************/ /**
*
* Busca si hay un equipo repetido en el vector de equipos del campeonato
*
* @param[in] nom_equipo Equipo a buscar en el campeonato
*
* @retval true  Si se consiguio el equipo en el campeonato
* @retval false Si no se consiguio el equipo en el campeonato
*
**************************************************************************/
bool Campeonato::BuscarSecuencialEquipo(string nom_equipo)
{
    int i;
    bool enc = false;
    string nom_aux;
    
    i = 0;
    while (i < equipos.size())
    {
        nom_aux = equipos[i].DevolverNombre();
        if (nom_aux == nom_equipo)
            enc = true;
        
        i = i + 1;
    }
    
    return enc;
}

/******************** Campeonato::BuscarSecuencialPartido ******************/ /**
*
* Busca si hay un partido repetido en el vector de partidos del campeonato
*
* @param[in] partido Partido a buscar en el campeonato
*
* @retval true  Si se consiguio el Partido en el Campeonato
* @retval false Si no se consiguio el Partido en el Campeonato
*
**************************************************************************/
bool Campeonato::BuscarSecuencialPartido(Partido partido)
{
    int i;
    bool enc = false;
    
    i = 0;
    while (i < partidos.size())
    {
        if (partidos[i].DevolverEquipo1() == partido.DevolverEquipo1() &&
            partidos[i].DevolverEquipo2() == partido.DevolverEquipo2() &&
            partidos[i].DevolverGoles(partidos[i].DevolverEquipo1()) == partido.DevolverGoles(partido.DevolverEquipo1()) &&
            partidos[i].DevolverGoles(partidos[i].DevolverEquipo2()) == partido.DevolverGoles(partido.DevolverEquipo2())   )
            enc = true;
        
        i = i + 1;
    }
    
    return enc;
}

/******************** Campeonato::ActualizarTabla ******************/ /**
*
* Gestiona la actualizacion de la tabla de puntuaciones
*
* @param[in] partido Partido con el que se va actualizar la tabla
*
**************************************************************************/
void Campeonato::ActualizarTabla(Partido partido)
{
    int g_equipo_1, g_equipo_2;
    
    if (partido.DevolverGoles(partido.DevolverEquipo1()) > partido.DevolverGoles(partido.DevolverEquipo2()))
    {
        g_equipo_1 = 3;
        g_equipo_2 = 0;
    }
    else if (partido.DevolverGoles(partido.DevolverEquipo1()) == partido.DevolverGoles(partido.DevolverEquipo2()))
    {
        g_equipo_1 = 1;
        g_equipo_2 = 1;
    }
    else
    {
        g_equipo_1 = 0;
        g_equipo_2 = 3;
    }
    
    ActualizarDatos(partido.DevolverEquipo1(), partido.DevolverGoles(partido.DevolverEquipo1()), partido.DevolverGoles(partido.DevolverEquipo2()), g_equipo_1);
    
    ActualizarDatos(partido.DevolverEquipo2(), partido.DevolverGoles(partido.DevolverEquipo2()), partido.DevolverGoles(partido.DevolverEquipo1()), g_equipo_2);
}

/******************** Campeonato::ActualizarTabla ******************/ /**
*
* Gestiona la actualizacion de la tabla de puntuaciones
*
* @param[in] nombre     Nombre del equipo a buscar
* @param[in] g_favor    Goles a favor del equipo a buscar
* @param[in] g_contra   Goles en contra al equipo a buscar
* @param[in] puntos     Puntos adquiridos por el equipo
*
**************************************************************************/
void Campeonato::ActualizarDatos(string nombre, int g_favor, int g_contra, int puntos)
{
    int i;
    bool enc = false;
    string nom_aux;
    
    i = 0;
    while (i < equipos.size() && enc == false)
    {
        nom_aux = equipos[i].DevolverNombre();
        if (nom_aux == nombre)
        {
            enc = true;
            equipos[i].ModificarGoles(g_favor, g_contra);
            equipos[i].ModificarPuntajeYPartidos(puntos);
        }
        
        i = i + 1;
    }
}

/********* Campeonato::OrdenarQuickSortTablaPorPuntaje *********//**
*
* Ordena un vector de equipos mediante el metodo de particion
*
*//*************************************************************/
void Campeonato::OrdenarQuickSortTablaPorPuntaje()
{
    Particion(equipos[0].DevolverPuntaje(), equipos[equipos.size() - 1].DevolverPuntaje());
}

/******************* Campeonato::Particion *****************//**
*
* Ordena un vector mediante el metodo de particion
*
* @param[in] izq    Borde/Limite izquierdo del vector
* @param[in] der    Borde/Limite derecho del vector
*
*//*************************************************************/
void Campeonato::Particion(int izq, int der)
{
    int i, j, piv;
    Equipo aux;
    
    i = izq;
    j = der;
    piv = equipos[(izq + der) / 2].DevolverPuntaje();
    
    while (i <= j)
    {
        while ( equipos[i].DevolverPuntaje() < piv )
        {
            i++;
        }
        
        while ( equipos[j].DevolverPuntaje() > piv)
        {
            j--;
        }
        
        if (i < j)
        {
            aux  = equipos[i];
            equipos[i] = equipos[j];
            equipos[j] = aux;
            i++;
            j--;
        }
        else if (i == j)
        {
            i++;
            j--;
        }
    }
    
    if (der > i)
    {
        Particion(i, der);
    }
    
    if (izq < j)
    {
        Particion(izq, j);
    }
}

/******************* Campeonato::EquiposDisponibles() *****************//**
*
* Muestra solo el nombre de los equipos disponibles
*
*//*************************************************************/
void Campeonato::EquiposDisponibles()
{
    int i;
    
    for (i = 0; i < equipos.size(); i++)
    {
        cout << "Equipo " << i + 1 << ": " << equipos[i].DevolverNombre() << endl;
    }
}

/******************* Campeonato::DevolverNombreEquiposDisponibles *****************//**
*
* Devuelve el nombre de los equipos disponibles
*
* @param[in] i Indice del vector donde esta el nombre del equipo
*
* @return Nombre del equipo
*
*//*************************************************************/
string Campeonato::DevolverNombreEquiposDisponibles(int i)
{
    return equipos[i].DevolverNombre();
}
