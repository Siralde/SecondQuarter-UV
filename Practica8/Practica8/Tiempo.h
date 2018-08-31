/****** Tiempo.h **************************************************/ /**
 *
 * @file Tiempo.h
 *
 * @brief Fichero de cabecera de la clase Tiempo
 *
 * @version 1.0
 * @author Vicente Cerverón
 * @date 26-04-2018
 */ /**************************************************************************/

#ifndef _TIEMPO_H_
#define _TIEMPO_H_

#include <iostream>

using namespace std;

/** Clase Tiempo para la gestión de tiempos */
class Tiempo
{
    public:
        Tiempo ();
        Tiempo (int, int, float);
        bool SetTiempo(int, int, float);
        int GetHoras();
        int GetMinutos();
        float GetSegundos();
        
        //sobrecargas
        friend istream& operator>> (istream&, Tiempo&); 
        friend ostream& operator<< (ostream&, Tiempo);
        friend void operator+=(Tiempo&, Tiempo);
        friend void operator-=(Tiempo&, Tiempo); 
        
    private:
        int horas;
        int minutos;
        float segundos;
};

#endif
