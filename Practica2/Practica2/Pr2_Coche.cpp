
/******* Pr2_Coche.cpp *************************************************/ /**
 *
 * @file Pr2_Coche.cpp
 *
 * Implementaci�n de los m�todos de la clase Coche
 * valida para cualquier tipo de final de linea \n o \r\n
 *
 * @version 1.0
 * @author Vicente Cerver�n
 * @date 22/02/2018
 *  
 ***************************************************************************/

#include "Pr2_Coche.h"

/*** Coche::Coche () **************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase
 *
 */ /**********************************************************************/
Coche::Coche ()
{
    /*
       No seria necesario iniciar los 'string' porque se inician de forma
       automatica a vacios en cuanto se declaran, como matricula = "";
    
        Si se quiere, podr�amos iniciarlos a valores 'est�ndar'
        matricula = "nnnnAAA";
        marca = "marca";
        modelo = "modelo";    
        ape1 = "xxx";
        ape2 = "yyy";
        nom = "nnn";
    */
    
    dia = 1;
    mes = 1;
    anyo = 2001;
}

/*** ostream & operator<< (ostream &, Coche ) ******************/ /**
 *
 *  Sobrecarga del operador '<<' para sacar la informaci�n de un Coche 
 *  por un stream (fichero, consola, ...).
 *
 *  @param [in/out]  salida  stream por el que vamos a sacar la informacion.
 *  @param [in]      coche  objeto Coche que queremos sacar por el stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
ostream & operator<< (ostream & salida, Coche coche)
{
    salida << coche.matricula;
    salida << " (" << coche.marca << "/" << coche.modelo << ") ";
    salida << coche.dia << "/" << coche.mes << "/" << coche.anyo;
    salida << " [" << coche.ape1 << " " << coche.ape2 << "," << coche.nom << "]" << endl;
    
    return salida;
}

/*** istream & operator>> (istream &, Coche &) ************************/ /**
 *
 *  Sobrecarga del operador '>>' para obtener la informaci�n de un Coche 
 *  desde un stream (fichero, teclado, ...).
 *
 *  @param [in/out]  entrada  stream del que vamos a obtener la informacion.
 *  @param [out]     coche  objeto Coche que queremos rellenar con la
 *                          informacion obtenida del stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
istream& operator>> (istream & entrada, Coche & coche)
{
char separador;
string final;
    
    entrada >> coche.anyo;
    entrada >> separador;
    entrada >> coche.mes;
    entrada >> separador;
    entrada >> coche.dia;
    entrada >> coche.matricula;
    getline(entrada, final);
    
    getline(entrada, coche.marca);
    getline(entrada, coche.modelo);
    
    getline(entrada, coche.nom);
    getline(entrada, coche.ape1);
    getline(entrada, coche.ape2);
    
    return entrada;       
}


/**********************************************************************/ /**
 *
 *  Devuelve la matr�cula del coche.
 *
 *  @return  el string con la matr�cula del coche.
 *
 */ /**********************************************************************/
 string Coche::DevuelveMatricula ()
 {
    return matricula;
 }
   
/**********************************************************************/ /**
 *
 *  Modifica la matr�cula del coche con la recibida como par�metro.
 *
 *  @param[in]  matric    nueva matricula del coche.
 *
 */ /**********************************************************************/
 void Coche::PonMatricula (string matric)
 {
    matricula = matric;
    
    return;
 }

