/******* Carta.cpp **************************************************/ /**
*
* @file Carta.cpp
*
* Implementacion de los metodos de la clase Carta
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 21/04/2018
*
***************************************************************************/
#include "Carta.h"

/****************************** Carta::Carta() **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase Carta
*
****************************************************************************/
Carta::Carta()
: palo('D'), numero(0)
{}

/****************************** Carta::PutPalo ************************/ /**
*
* Asigna palo a la carta
*
* @param[in] x Palo ha asignar a la carta
*
****************************************************************************/
void Carta::PutPalo(char x)
{
    if (x == 'O' || x == 'C' || x == 'E' || x == 'B' )
    {
        palo = x;
    }
}

/****************************** Carta::PutNumero ************************/ /*
*
* Asigna número a la cara
*
* @param[in] x Numero ha asignar a la carta
*
****************************************************************************/
void Carta::PutNumero(int x)
{
   if(x > 0 && x < 13)
   {
       numero = x;
   }
}

/****************************** Carta::GetPalo ************************/ /**
*
* Devuelve el palo de la carta
*
* @return Palo de la carta
*
****************************************************************************/
char Carta::GetPalo()
{
    return palo;
}

/****************************** Carta::GetNumero ************************/ /**
*
* Devuelve el numero de la carta
*
* @return Numero de la carta
*
****************************************************************************/
int Carta::GetNumero()
{
    return numero;
}

/************* ostream & operator<< (ostream &, Carta ) **************/ /**
*
*  Sobrecarga del operador '<<' para motrar la información de una Carta
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      carta   objeto Carta que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
ostream & operator<< (ostream & salida, Carta carta)
{
    salida << carta.palo << carta.numero;
    
    return salida;
}
