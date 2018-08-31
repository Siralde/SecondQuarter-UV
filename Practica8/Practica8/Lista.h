/****** Lista.h **************************************************/ /**
*
* @file Lista.h
*
* @brief Fichero de cabecera de la clase Lista
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12-05-2018
*/ /**************************************************************************/

#ifndef _LISTA_H_
#define _LISTA_H_

#include "Media.h"
#include <iostream>
using namespace std;

/** Interfaz de la clase Lista */
class Lista
{
    public:
        // Constructor por defecto, copia y destructor
        Lista();
        // Destructor
        ~Lista();
        // Constructor de Copia
        Lista(const Lista &);
        // Operador de asignacion
        const Lista & operator= (const Lista &);
    
        // Funciones sobre el elemento de la lista
        void InsertarElementoDespues(Media);
        void InsertarElementoAntes(Media);
        void InsertarElementoAlFinal(Media);
        bool EliminarElemento();
        bool ConsultarElemento(Media &);
        bool MoverElementoAlFinal();
        int DevuelvePosicion();
        int DevuelveTotalDeElementos();
    
        // Funciones sobre el pto de interes de la lista
        bool ListaVacia();
        void IrAInicio();
        bool Avanzar();
        bool Retroceder();
        bool FinalLista();
        void Vaciar();
    
        // SobreCargas de Flujo
//        friend istream& operator>> (istream&, Lista&);
        friend ostream& operator<< (ostream&, Lista);
    
    private:
        // Implementacion de los Nodos
        struct Nodo;
        typedef Nodo* Puntero;
        struct Nodo
        {
            int num;
            Media info;
            Puntero sig;
            Puntero ant;
        };
        Puntero cab, pto;

        // Funciones Auxiliares
        void Copiar(const Lista&);
        bool ActualizarPosicion();
    
        // Informacion complementaria
        int total;
        Tiempo duracion_total;
};

#endif

