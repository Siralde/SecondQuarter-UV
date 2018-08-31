/****** Media.h **************************************************/ /**
 *
 * @file Media.h
 *
 * @brief Fichero de cabecera de la clase Media
 *
 * @version 1.0
 * @author Vicente Cerverón
 * @date 26-04-2018
 */ /**************************************************************************/

#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>
#include "Tiempo.h"

using namespace std;

/**
 * Clase Media conjunto de datos de un archivo multimedia
 */
class Media
{
    public:
        Media ();
        Media (string, string, string, Tiempo);
        bool SetTitulo(string);
        bool SetInfo(string);
        bool SetRuta(string);
        bool SetDuracion(Tiempo);
        string GetTitulo();
        string GetInfo();
        string GetRuta();
        Tiempo GetDuracion();
        
        //sobrecargas
        friend istream& operator>> (istream&, Media&);
        friend ostream& operator<< (ostream&, Media); 

        //funciones amigas        
        friend void MostrarVersion(ostream&, Media, string);
        
    private:
        string titulo;
        string info; // información complementaria sobre el Media
        string ruta;
        Tiempo duracion;
};

#endif
