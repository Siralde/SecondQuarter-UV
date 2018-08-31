/******* Pr7_Cola.h ****************************************************/ /**
 *
 * @file Pr7_Cola.h
 *
 * @brief Interfaz del TAD Cola que guarda elementos de tipo Paciente
 *
 * Interfaz del TAD Cola que guarda elementos de tipo Paciente
 *
 * @version 1.0
 * @author  Miguel Angel Gamón
 *
 * @date    25-04-2018
 *
 */ /***********************************************************************/

#ifndef _COLA_H_
#define _COLA_H_

#include <iostream>
#include "Pr7_Paciente.h"

/*
 * Interfaz del TAD Cola que guarda elementos de tipo Paciente
 */
class Cola
{
    public:
        // Consutructor por defecto
        Cola ();

        // Consutructor con argumentos
        Cola (unsigned int);

        // Constructor de copia
        Cola (const Cola&);

        // Destructor
        ~Cola ();

        // Operador de asignacion de cola
        const Cola& operator= (const Cola&);

        // Almacena un elemento al final de la cola
        void Encolar (Paciente);

        // Elimina el elemento situado al inicio de la cola
        bool Desencolar ();

        // Devuelve el elemento situado al inicio de la cola
        bool PrimeroCola (Paciente &);

        // Determina si la cola tiene o no elementos almacenados
        bool ColaVacia () const;

        // Establece el identificador de la cola
        void EstablecerIdentificador (unsigned int);

        // Devuelve el número de elementos de la cola
        unsigned int NumeroElementos () const;

        // Devuelve una copia de la cola con los elementos en orden inverso
        Cola InvertirCola () const;

        // Operacion para escribir informacion en un stream
        friend ostream & operator<< (ostream &, const Cola &);

    private:
        struct Nodo;
        typedef Nodo* Puntero;
    	
        /**
         * Registro nodo para la construccion de los elementos de la lista dinamica
         */
        struct Nodo
        {
            Paciente info;  ///< Dato (Paciente)
            Puntero sig;    ///< Puntero al siguiente elemento de la cola
        };
	
        Puntero inicio;              ///< Puntero al inicio de la cola	
        Puntero fin;                 ///< Puntero al fin de la cola		
        unsigned int identificador;  ///< Identificador de la cola
        unsigned int n_elementos;    ///< Número de elementos de la cola

        void Vaciar ();
        void Copiar (const Cola&);
};

#endif

