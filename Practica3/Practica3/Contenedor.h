/************************ Contenedor.h *********************//**
*
* @file Contenedor.h
*
* Fichero de cabecera/interfaz de la clase contenedor
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 06/03/2018
*
*//*************************************************************/

#ifndef Contenedor_h
#define Contenedor_h

#include <random>
#include <string>
#include <iostream>
using namespace std;

/*
 * @brief Clase para el manejo de los contenedores
 *
 * Clase para manejar la informacion de un contenedor
 */
class Contenedor
{
    public:
        //Constructores
        Contenedor();
        Contenedor(float, float, float, char, float);
    
        //Metodos de determinacion de datos
        void PutAncho(float);
        void PutLargo(float);
        void PutProfundidad(float);
        void PutTransporte(char);
        void PutCodigoEnvio(string);
        void PutLargoPaquete(float);
    
        //Metodos de obtencion de datos
        float GetAncho();
        float GetLargo();
        float GetProfundidad();
        char GetTransporte();
        string GetCodigoEnvio();
        float GetLadoPaquete();
    
        //Otros
        void PrintInfo();
        string GenerarCodigoEnvio(string);
        Contenedor MayorVolumen (Contenedor);
    
    private:
    
        float ancho, largo, profundidad, l_paquete;
        //'T' terrestre, 'M' maritimo, 'D' desconocido
        char transporte;
        //Codigo identificativo del envio
        string codigo;
        // Genera un numero de 8 cifras
        int GenerarNumeroOchoCifras();
        unsigned int Potencia (int, unsigned int);
        char TablaAsignacion(int);
        int CalcularPaquetes();
};

#endif
