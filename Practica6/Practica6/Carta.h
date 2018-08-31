/******* Carta.h ****************************************************/ /**
*
* @file Carta.h
*
* Fichero de cabecera de la clase Carta
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 21/04/2018
*
***************************************************************************/
#ifndef _CARTA_H
#define _CARTA_H

#include <iostream>
using namespace std;

/**
 * @brief Clase para el manejo de Carta
 *
 * Clase para manejar la informacion de Carta.
 */
class Carta
{
    public:
        Carta();
        void PutPalo(char);
        void PutNumero(int);
        char GetPalo();
        int GetNumero();
        //muestra por pantalla la carta según formato PaloNumero
        friend ostream & operator << (ostream &, Carta);
    private:
        char palo; //'O'=oros, 'C'=copas, 'E'=espadas, 'B'=bastos
        int numero; //1..12
};
#endif
