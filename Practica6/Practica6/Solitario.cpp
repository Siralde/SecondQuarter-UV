/******************************* Solitario.cpp ***************************/ /**
*
* @file Solitario.cpp
*
* Implementacion de los metodos de la clase Solitario
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 21/04/2018
*
***************************************************************************/
#include "Solitario.h"
#include <cstdlib>  //Equivalente C, #include <stdlib.h>
#include <ctime>    //Equivalente C, #include <time.h>

/********************** Solitario::Solitario() ***********************/ /**
*
* Debe rellenar la pila 0 (Baraja) con las 48 cartas de la Baraja
* y las restantes pilas estarán vacías.
*
**************************************************************************/
Solitario::Solitario()
{
    int i,j;
    Carta baraja_espanola;
    
    /*
     * Relleno la Baraja = mazo[0] con todas las cartas
     */
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 12; j++)
        {
            switch (i)
            {
                case 0:
                    baraja_espanola.PutNumero(j + 1);
                    baraja_espanola.PutPalo('O');
                    mazos[0].Apilar(baraja_espanola);
                    break;
                case 1:
                    baraja_espanola.PutNumero(j + 1);
                    baraja_espanola.PutPalo('C');
                    mazos[0].Apilar(baraja_espanola);
                    break;
                case 2:
                    baraja_espanola.PutNumero(j + 1);
                    baraja_espanola.PutPalo('E');
                    mazos[0].Apilar(baraja_espanola);
                    break;
                case 3:
                    baraja_espanola.PutNumero(j + 1);
                    baraja_espanola.PutPalo('B');
                    mazos[0].Apilar(baraja_espanola);
                    break;
            }//Fin switch
        }//Fin for j
    }//Fin for i

}

/************************ Solitario::IniciaJuego ***********************/ /**
*
* Sitúa todas las cartas que pueda haber en las distintas pilas en la
* pila de la Baraja, a continuación, se procede a barajar esas cartas,
* y reparte las cartas según la posición inicial del juego: una en cada
* uno de los siete mazos y 5 en la pila Auxiliar.
*
**************************************************************************/
void Solitario::IniciaJuego()
{
    int i, j;
    Carta carta;
    
    /*
     * Sitúa todas las cartas que pueda haber en las distintas pilas en la
     * pila de la Baraja
     */
    for (i = 1; i < MAX_MAZOS; i++)
    {
        while (mazos[i].CimaPila(carta))
        {
            mazos[0].Apilar(carta);
            mazos[i].Desapilar();
        }
    }
    
    /*
     * Se barajean las cartas
     */
    Barajar();
    
    /*
     * Reparte las cartas según la posición inicial del juego
     * 0: Pila con la Baraja.
     * 1 - 7: Pilas con los 7 mazos.
     * 8 – 11: Pilas con los Palos.
     * 12: Pila auxiliar.
     */
    for (i = 1; i < MAX_MAZOS; i++)
    {
        if (i > 0 && i < 8)
        {
            mazos[0].CimaPila(carta);
            mazos[i].Apilar(carta);
            mazos[0].Desapilar();
        }
        else if(i == 12)
        {
            for (j = 0; j < 5; j++)
            {
                mazos[0].CimaPila(carta);
                mazos[i].Apilar(carta);
                mazos[0].Desapilar();
            } //Fin For j
        }//Fin else if
    }//Fin for
}

/************************ Solitario::MoverCarta ***********************/ /**
*
* Solicita al jugador que indique la pila de la que cogerá la carta y
* la pila donde la depositará. Comprobará que sea un movimiento
* válido (según la descripción de la introducción), si lo es,
* realizará el movimiento, en caso contrario, mostrará un mensaje
* de movimiento inválido al jugador.
*
**************************************************************************/
void Solitario::MoverCarta()
{
    int ini, final;
    
    do
    {
        cout << "\nSolo introducir valor entre el 1 y el 12\n";
        cout << "Dame el mazo o palo de donde cogeras la carta: ";
        cin >> ini;
        cout << endl;
        cout << "Dame el mazo o palo donde depositaras la carta: ";
        cin >> final;
        cout << endl;
    }
    while ( (ini == final) || (ini < 1 || ini > 12) || (final < 1 || final > 12) );
    
    if (!Validar(ini, final))
    {
        cout << "\nMovimiento no valido, vuelva a intentar.\n";
    }
}

/************************ Solitario::Sacar5Mas ***********************/ /**
*
* Pasa 5 cartas de la pila de la Baraja a la pila Auxiliar.
* Si quedan menos de 5 pasará las que queden en la Baraja.
* Si la Baraja está vacía primero volcará la pila Auxiliar en
* la Baraja y a continuación pasará las 5 primeras a la pila Auxiliar.
*
**************************************************************************/
void Solitario::Sacar5Mas()
{
    Carta carta;
    int i;
    
    Barajar();
    
    /*
     * Baraja está vacía primero volcará la pila Auxiliar en
     * la Baraja
     */
    if (mazos[0].PilaVacia() == true)
    {
        while (mazos[12].PilaVacia() == false)
        {
            mazos[12].CimaPila(carta);
            mazos[0].Apilar(carta);
            mazos[12].Desapilar();
        }
        for (i = 0; i < 5; i++)
        {
            mazos[0].CimaPila(carta);
            mazos[12].Apilar(carta);
            mazos[0].Desapilar();
        }
    }
    else
    {
        i = 0;
        while (mazos[0].PilaVacia() == false && i < 5)
        {
            mazos[0].CimaPila(carta);
            mazos[12].Apilar(carta);
            mazos[0].Desapilar();
            i++;
        }
    }
}

