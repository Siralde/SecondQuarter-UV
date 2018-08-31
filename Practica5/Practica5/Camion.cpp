/*********************** Camion.cpp ************************/ /**
*
* @file Camion.cpp
*
* Implementacion de los metodos de la clase Camion
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*******************************************************************/
#include "Camion.h"

/************************* Camion::Camion **************************/ /**
*
* Asigna valores iniciales 'coherentes' a los distintos
* atributos de la clase Coche
*
***********************************************************************/
Camion::Camion()
: Vehiculo(), carga(0)
{}

/********************* Coche::Coche ************************/ /**
*
* Asigna valores proposionados a los atributos de la clase Coche
*
* @param[in] mtl    Matricula del Vehiculo
* @param[in] mc     Marca del Vehiculo
* @param[in] mdl    Modelo del Vehiculo
* @param[in] n_r     Numero de ruedas
* @param[in] n_p     Numero de pasajeros
* @param[in] cg     Carga
*
******************************************************************/
Camion::Camion(string mtl, string mc, string mdl, int n_r, int n_p, float cg)
: Vehiculo(mtl, mc, mdl, n_r, n_p), carga(cg)
{}

/********************* Camion::GetCarga ******************/ /**
*
* Devuelve la matricula del Vehiculo
*
* @return Matricula del Vehiculo
*
******************************************************************/
float Camion::GetCarga()
{
    return carga;
}

/********************* Camion::SetCarga ******************/ /**
*
* Asigna los valores de la carga
*
* @param[in] cg Carga del camion
*
******************************************************************/
void Camion::SetCarga(float cg)
{
    carga = cg;
}

/*** ostream & operator<< (ostream &, Camion) *************************/ /**
*
*  Sobrecarga del operador '<<' para sacar la información de un Camion
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      camion  objeto Camion que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************/
ostream& operator<< (ostream & salida, Camion camion)
{
    salida << "Camion: ";
    salida << endl;
    salida << (Vehiculo)camion;
    salida << endl;
    salida << "\tCapacidad maxima de carga: " << camion.GetCarga() << " toneladas";
    salida << endl;
    salida << "--------------------------------------------------------------------\n";
    
    return salida;
}

/*** istream & operator>> (istream &, Camion &) ************************/ /**
*
*  Sobrecarga del operador '>>' para obtener la información de un Camion
*  desde un stream (fichero, teclado, ...).
*
*  @param [in,out]  entrada     stream del que vamos a obtener la informacion.
*  @param [out]     camion      objeto Camion que queremos rellenar con la
*                               informacion obtenida del stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
istream& operator>> (istream & entrada, Camion & camion)
{
    Persona propietario;
    string nombre_propietario, nombre_propietario_final;
    string apel1_propietario;
    string apel2_propietario;
    string dni_propietario;
    string matricula, marca, modelo;
    int num_ruedas, num_pasajeros;
  
    getline(entrada, matricula);
    QuitarRParaMac(matricula);
    
    getline(entrada, marca);
    getline(entrada, modelo);
    entrada >> num_ruedas;
    entrada >> num_pasajeros;
    entrada >> camion.carga;
    entrada.ignore();
    entrada.ignore();
    
    getline(entrada, nombre_propietario);
    QuitarRParaMac(nombre_propietario);
    
    getline(entrada, apel1_propietario);
    QuitarRParaMac(apel1_propietario);
    
    getline(entrada, apel2_propietario);
    QuitarRParaMac(apel2_propietario);
    
    getline(entrada, dni_propietario);
    QuitarRParaMac(dni_propietario);
    
    camion.SetMatricula(matricula);
    camion.SetMarca(marca);
    camion.SetModelo(modelo);
    camion.SetRuedas(num_ruedas);
    camion.SetPasajeros(num_pasajeros);
    
    nombre_propietario_final = nombre_propietario + " " + apel1_propietario + " " + apel2_propietario;
    propietario.SetNombre(nombre_propietario_final);
    propietario.SetDNI(dni_propietario);
    camion.SetPropietaria(propietario);
    
    return entrada;
}


