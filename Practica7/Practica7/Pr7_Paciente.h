/******* Pr7_Paciente.h ****************************************************/ /**
*
* @file Pr7_Paciente.h
*
* @brief Interfaz del TAD Paciente
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 05/05/2018
*
*/ /***********************************************************************/

#ifndef _PACIENTE_H
#define _PACIENTE_H

#include <iostream>
#include <string>
using namespace std;

const int N_CAR_TICKET = 6;

/*
 * Interfaz del TAD Paciente que guarda los datos del paciente y gestiona su
 * sus consultas
 */
class Paciente
{
    public:
        Paciente();
        
        void AsignarDatos(string nombre, string apellido, int edad, string motivo);
        void GenerarTicket(int);
        string DevuelveTicket();
        void EstableceConsulta(int);
        int DevuelveConsulta();
        
        //Operador sobrecargado para entrada de datos
        friend istream& operator>> (istream &, Paciente &);
        //Operador sobrecargado para salida de datos
        friend ostream& operator<< (ostream &, Paciente);
        
    private:
    //Nombre, Apellidos, Edad (número de años), Motivo de la consulta, Ticket generado al paciente, Nº de consulta asignada
        string nombre, apellido, motivo, ticket;
        int edad, num_consulta;
};

#endif
