/************************ Solitario.h *********************//**
*
* @file Solitario.h
*
* Fichero de cabecera/interfaz de la clase Solitario
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 21/04/2018
*
*//*********************************************************/
#ifndef _SOLITARIO_H
#define _SOLITARIO_H

#include "Pr6_Pila.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;


/*
 * @brief Clase para del Juego Solitario
 *
*/

/** Clase para manejar la informacion del juego Solitario
 */
class Solitario
{
    public:
        Solitario();
        void IniciaJuego();
        void MoverCarta();
        void Sacar5Mas();
        bool JuegoFinalizado();
        void MostrarTapete();
    private:
        /*
         * Numero de elementos maximo que podremos poner en la pila
         * Como esta pila se va a utilizar para la gestion de barajas de cartas,
         * es el numero maximo de cartas de una baraja
         */
        static const int MAX_MAZOS = 13;
        typedef Pila pilas[MAX_MAZOS];
        pilas mazos;
    
        /*
         * Funciones Auxilares
         */
        void Barajar();
        bool Validar(int, int);
};
#endif /* Solitario_hpp */
