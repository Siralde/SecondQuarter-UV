/**
 * @file Pr3_ver_1_4.cpp
 *
 * @brief Practica 3: Contenedores.
 *
 * Desarrollo de la practica 3 del laboratorio de programacion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 07/03/2018
 */

#include "Contenedor.h"

int main (void)
{
    Contenedor c1, mas_grande;
    Contenedor c2(100, 100, 50, 'D', 5);
    float largo, ancho, profundidad, l_p;
    char transporte;
    string codigo;
    
    cout << "TAREA 1\n";
    cout << "Parte 1 y 2:";
    c1.PrintInfo();
    c2.PrintInfo();
    
    cout << "\nParte 3:\n";
    cout << "A continuacion asignale los valores a el contenedor 1:\n";
    cout << "\tContenedor:\n";
    cout << "\t\tLargo: ";
    cin >> largo;
    c1.PutLargo(largo);
    cout << "\t\tAncho: ";
    cin >> ancho;
    c1.PutAncho(ancho);
    cout << "\t\tProfundidad: ";
    cin >> profundidad;
    c1.PutProfundidad(profundidad);
    cout << "\t\tTipo de Transporte(T terrestre, M marítimo, D desconocido): ";
    cin >> transporte;
    c1.PutTransporte(transporte);
    cout << "\t\tDame las dos primeras letras del pais a enviar el paquete en mayusculas: ";
    cin >> codigo;
    c1.PutCodigoEnvio(codigo);
    cout << "\t\tDame el largo de un lado del paquete: ";
    cin >> l_p;
    c1.PutLargoPaquete(l_p);
    c1.PrintInfo();
    
    cout << "\nParte 4:\n";
    largo = c2.GetLargo();
    ancho = c2.GetAncho();
    profundidad = c2.GetProfundidad();
    codigo = c2.GetCodigoEnvio();
    transporte = c2.GetTransporte();
    l_p = c2.GetLadoPaquete();
    cout << "\n-------------------------------------------\n";
    cout << "\t\t INFORMACION ";
    cout << "\n-------------------------------------------\n";
    cout << "Contenedor: " << endl;
    cout << "\tLargo: " << largo << " metros" << endl;
    cout << "\tAncho: " << ancho << " metros" << endl;
    cout << "\tProfundidad: " << profundidad << " metros" << endl;
    cout << "\tTipo de Transporte: ";
    switch (transporte)
    {
        case 'T':
            cout << "Terreste" << endl;
            break;
        case 'M':
            cout << "Maritimo" << endl;
        default:
            cout << "Desconocido" << endl;
            break;
    }
    cout << "Paquete:" << endl;
    cout << "\tCodigo Envio: " << codigo << endl;
    cout << "\tDimension de paquete(1 Lado): " << l_p << " metros";
    cout << "\n-------------------------------------------\n";
    cout << "\t\t FIN DE INFORMACION ";
    cout << "\n-------------------------------------------\n";
    
    cout << "\n\n--------------------------------------------------------\n";
    cout << "\t\tCALCULAMOS CUAL CONTENEDOR TIENE MAYOR VOLUMEN";
    cout << "\n----------------------------------------------------------";
    mas_grande = c1.MayorVolumen(c2);
    mas_grande.PrintInfo();
    
    cout << endl;
    
    return 0;
}

