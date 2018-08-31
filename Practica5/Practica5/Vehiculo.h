/************************ Vehiculo.h *********************//**
*
* @file Vehiculo.h
*
* Fichero de cabecera/interfaz de la clase Vehiculo
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*//*********************************************************/

#ifndef _VEHICULO_H_
#define _VEHICULO_H_

#include "Persona.h"
#include <iostream>
using namespace std;

void QuitarRParaMac(string &);

/*
 * @brief Clase para el manejo de los vehiculos
 *
 * Clase para manejar la informacion de un vehiculo
 */
class Vehiculo
{
    public:
        Vehiculo();
        Vehiculo(string, string, string, int, int);
        string GetMatricula();
        string GetMarca();
        string GetModelo();
        int GetRuedas();
        int GetPasajeros();
        Persona GetPropietaria();
        void SetMatricula(string);
        void SetMarca(string);
        void SetModelo(string);
        void SetRuedas(int);
        void SetPasajeros(int);
        void SetPropietaria(Persona);
        //Operador sobrecargado para mostrar el vehiculo
        friend ostream& operator<< (ostream &, Vehiculo);
        friend istream& operator>> (istream &, Vehiculo &);
    private:
        string matricula, marca, modelo;
        int num_ruedas, num_pasajeros;
        Persona propietario;
};

#endif 
