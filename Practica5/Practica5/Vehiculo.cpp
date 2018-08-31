/*********************** Vehiculo.cpp ************************/ /**
*
* @file Vehiculo.cpp
*
* Implementacion de los metodos de la clase Vehiculo
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 12/04/2018
*
*******************************************************************/
#include "Vehiculo.h"

/************************* Vehiculo::Vehiculo **************************/ /**
*
*  Asigna valores iniciales 'coherentes' a los distintos atributos de la
*  clase Vehiculo
*
**************************************************************************/
Vehiculo::Vehiculo()
: matricula(""), marca(""), modelo(""), num_ruedas(0), num_pasajeros(1), propietario()
{}

/********************* Vehiculo::Vehiculo *********************/ /**
*
* Asigna valores proposionados a los atributos de la clase Vehiculo
*
* @param[in] mtl    Matricula del Vehiculo
* @param[in] mc     Marca del Vehiculo
* @param[in] mdl    Modelo del Vehiculo
* @param[in] nr     Numero de ruedas
* @param[in] np     Numero de pasajeros
*
******************************************************************/
Vehiculo::Vehiculo(string mtl, string mc, string mdl, int nr, int np)
: matricula(mtl), marca(mc), modelo(mdl), num_ruedas(nr), num_pasajeros(np), propietario()
{}

/********************* Vehiculo::GetMatricula ******************/ /**
*
* Devuelve la matricula del Vehiculo
*
* @return Matricula del Vehiculo
*
******************************************************************/
string Vehiculo::GetMatricula()
{
    return matricula;
}

/********************* Vehiculo::GetMarca *********************/ /**
*
* Devuelve la marca del Vehiculo
*
* @return Marca del Vehiculo
*
******************************************************************/
string Vehiculo::GetMarca()
{
    return marca;
}

/********************* Vehiculo::GetModelo *********************/ /**
*
* Devuelve el modelo del Vehiculo
*
* @return Modelo del Vehiculo
*
******************************************************************/
string Vehiculo::GetModelo()
{
    return modelo;
}

/********************* Vehiculo::GetRuedas ******************/ /**
*
* Devuelve el numero de ruedas del Vehiculo
*
* @return Numero de ruedas del Vehiculo
*
******************************************************************/
int Vehiculo::GetRuedas()
{
    return num_ruedas;
}

/****************** Vehiculo::GetPasajeros *******************/ /**
*
* Devuelve el numero de los pasajeros que caben en un Vehiculo
*
* @return Pasajeros de un Vehiculo
*
******************************************************************/
int Vehiculo::GetPasajeros()
{
    return num_pasajeros;
}

/******************** Vehiculo::GetPropietaria *****************/ /**
*
* Devuelve el propietario de un Vehiculo
*
* @return Propietario del Vehiculo
*
******************************************************************/
Persona Vehiculo::GetPropietaria()
{
    return propietario;
}

/****************** Vehiculo::SetMatricula *****************/ /**
*
* Asigna el numero de matricula de un vehiculo
*
* @param[in] mtl Numero de matricula
*
******************************************************************/
void Vehiculo::SetMatricula(string mtl)
{
    matricula = mtl;
}

/********************* Vehiculo::SetMarca *********************/ /**
*
* Asigna la marca de un Vehiculo
*
* @param[in] mc Marca de Vehiculo
*
******************************************************************/
void Vehiculo::SetMarca(string mc)
{
    marca = mc;
}

/********************* Vehiculo::SetModelo *********************/ /**
*
* Asigna el modelo de un vehiculo
*
* @param[in] mdl Modelo de Vehiculo
*
******************************************************************/
void Vehiculo::SetModelo(string mdl)
{
    modelo = mdl;
}

/********************* Vehiculo::SetRuedas *********************/ /**
*
* Asigna el numero de ruedas de un Vehiculo
*
* @param[in] nr Numero de ruedas
*
******************************************************************/
void Vehiculo::SetRuedas(int nr)
{
    num_ruedas = nr;
}

/********************* Vehiculo::SetPasajeros *********************/ /**
*
* Asigna el numero de pasajeros de un Vehiculo
*
* @param[in] np Numero de pasajeros
*
******************************************************************/
void Vehiculo::SetPasajeros(int np)
{
    num_pasajeros = np;
}

/********************* Vehiculo::SetPropietaria *********************/ /**
*
* Asigna los datos del propetario del Vehiculo
*
* @param[in] pptr Objeto de Persona que se refiere al propetario
*
******************************************************************/
void Vehiculo::SetPropietaria(Persona pptr)
{
    propietario.SetDNI(pptr.GetDNI());
    propietario.SetNombre(pptr.GetNombre());
}

/*** ostream & operator<< (ostream &, Vehiculo) *************************/ /**
*
*  Sobrecarga del operador '<<' para sacar la información de un Vehiculo
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida      stream por el que vamos a sacar la informacion.
*  @param [in]      vehiculo    objeto Vehiculo que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************/
ostream& operator<< (ostream & salida, Vehiculo vehiculo)
{

    salida << "\tMatricula: " << vehiculo.GetMatricula();
    salida << endl;
    salida << "\tMarca: " << vehiculo.GetMarca();
    salida << endl;
    salida << "\tModelo: " << vehiculo.GetModelo();
    salida << endl;
    salida << "\tNumero de Ruedas: " << vehiculo.GetRuedas();
    salida << endl;
    salida << "\tNumero de Pasajeros: " << vehiculo.GetPasajeros();
    salida << endl;
    salida << "\tPropietario: " << vehiculo.GetPropietaria();
    
    return salida;
}

/*** istream & operator>> (istream &, Vehiculo &) ************************/ /**
*
*  Sobrecarga del operador '>>' para obtener la información de un Vehiculo
*  desde un stream (fichero, teclado, ...).
*
*  @param [in,out]  entrada     stream del que vamos a obtener la informacion.
*  @param [out]     vehiculo    objeto Vehiculo que queremos rellenar con la
*                               informacion obtenida del stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /**********************************************************************/
istream& operator>> (istream & entrada, Vehiculo & vehiculo)
{
    getline(entrada, vehiculo.matricula);
    getline(entrada, vehiculo.marca);
    getline(entrada, vehiculo.modelo);
    entrada >> vehiculo.num_ruedas;
    entrada >> vehiculo.num_pasajeros;
    
    return entrada;
}


/**************************** QuitarRParaMac ************************/ /**
*
* Quita el caracter "\r" y "\0" que ocasionan problemas a la hora de leer
* en el sistema operativo MacOS
*
*  @param [in,out] x    Cadena de caracteres
*
*/ /**********************************************************************/
void QuitarRParaMac(string & x)
{
    char ultimo_caracter;
    size_t cant_caracteres;
    string arreglo;
    
    cant_caracteres = x.length();
    ultimo_caracter = x[cant_caracteres];
    if ( ultimo_caracter == '\r' || ultimo_caracter == '\0')
    {
        arreglo = x.substr(0, cant_caracteres - 1);
        x = arreglo;
    }
}
