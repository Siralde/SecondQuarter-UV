/************************ Partido.h *********************//**
*
* @file Partido.h
*
* Fichero de cabecera/interfaz de la clase Partido
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 18/03/2018
*
*//*********************************************************/

#ifndef _PARTIDO_H
#define _PARTIDO_H

#include <iomanip>      
#include <iostream>
using namespace std;

/*
 * @brief Clase para el manejo de los partidos
 *
 * Clase para manejar la informacion de un partido
 */
class Partido
{
    public:
        //Construtor
        Partido();
        //Metodos dados en clases
        void    AsignarEquipos(string, string);
        void    AsignarResultado(int, int);
        string  DevolverEquipo1();
        string  DevolverEquipo2();
        int     DevolverGoles(string);
        //Operadore SobreCargado para mostrar el partido
        friend ostream& operator<< (ostream &, Partido);
    
    private:
        string equipo_1, equipo_2;
        int goles_1, goles_2;
};

#endif