/*********************** Solitario::JuegoFinalizado ******************/ /**
*
* Comprueba que en los palos esten los doce de cada palo para poder concluir
* si se ha finalizado el juego
*
* @retval true  El juego ya ha terminado
* @retval false El juego no ha terminado
*
**************************************************************************/
bool Solitario::JuegoFinalizado()
{
    bool finalizado = false;
    int i, cont_doces = 0;
    Carta carta;
    
    for (i = 8; i <= 11; i++)
    {
        mazos[i].CimaPila(carta);
        if(carta.GetNumero() == 12)
            cont_doces++;
    }
    
    if (cont_doces == 4)
    {
        finalizado = true;
    }
    
    return finalizado;
}

/*********************** Solitario::MostrarTapete *********************/ /**
*
* Muestra como esta el tapete del juego en ese momento
*
**************************************************************************/
void Solitario::MostrarTapete()
{
    int i;
    
    cout << "\nTAPETE";
    cout << "\n=============================\n";
    
    for(i = 1; i < MAX_MAZOS; i++)
    {
        if (i <= 7) // Mazos
        {
            cout << "(0" << i << ") Mazo" << i << ": " << mazos[i] << endl;
            if (i == 7)
            {
                cout << "=============================\n";
            }
        }
        else if (i >= 8 && i <= 11) //Palos
        {
            if (i <= 9)
            {
                cout << "(0" << i << ") Palo" << i - 7 << ": " << mazos[i] << endl;
            }
            else
                cout << "(" << i << ") Palo" << i - 7 << ": " << mazos[i] << endl;
        }
        else if (i == 12) // Auxiliar y Baraja
        {
            cout << "=============================\n";
            cout << "(" << i << ") Auxiliar: " << mazos[i];
            cout << "\n(00) Baraja: " << mazos[0];
            cout << "\n=============================\n";
        }
    }
}


/************************* Solitario::Barajar ************************/ /**
*
* Se encarga de barajar las cartas de la baraja.
*
**************************************************************************/
void Solitario::Barajar()
{
    srand (int(time(NULL)));
    
    vector<Carta> v_aux;
    Carta carta;
    size_t pos_1, pos_2, pos;
    
    if (mazos[0].PilaVacia() == false)
    {
        while (mazos[0].CimaPila (carta) )
        {
            v_aux.push_back (carta);
            mazos[0].Desapilar ();
        }
        for (unsigned int i = 0; i < 1000; i++)
        {
            pos_1 = rand () % v_aux.size ();
            pos_2 = rand () % v_aux.size ();
            carta = v_aux[pos_1];
            v_aux[pos_1] = v_aux[pos_2];
            v_aux[pos_2] = carta;
        }
        
        for (pos = 0; pos < v_aux.size (); pos++)
            mazos[0].Apilar (v_aux[pos]);
    }
    
    return;
}


/*************************** Solitario::Validar ************************/ /**
*
* Se encargará de comprobar si el movimiento de una carta de
* la pila indicada por el primer parámetro a la del segundo
* es válido o no
*
* @param[in] inicio     Donde esta la carta
* @param[in] final      A donde se quiere llevar la carta
*
* @retval true  Si se puede mover la carta
* @retval false No se puede mover la carta
*
**************************************************************************/
bool Solitario::Validar(int inicio, int final)
{
    bool valido = false;
    Carta a_poner, en_mazo;
    char palo_a_poner, palo_en_mazo;
    int num_a_poner, num_en_mazo;
    
    mazos[inicio].CimaPila(a_poner);
    mazos[final].CimaPila(en_mazo);
    
    num_a_poner = a_poner.GetNumero();
    palo_a_poner = a_poner.GetPalo();
    
    num_en_mazo = en_mazo.GetNumero();
    palo_en_mazo = en_mazo.GetPalo();
    
    // Mover carta hacia las pilas de los palos (Oros, Copas, Espadas y Bastos)
    if (final >= 8)
    {
        /*
         * Cuando se encuentran vacías solo se puede mover el “as” (B1, C1, E1, O1)
         * del palo correspondiente desde la cima de cualquier pila, excepto
         * desde la Baraja.
         */
        if ( mazos[final].PilaVacia() == true && num_a_poner == 1 )
        {
            mazos[final].Apilar(a_poner);
            mazos[inicio].Desapilar();
            valido = true;
        }
        /*
         * Cuando contienen alguna carta solo se puede colocar otra del mismo palo y
         * una unidad superior desde la cima de cualquier pila, excepto desde
         * la Baraja.
         */
        else if ( !mazos[final].PilaVacia() && palo_en_mazo == palo_a_poner && (num_en_mazo + 1) == num_a_poner )
        {
            mazos[final].Apilar(a_poner);
            mazos[inicio].Desapilar();
            valido = true;
        }
    }
    // Mover carta hacia las pilas de trabajo (mazo1, ..., mazo7)
    else
    {
        /*
         * Cuando están vacías se puede mover cualquier carta
         * desde la cima de cualquier pila, excepto desde la Baraja.
         */
        if ( mazos[final].PilaVacia() == true )
        {
            mazos[final].Apilar(a_poner);
            mazos[inicio].Desapilar();
            valido = true;
        }
        /*
         * Cuando contienen alguna carta solo se puede colocar
         * otra de distinto palo y una unidad inferior procedente
         * de la cima de cualquier pila, excepto desde la Baraja.
         */
        else if ( !mazos[final].PilaVacia() && palo_en_mazo != palo_a_poner && (num_en_mazo - 1) == num_a_poner )
        {
            mazos[final].Apilar(a_poner);
            mazos[inicio].Desapilar();
            valido = true;
        }
    }
    
    return valido;
}

