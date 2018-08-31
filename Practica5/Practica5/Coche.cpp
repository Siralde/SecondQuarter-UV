/*********************** Coche.cpp ************************/ /**
*
* @file Coche.cpp
*
* Implementacion de los metodos de la clase Coche
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*******************************************************************/

#include "Coche.h"

/************************* Coche::Coche **************************/ /**
*
* Asigna valores iniciales 'coherentes' a los distintos
* atributos de la clase Coche
*
***********************************************************************/
Coche::Coche()
: Vehiculo(), tipo_coche("Indeterminado")
{}

/********************* Coche::Coche ************************/ /**
*
* Asigna valores proposionados a los atributos de la clase Coche
*
* @param[in] matricula      Matricula del Vehiculo
* @param[in] marca          Marca del Vehiculo
* @param[in] modelo         Modelo del Vehiculo
* @param[in] n_ruedas       Numero de ruedas
* @param[in] n_pasajeros    Numero de pasajeros
* @param[in] tipo           Tipo de Coche
*
******************************************************************/
Coche::Coche(string matricula, string marca, string modelo, int n_ruedas, int n_pasajeros, string tipo)
: Vehiculo(matricula, marca, modelo, n_ruedas, n_pasajeros), tipo_coche(tipo)
{
    SetTipoCoche(tipo_coche);
}

/********************* Coche::GetTipoCoche ******************/ /**
*
* Devuelve el tipo de Coche
*
* @return Tipo de Coche
*
******************************************************************/
string Coche::GetTipoCoche()
{
    return tipo_coche;
}

/********************* Coche::SetTipoCoche ******************/ /**
*
* Asigna el Tipo de Coche
*
* @param[in] tipo Tipo de Coche
*
******************************************************************/
void Coche::SetTipoCoche(string tipo)
{
    if (tipo == "deportivo" || tipo == "Deportivo" || tipo == "DEPORTIVO")
    {
        tipo_coche = "Deportivo";
    }
    else if (tipo == "berlina" || tipo == "Berlina" || tipo == "BERLINA")
    {
        tipo_coche = "Berlina";
    }
    else if (tipo == "turismo" || tipo == "Turismo" || tipo == "TURISMO")
    {
        tipo_coche = "Turismo";
    }
    else
        tipo_coche = "Indeterminado";
}

/*** ostream & operator<< (ostream &, Coche) *************************/ /**
*
*  Sobrecarga del operador '<<' para sacar la información de un Vehiculo
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      coche   objeto Coche que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************/
ostream& operator<< (ostream & salida, Coche coche)
{
    salida << "\nCoche:";
    salida << endl;
    salida << (Vehiculo)coche;
    salida << endl;
    salida << "\tTipo: " << coche.GetTipoCoche();
    salida << endl;
    salida << "--------------------------------------------------------------------";
    
    return salida;
}


/*** istream & operator>> (istream &, Coche &) ************************/ /**
*
*  Sobrecarga del operador '>>' para obtener la información de un Coche
*  desde un stream (fichero, teclado, ...).
*
*  @param [in,out]  entrada     stream del que vamos a obtener la informacion.
*  @param [out]     coche       objeto Coche que queremos rellenar con la
*                               informacion obtenida del stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
istream& operator>> (istream & entrada, Coche & coche)
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
    entrada >> coche.tipo_coche;
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
    
    coche.SetMatricula(matricula);
    coche.SetMarca(marca);
    coche.SetModelo(modelo);
    coche.SetRuedas(num_ruedas);
    coche.SetPasajeros(num_pasajeros);
    
    nombre_propietario_final = nombre_propietario + " " + apel1_propietario + " " + apel2_propietario;
    propietario.SetNombre(nombre_propietario_final);
    propietario.SetDNI(dni_propietario);
    coche.SetPropietaria(propietario);
    
    
    return entrada;
}
