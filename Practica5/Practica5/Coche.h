/************************ Coche.h *********************//**
*
* @file Coche.h
*
* Fichero de cabecera/interfaz de la clase Coche
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*//*********************************************************/

#ifndef _COCHE_H_
#define _COCHE_H_

#include "Vehiculo.h"
#include <iostream>
using namespace std;
/*
 * @brief Clase para el manejo de los coches
 *
 * Clase para manejar la informacion de un coche
 */
class Coche: public Vehiculo
{
    public:
        Coche();
        Coche(string, string, string, int, int, string);
        string GetTipoCoche();
        void SetTipoCoche(string);
        //Operador sobrecargado para mostrar el coche
        friend ostream& operator<< (ostream &, Coche);
        friend istream& operator>> (istream &, Coche&);
    private:
        string tipo_coche;
};


#endif
