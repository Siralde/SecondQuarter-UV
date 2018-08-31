/**
 * @file Pr4_ver4.cpp
 *
 * @brief Campeonato Universitario de Futbito.
 *
 * Esta aplicacion gestiona el Campeonato Universitario de Futbito
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 18/03/2018
 */
#include "Campeonato.h"
#include "Partido.h"
#include <iostream>
using namespace std;

void RegistrarEquipo(Campeonato &);
void RegistrarPartido(Campeonato &);
void IngresarAportacion(Campeonato &);
void RealizarGastos(Campeonato &);
void MostrarEquipos(Campeonato);
void MostrarPartidos(Campeonato);
void MostrarPuntaje(Campeonato);

/**
 * Funcion principal
 */
int main (void)
{
    Campeonato etse("ETSE-UV");
    bool finalizar_app = false;
    int opcion, i = 0, j = 0;
    
    do
    {
        cout << "1. Registrar equipo." << endl;
        cout << "2. Registrar un resultado/partido." << endl;
        cout << "3. Ingresar Aportación." << endl;
        cout << "4. Realizar Gasto." << endl;
        cout << "5. Mostrar Equipos." << endl;
        cout << "6. Mostrar tabla de resultados." << endl;
        cout << "7. Mostrar tabla de puntuación." << endl;
        cout << "8. Finalizar." << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                cout << endl;
                RegistrarEquipo(etse);
                cout << endl;
                i++;
                break;
            case 2:
                if (i > 1 && !etse.Finalizado())
                {
                    cout << endl;
                    RegistrarPartido(etse);
                    cout << endl;
                    j++;
                }
                else if (etse.Finalizado())
                    cout << "\nYa se jugaron todos los partidos\n\n";
                else
                    cout << "\nDebe Registrar al menos dos equipos para introducir un partido\n\n";
                break;
            case 3:
                    cout << endl;
                    IngresarAportacion(etse);
                    cout << endl;
                break;
            case 4:
                    cout << endl;
                    RealizarGastos(etse);
                    cout << endl;
                break;
            case 5:
                if (i > 0)
                {
                    cout << endl;
                    MostrarEquipos(etse);
                    cout << endl;
                }
                else
                    cout << "\nDebe Registrar al menos un equipo para poder mostrarlo\n\n";
                break;
            case 6:
                if (i > 0 && j > 0)
                {
                    cout << endl;
                    MostrarPartidos(etse);
                    cout << endl;
                }
                else
                    cout << "\nDebe Registrar al menos dos equipos y un partido para poder mostrar los resultados\n\n";
                break;
            case 7:
                if (i > 0)
                {
                    cout << endl;
                    MostrarPuntaje(etse);
                    cout << endl;
                }
                else
                    cout << "\nDebe Registrar al menos un equipo para mostrar la tabla de posiciones\n\n";
                break;
            case 8:
                finalizar_app = true;
                break;
            default:
                break;
        }
    }
    while (!finalizar_app);
//1    while (!finalizar_app && !etse.Finalizado());
    
    if (etse.Finalizado())
    {
        cout << "\n****************************************************************************\n";
        cout << "\n Todos los partidos han sido jugado por lo tanto se ha finalizado el torneo\n";
        cout << "\n****************************************************************************\n";
    }
    
    return 0;
}

/************************* RegistrarEquipo **************************/ /**
*
* Registra un equipo en el campeonato
*
* @param[in] c Campeonato
*
*****************************************************************************/
void RegistrarEquipo(Campeonato & c)
{
    Equipo team;
    string nombre, capitan;
    
    cout << "Nombre del Equipo: ";
    cin >> nombre;
    team.AsignarNombre(nombre);
    cout << "Nombre del Capitan del Equipo: ";
    cin >> capitan;
    cout << "El capitan ya fue registrado en el equipo, no hace falta volverlo a introducir\n";
    cin >> team;
    team.AsignarCapitan(capitan);
    
    c.InscribirEquipo(team);
}

/************************* RegistrarPartido **************************/ /**
*
* Registra un partido en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void RegistrarPartido(Campeonato & c)
{
    Partido p;
    int e1, e2;
    string equipo1, equipo2;
    int goles1, goles2;
    
    cout << "Equipos Disponibles: " << endl;
    c.EquiposDisponibles();
    
    cout << "Dame el numero de un equipo: ";
    cin >> e1;
    e1 -= 1;
    equipo1 = c.DevolverNombreEquiposDisponibles(e1);
    cout << "Goles marcados: ";
    cin >> goles1;
    cout << "Dame el numero del otro equipo: ";
    cin >> e2;
    e2 -= 1;
    equipo2 = c.DevolverNombreEquiposDisponibles(e2);
    cout << "Goles marcados: ";
    cin >> goles2;
    
    p.AsignarEquipos(equipo1, equipo2);
    p.AsignarResultado(goles1, goles2);
    
    c.AgregarResultadoPartido(p);
}

/************************* IngresarAportacion **************************/ /**
*
* Registra una aportacion en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void IngresarAportacion(Campeonato & c)
{
    int aportacion, saldo;
    
    saldo = c.DevolverSaldo();
    cout << "Saldo Actual: " << saldo << endl;
    
    cout << "Cifra de Aportacion: ";
    cin >> aportacion;
    c + aportacion;
    
    saldo = c.DevolverSaldo();
    cout << "Saldo Actualizado: " << saldo << endl;
}

/************************* RealizarGastos **************************/ /**
*
* Registra una aportacion en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void RealizarGastos(Campeonato & c)
{
    int gasto, saldo;
    
    saldo = c.DevolverSaldo();
    cout << "Saldo Actual: " << saldo << endl;
    
    cout << "Cifra del Gasto realizado: ";
    cin >> gasto;
    c - gasto;
    
    saldo = c.DevolverSaldo();
    cout << "Saldo Actualizado: " << saldo << endl;
}

/************************* MostrarEquipos **************************/ /**
*
* Registra una aportacion en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void MostrarEquipos(Campeonato c)
{
    cout << c;
}

/************************* MostrarPartidos **************************/ /**
*
* Registra una aportacion en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void MostrarPartidos(Campeonato c)
{
    c.MostrarResultados();
}

/************************* MostrarPuntaje **************************/ /**
*
* Registra una aportacion en el campeonato
*
* @param[in] c Campeonato
*
***************************************************************************/
void MostrarPuntaje(Campeonato c)
{
    cout << "\n***LOS EQUIPOS SERAN MOSTRADOS EN ORDEN DE INSCRIPCION NO DE PUNTUACION****\n";
    c.MostrarPuntuaciones();
}
