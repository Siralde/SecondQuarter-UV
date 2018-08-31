
/******* Pr2_Coche.h ***************************************************/ /**
 *
 * @file Pr2_Coche.h
 *
 * Fichero de cabecera de la clase Coche
 *
 * @version 1.0
 * @author Vicente Cerveron
 * @date 20/02/2018
 *  
 ***************************************************************************/

#ifndef _COCHE_H_
#define _COCHE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Clase para el manejo de Coche
 *
 * Clase para manejar la informacion de coches.
  */
class Coche
{
    public:
        // Constructor por defecto
        Coche();

		// Operacion para devolver información de la montaña
		string DevuelveMatricula();
		//string DevuelveMarca();
        //string DevuelveModelo();	
        //void DevuelveFecha(int & dia, int & mes, int & anyo);
        //void DevuelvePropietario(string & nom, string & ape1, string & ape2);
		
		// Operacion para modificar información de la montaña
		void PonMatricula(string);
        //void PonMarca(string);
		//void PonModelo(string);
		//void PonFecha(int dia, int mes, int anyo);
		//void PonPropietario(string nom, string ape1, string ape2);

        // Operacion de salida para la escritura de datos por un stream
		friend ostream& operator<< (ostream &, Coche);

        // Operacion de entrada para leer datos desde un stream
		friend istream& operator>> (istream &, Coche &);

    private:       
        // Atributos propios de un Coche:
        string matricula;           ///< Matricula del vehiculo, formato 0000AAA
        string marca;               ///< Marca del vehidulo
        string modelo;              ///< Modelo del vehiculo
        int dia, mes, anyo;         ///< Componentes de la Fecha en que la empresa adquirio el vehiculo
        string nom, ape1, ape2;     ///< Datos del propietario del vehiculo
};

#endif
