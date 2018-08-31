/**
 * @file Pr6.cpp
 *
 * @brief Juego: Solitario.
 *
 * Esta aplicacion gestiona el Juego Solitario
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 21/04/2018
 */

#include "Solitario.h"
#include <iostream>
using namespace std;

/**
 * Funcion principal
 */
int main (void)
{
    int op;
    bool finalizado = false;
    Solitario s;
    
    s.IniciaJuego();
    s.MostrarTapete();
    do
    {
        cout << "\n********************************\n";
        cout << "\t\tMENU";
        cout << "\n********************************\n";
        cout << "1. Mover una carta.\n";
        cout << "2. Sacar 5 más de la Baraja.\n";
        cout << "3. Iniciar un nuevo juego.\n";
        cout << "4. Finalizar el juego.\n";
        cout << "Opcion: ";
        cin >> op;
        
        switch (op)
        {
            case 1:
                s.MoverCarta();
                s.MostrarTapete();
                finalizado = s.JuegoFinalizado();
                break;
            case 2:
                s.Sacar5Mas();
                s.MostrarTapete();
                break;
            case 3:
                s.IniciaJuego();
                s.MostrarTapete();
                break;
            case 4:
                s.MostrarTapete();
                finalizado = true;
                cout << endl;
            default:
                break;
        }
        
    }
    while (finalizado == false && (op > 0 || op < 5));
    
    cout << endl;
    
    return 0;
}

