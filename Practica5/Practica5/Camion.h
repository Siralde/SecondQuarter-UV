/************************ Camion.h *********************//**
*
* @file Camion.h
*
* Fichero de cabecera/interfaz de la clase Camion
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*//*********************************************************/

#ifndef _CAMION_H_
#define _CAMION_H_

#include "Vehiculo.h"
#include <iostream>
using namespace std;
/*
 * @brief Clase para el manejo de los Camiones
 *
 * Clase para manejar la informacion de un Camion
 */
class Camion: public Vehiculo
{
    public:
        Camion();
        Camion(string, string, string, int, int, float);
        float GetCarga();
        void SetCarga(float);
        //Operador sobrecargado para mostrar el camion
        friend ostream& operator<< (ostream &, Camion);
        friend istream& operator>> (istream &, Camion &);
    private:
        float carga;
};
#endif /* Camion_hpp */
