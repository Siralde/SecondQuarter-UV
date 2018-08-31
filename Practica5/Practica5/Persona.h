/************************ Persona.h *********************//**
*
* @file Persona.h
*
* Fichero de cabecera/interfaz de la clase persona
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*//*********************************************************/

#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <iostream>
using namespace std;
/*
 * @brief Clase para el manejo de las personas
 *
 * Clase para manejar la informacion de una persona
 */
class Persona
{
    public:
        Persona();
        Persona(string, string);
        string GetNombre();
        string GetDNI();
        void SetNombre(string);
        void SetDNI(string);
        //Operador sobrecargado para mostrar la persona
        friend ostream& operator<< (ostream &, Persona);
    private:
        string dni, nombre;
};

#endif
