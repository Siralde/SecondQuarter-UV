
/******* Pr6_Pila.h ****************************************************/ /**
 *
 * @file Pr6_Pila.h
 *
 * Fichero de cabecera de la clase Pila (estatica)
 *
 * @version 1.0
 * @author Jesus V. Albert
 * @date 16/04/2018
 *  
 ***************************************************************************/

#ifndef _PILA_H
#define _PILA_H

#include "Carta.h"

/**
 * @brief Clase para el manejo de Pilas
 *
 * Clase para manejar la informacion de Pilas.
 * Estan implementadas las operaciones basicas y se ha a�adido la sobrecarga
 * del operador '<<' para poder mostrar el contenido completo de la pila por
 * pantalla
 */
class Pila
{
    public:
        typedef Carta Valor;
        
        // Constructores
        Pila ();
        
        /// Metodos de modificacion de la Pila
        bool Apilar (Valor);
        bool Desapilar ();

        // Metodos de consulta de la Pila
        bool CimaPila (Valor &);
        bool PilaVacia ();

        // Sobrecarga del operador '<<'
        friend ostream & operator<< (ostream &, Pila);
        
    private:
        /**
         * Numero de elementos maximo que podremos poner en la pila
         * Como esta pila se va a utilizar para la gestion de barajas de cartas,
         * es el numero maximo de cartas de una baraja
         */
        static const int MAX_CARTAS = 48;
        
        /**
         * Tipo auxiliar para guardar la informacion contenida en la Pila
         */
        typedef Valor Vector[MAX_CARTAS];
        
        Vector datos;  ///< Vector donde guardaremos los elementos de la Pila
        
        /**
         * Indice que indica la posicion donde esta la informacion de la cima
         * de la pila
         */
        int cima;
};

#endif

