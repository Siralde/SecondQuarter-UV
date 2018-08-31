/******* Pr7_ColaPrioridad.h ****************************************************/ /**
*
* @file Pr7_ColaPrioridad.h
*
* @brief Interfaz del TAD ColaPrioridad
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 05/05/2018
*
*/ /*************************************************************************/

#ifndef _COLAPRIORIDAD_hpp
#define _COLAPRIORIDAD_hpp

#include "Pr7_Cola.h"
#include "Pr7_Paciente.h"
#include <vector>
#include <iostream>
using namespace std;

/*
 * Interfaz del TAD ColaPrioridad que guarda y gestiona las diferentes colas
 * que conforman a la clases ColaPrioridad
 */
class ColaPrioridad
{
    public:
        ColaPrioridad();
        ColaPrioridad(int);
    
        bool Encolar(Paciente, int);
        bool Desencolar();
        bool PrimeroCola(Paciente&);
        bool ColaVacia();
    
        //Operador sobrecargado para salida de datos
        friend ostream& operator<< (ostream &, ColaPrioridad);

    private:
        vector<Cola> prioridades;
};

#endif 
