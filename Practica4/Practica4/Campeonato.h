/************************ Campeonato.h *****************//**
*
* @file Campeonato.h
*
* Fichero de cabecera/interfaz de la clase Campeonato
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
*//*******************************************************/

#ifndef _CAMPEONATO_H
#define _CAMPEONATO_H

#include "Partido.h"
#include "Equipo.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 * @brief Clase para el manejo de Campeonato
 *
 * Clase para manejar la informacion de un Campeonato
 */
class Campeonato
{
    public:
        Campeonato(string);
        //Funciones TAD
        bool InscribirEquipo(Equipo);
        bool AgregarResultadoPartido(Partido);
        int DevolverSaldo();
        void EquiposDisponibles();
        string DevolverNombreEquiposDisponibles(int);
        void MostrarPuntuaciones();
        void MostrarResultados();
        //SobreCarga de Operadores
        friend void operator+(Campeonato &, int);
        friend void operator-(Campeonato &, int);
        friend ostream& operator<<(ostream &, Campeonato);
        //Funcion De partidos jugados
        bool Finalizado();
    
    private:
        int saldo;
        string nombre;
        vector<Equipo> equipos;
        vector<Partido> partidos;
        void ActualizarTabla(Partido);
        void ActualizarDatos(string, int, int, int);
        void OrdenarQuickSortTablaPorPuntaje();
        void Particion(int, int);
        bool BuscarSecuencialEquipo(string);
        bool BuscarSecuencialPartido(Partido);
};

#endif
