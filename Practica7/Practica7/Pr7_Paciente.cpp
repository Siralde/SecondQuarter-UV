/******* Pr7_Paciente.cpp ***************************************************/ /**
*
* @file Pr7_Paciente.cpp
*
* Implementacion de los metodos de la clase Paciente
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 05-05-2018
*
*/ /*****************************************************************************/
#include "Pr7_Paciente.h"

int Potencia (int base, int exp);

/*********************** Paciente::Paciente() ***********************/ /**
*
* Asigna valores iniciales 'coherentes' a los distintos atributos de la
* clase Paciente
*
*************************************************************************/
Paciente::Paciente()
:nombre(""), apellido(""), edad(0), motivo(""), ticket(""), num_consulta(0)
{}

/*********************** Paciente::AsignarDatos ***********************/ /**
*
* Asigna los valores de nombre, apellidos, edad y motivo de consulta
* del Paciente.
*
* @param[in] nombre_paciente    Nombre del Paciente
* @param[in] apellido_paciente  Apellido del Paciente
* @param[in] edad_paciente      Edad del Paciente
* @param[in] motivo_consulta    Motivo de la consulta del Paciente
*
*************************************************************************/
void Paciente::AsignarDatos(string nombre_paciente, string apellido_paciente, int edad_paciente, string motivo_consulta)
{
    nombre = nombre_paciente;
    apellido = apellido_paciente;
    edad = edad_paciente;
    motivo = motivo_consulta;
}

/*********************** Paciente::GenerarTicket ***********************/ /**
*
* Genera un código de ticket a partir de las iniciales del nombre y del
* primer apellido del paciente y del número indicado como
* parámetro, con el formato “AB0001”.
*
* @param[in] numero Numero
*
*************************************************************************/
void Paciente::GenerarTicket(int numero)
{
    string cadena;
    
    // Primero las iniciales del nombre y del primer apellido
    if (!nombre.empty())
        ticket = nombre.substr(0, 1); 
    else
        ticket = '-';
    if (!apellido.empty())
        ticket += apellido.substr(0, 1);
    else
        ticket += '-';
    
    // El numero de paciente no puede ser mayor de 4 cifras
    numero = numero % Potencia(10, N_CAR_TICKET - 2);
    cadena = to_string (numero);
    
    // Rellenamos con ceros si el numero tiene menos de 4 cifras
    while (cadena.length() < N_CAR_TICKET - 2)
        cadena = '0' + cadena;
    
    ticket += cadena;
    
    return;

}

/******************** Paciente::DevuelveTicket *********************/ /*
*
* Devuelve el ticket del paciente.
*
*************************************************************************/
string Paciente::DevuelveTicket()
{
    return ticket;
}

/******************** Paciente::EstableceConsulta *********************/ /**
*
* Asigna el número de la consulta.
*
*************************************************************************/
void Paciente::EstableceConsulta(int numero)
{
    if (numero > 0)
    {
        num_consulta = numero;
    }
}

/******************** Paciente::DevuelveConsulta() *********************/ /**
*
* Devuelve el número de la consulta.
*
*************************************************************************/
int Paciente::DevuelveConsulta()
{
    return num_consulta;
}

/*********** istream & operator>> (istream &, Paciente &) ************************/ /**
*
*  Sobrecarga del operador '>>' para obtener la información de un Paciente
*  desde un stream (fichero, teclado, ...).
*
*  @param [in,out]  entrada     stream del que vamos a obtener la informacion.
*  @param [out]     paciente    objeto Paciente que queremos rellenar con la
*                               informacion obtenida del stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /************************************************************************************/
istream& operator>> (istream & entrada, Paciente & paciente)
{
    cout << "Introduce el nombre del paciente: ";
    entrada >> paciente.nombre;
    entrada.ignore();
    cout << "Introduce el apellido del paciente: ";
    getline(entrada, paciente.apellido);
    cout << "Introduce la edad del paciente: ";
    entrada >> paciente.edad;
    entrada.ignore();
    cout << "Introduce el motivo de la consulta: ";
    getline(entrada,paciente.motivo);
    cout << endl;
    
    return entrada;
}

/********************* ostream & operator<< (ostream &, Paciente ) *********************/ /**
*
*  Sobrecarga del operador '<<' para motrar la información de un Paciente
*  por un stream (fichero, consola, ...).
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      paciente   objeto Paciente que queremos sacar por el stream.
*
*  @return  El stream modificado tras su utilizacion
*
*/ /****************************************************************************************/
ostream& operator<< (ostream & salida, Paciente paciente)
{
    salida << "Nombre: ";
    salida << paciente.nombre << " " << paciente.apellido;
    salida << endl;
    salida << "Edad: " << paciente.edad;
    salida << endl;
    salida << "Motivo de Consulta: " << paciente.motivo;
    salida << endl;
    salida << "Numero de Ticket: " << paciente.DevuelveTicket();
    salida << endl;

    return salida;
}

/************************** Potencia ********************************/ /**
*
*  Calcula la potencia de una expresion
*
*  @param [in]  base    Base de la expresion
*  @param [in]  exp     Exponente de la expresion
*
*  @return  Resultado de la potencia
*
*/ /**************************************************************/
int Potencia (int base, int exp)
{
    int i;
  
    for(i = 0; i < exp; i++)
    {
        base = base * base;
    }
    
    return base;
}
