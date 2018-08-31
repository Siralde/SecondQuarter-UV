/************************ Equipo.h *********************//**
*
* @file Equipo.h
*
* Fichero de cabecera/interfaz de la clase Equipo
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
*//*******************************************************/

#ifndef _EQUIPO_H
#define _EQUIPO_H

#include <iomanip>  
#include <vector>
#include <iostream>
using namespace std;

/*
 * @brief Clase para el manejo de los equipos
 *
 * Clase para manejar la informacion de un equipo
 */
class Equipo
{
    public:
        Equipo();
        Equipo(string);
        void AsignarNombre(string);
        bool AsignarCapitan(string);
        string DevolverNombre();
        //Asignar Jugadores
        friend istream& operator>>(istream &, Equipo &);
        //Mostrar equipo
        friend ostream& operator<<(ostream&, Equipo);
        void ModificarGoles(int, int);
        void ModificarPuntajeYPartidos(int);
        int DevolverPuntaje();
        void MostrarDatosEquipos();
        
    private:
        string nombre_equipo, nombre_capitan;
        vector<string> nombre_jugadores;
        bool BusquedaSecuencialCapitan (vector<string>, string);
        int goles_favor, goles_contra;
        int partidos_jugados, partidos_ganados, partidos_perdidos, partidos_empatados;
        int puntuacion, numeros_jugadores;
};

#endif
