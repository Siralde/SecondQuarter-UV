/**
 * @file Pr7_Urgencias.cpp
 *
 * @brief Practica 7, Servicio de Urgencias Medicas
 *
 * Esta aplicacion gestiona la admisión y la atención de los pacientes
 * de un centro que tenga un Servicio de Urgencias Medicas
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 05/05/2018
 */

#include "Pr7_ColaPrioridad.h"
#include "Pr7_Cola.h"
#include "Pr7_Paciente.h"
#include <iostream>
using namespace std;

int NumeroAleatorio(int, int);
void RegistraPaciente(ColaPrioridad &, Paciente &, int);
void MostrarEspera(ColaPrioridad &);
void AtenderPaciente(ColaPrioridad &, Cola &);
void MostrarLlamadas(Cola &);

int main()
{
    ColaPrioridad pacientes(5);
    Cola atendidos;
    Paciente p;
    int op;
    bool finalizar = false;
    int num_paciente = 1;
    
    
    do
    {
        // Si la cola se vacia el conteo de los pacientes vuelve a comenzar
        if (pacientes.ColaVacia())
        {
            num_paciente = 1;
        }
        cout << "\n***************** MENU ********************\n";
        cout << "1. Registrar un paciente" << endl;
        cout << "2. Mostrar pacientes en espera" << endl;
        cout << "3. Atender a un paciente" << endl;
        cout << "4. Mostrar llamadas pacientes" << endl;
        cout << "5. Finalizar el programa" << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
        
        switch (op)
        {
            case 1:
                RegistraPaciente(pacientes, p, num_paciente);
                num_paciente++;
                cout << endl;
                break;
            case 2:
                MostrarEspera(pacientes);
                cout << endl;
                break;
            case 3:
                AtenderPaciente(pacientes, atendidos);
                cout << endl;
                break;
            case 4:
                MostrarLlamadas(atendidos);
                cout << endl;
                break;
            case 5:
                finalizar = true;
                cout << endl;
                break;
            default:
                cout << "Opcion invalida, vuelve a intentarlo";
                cout << endl;
                break;
        }
    }
    while (!finalizar);
    
    cout << endl;
    
    return 0;
}

/*************************** RegistraPaciente **************************/ /**
*
* Lee los datos de un paciente y genera un ticket para el mismo.
* El ticket se genera a partir de un contador de pacientes que van
* llegando al centro médico. Seguidamente, el paciente pasa a formar
* parte de la cola de pacientes en espera.
*
* @param[in] pacientes      Lista de espera
* @param[in] p              Paciente a registrar
* @param[in] num_paciente   Numero de llegada
*
*/ /**********************************************************************/
void RegistraPaciente(ColaPrioridad & pacientes, Paciente & p, int num_paciente)
{
    int prioridad;
    
    do
    {
        cout << "\n*************** Niveles de Prioridad ****************\n";
        cout << "1. Atención inmediata " << endl;
        cout << "2. Muy urgente " << endl;
        cout << "3. Urgente " << endl;
        cout << "4. Normal " << endl;
        cout << "5. No Urgente " << endl;
        cout << "\nIntroduce el nivel de prioridad del paciente: ";
        cin >> prioridad;
        
        if (prioridad < 1 || prioridad > 5)
        {
            cout << "\nNumero de prioridad incorrecto. Vuelve a intentar \n";
        }
    }
    while (prioridad < 1 || prioridad > 5);

    cin >> p;
    p.GenerarTicket(num_paciente);
    
    pacientes.Encolar(p, prioridad);
}

/*************************** MostrarEspera **************************/ /**
*
* Muestra todos los pacientes que están en la cola de espera.
*
* @param[in] l_espera Lista de espera
*
*/ /**********************************************************************/
void MostrarEspera(ColaPrioridad & l_espera)
{
    if(l_espera.ColaVacia())
        cout << "No hay ningun paciente en lista de espera " << endl;
    else
    {
        cout << "\n************** LISTA DE ESPERA ***************\n";
        cout << l_espera;
    }
}

/*************************** AtenderPaciente **************************/ /**
*
* Se llama al primer paciente de la cola (dejando de formar parte de ella)
* para ser atendido por un médico. El sistema muestra los datos del paciente
* y avisa de que puede pasar a la consulta indicada con número generado
* aleatoriamente entre 1 y 8.
*
* @param[in] pacientes Lista de espera
* @param[in] atendidos Lista de Atendidos
*
*/ /**********************************************************************/
void AtenderPaciente(ColaPrioridad & pacientes, Cola & atendidos)
{
    Paciente atender;
    int num_consulta;
    
    if(pacientes.ColaVacia())
        cout << "No hay ningun paciente para atender " << endl;
    else
    {
        pacientes.PrimeroCola(atender);
        pacientes.Desencolar();
        num_consulta = NumeroAleatorio(1, 8);
        atender.EstableceConsulta(num_consulta);
        cout << "\n************** Paciente a ser atendido ***************\n";
        cout << atender.DevuelveTicket() << "\tConsulta: " << atender.DevuelveConsulta();
        cout << endl;
        atendidos.Encolar(atender);
//        cout << atender;
    }
}

/*************************** MostrarLlamadas **************************/ /**
*
* Muestra la información del ticket y del número de consulta asignado
* del último paciente atendido, así como de los 4 anteriormente llamados.
*
* @param[in] atendidos Lista de Atendidos
*
*/ /**********************************************************************/
void MostrarLlamadas(Cola & atendidos)
{
    Paciente paciente;
    Cola aux;
    int i = 0;
    
    if (atendidos.ColaVacia())
    {
        cout << "No ha sido atendido ningun paciente." << endl;
    }
    else
    {
        if (atendidos.NumeroElementos() > 5)
        {
            atendidos.Desencolar();
        }
        
        aux = atendidos.InvertirCola();
        
        while (!aux.ColaVacia() && i < 5)
        {
            aux.PrimeroCola(paciente);
            if(i == 0)
            {
                cout << "\nLlamando:\n";
                cout << "-------------------" << endl;
                cout << paciente.DevuelveTicket() << "\tConsulta " << paciente.DevuelveConsulta();
                cout << endl;
                cout << "\nLlamandos anteriormente: \n";
                cout << "-------------------" << endl;
            }
            else
            {
                cout << paciente.DevuelveTicket() << "\tConsulta " << paciente.DevuelveConsulta();
                cout << endl;
            }
            aux.Desencolar();
            i++;
        }
    }
    
}

/************************ NumeroAleatorio *********************//**
*
* Genera un numero aletorio
*
* @param[in] min El numero mas pequeno
* @param[in] max El numero mas grande
*
* @return Numero aleatorio generado por la funcion
*
*//*************************************************************/
int NumeroAleatorio(int min, int max)
{
    int num;
    
    num = min + rand() % (max - min);
    
    return num;
}
