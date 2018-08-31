/************************ Contenedor.cpp *********************//*
*
* @file Contenedor.cpp
*
* Implementacion de los metodos de la clase contenedor
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 06/03/2018
*
*//*************************************************************/

#include "Contenedor.h"

/***************** Contendor::Contenedor() ********************//*
*
* Constructor por defecto de la clase contenedor
*
*//*************************************************************/
Contenedor::Contenedor()
:ancho(0), largo(0), profundidad(0),transporte(0), l_paquete(0), codigo("Sin Asignar")
{}

/*** Contendor::Contenedor(float, float, float, char, float) *****//*
*
* Constructor con argumentos de la clase contenedor
*
* @param[in] a      Ancho a asignar
* @param[in] l      Largo a asignar
* @param[in] p      Profundidad a asignar
* @param[in] t      Transporte a asignar
* @param[in] l_p    l_paquete a asignar
*
*//*****************************************************************/
Contenedor::Contenedor(float a, float l, float p, char t, float l_p)
: ancho(a), largo(l), profundidad(p), transporte(t), l_paquete(l_p), codigo("Sin Asignar")
{}

/************************ Contendor::PutAncho **********************//**
*
* Asigna el ancho del contenedor
*
* @param[in] a  Ancho a asignar
*
*//*******************************************************************/
void Contenedor::PutAncho(float a)
{
    ancho = a;
}

/************************ Contendor::PutLargo **********************//**
*
* Asigna el largo del contenedor
*
* @param[in] l  Largo a asignar
*
*//*******************************************************************/
void Contenedor::PutLargo(float l)
{
    largo = l;
}

/********************* Contenedor::PutProfundidad *******************//**
*
* Asigna la profundidad del contenedor
*
* @param[in] p Profundidad a Asignar
*
*//*******************************************************************/
void Contenedor::PutProfundidad(float p)
{
    profundidad = p;
}

/***************** Contendor::PutTransporte ******************//**
*
* Asigna el tipo de transporte del envio
*
* @param[in] t Tipo de transporte
*
*//****************************************************************/
void Contenedor::PutTransporte(char t)
{
    transporte = t;
}

/******************** Contendor::PutCodigoEnvio ******************//**
*
* Asigna el codigo de envio del paquete
*
* @param[in] pais  Codigo de envio a asignar
*
*//**************************************************************/
void Contenedor::PutCodigoEnvio(string pais)
{
    string c = GenerarCodigoEnvio(pais);
    
    codigo = c;
}

/*************** Contendor::PutLargoPaquete **************//**
*
* Asigna el largo de un paquete
*
* @param[in] l_p  Largo a asignar
*
*//********************************************************/
void Contenedor::PutLargoPaquete(float l_p)
{
    l_paquete = l_p;
}

/************ Contenedor::GetAncho ************//**
*
* Devuelve el ancho del contenedor
*
* @return Ancho del contenedor
*
*//************************************************/
float Contenedor::GetAncho()
{
    return ancho;
}

/************ Contenedor::GetLargo ************//**
*
* Devuelve el largo del contenedor
*
* @return Largo del contenedor
*
*//************************************************/
float Contenedor::GetLargo()
{
    return largo;
}

/************ Contenedor::GetProfundidad ************//**
*
* Devuelve la profundidad del contenedor
*
* @return Profundidad del contenedor
*
*//************************************************/
float Contenedor::GetProfundidad()
{
    return profundidad;
}

/************ Contenedor::GetTransporte ************//**
*
* Devuelve el tipo de transporte del envio
*
* @return Tipo de transporte del envio
*
*//************************************************/
char Contenedor::GetTransporte()
{
    return transporte;
}

/************ Contenedor::GetCodigoEnvio ************//**
*
* Devuelve el codigo de envio
*
* @return Codigo de envio
*
*//************************************************/
string Contenedor::GetCodigoEnvio()
{
    return codigo;
}

/*********** Contenedor::GetLadoPaquete ************//**
*
* Devuelve el lado del paquete
*
* @return Lado del paquete
*
*//************************************************/
float Contenedor::GetLadoPaquete()
{
    return l_paquete;
}

/************************* Contenedor::GenerarCodigoEnvio **********************//**
*
* Devuelve un codigo alfanumerico aleatorio donde el primer digito sea una letra,
* los 8 siguientes sean numeros
*
* @param[in] pais Pais que gestiona el envio
*
* @return Codigo de Envio
*
*//********************************************************************************/
string Contenedor::GenerarCodigoEnvio(string pais)
{
    string codigo_e, n;
    int num, resto;
    char letra;
    
    num = GenerarNumeroOchoCifras();
    resto = num % 23;
    letra = TablaAsignacion(resto);
    n = to_string(num);
    
    codigo_e = letra + n + pais;
    
    return codigo_e;
}

/***************************** Contenedor::TablaAsignacion **************************//**
*
* Asigna una letra a un numero
*
* @param[in] num Numero a evaluar
*
* @return Letra de la tabla de asignacion
*
*//********************************************************************************/
char Contenedor::TablaAsignacion(int num)
{
    string abecedario = "TRWAGMYFPDXBNJZSQVHLCKE";
    
    return abecedario[num];
}

/************ Contenedor::PrintInfo ************//**
*
* Muestra la informacion por pantalla
*
*//************************************************/
void Contenedor::PrintInfo()
{
    int cant_paquetes;
    
    cant_paquetes = CalcularPaquetes();
    
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
    cout << "\tCantidad de paquetes: " << cant_paquetes << endl;
    cout << "Paquete:" << endl;
    cout << "\tCodigo Envio: " << codigo << endl;
    cout << "\tDimension de paquete(1 Lado): " << l_paquete << " metros";
    cout << "\n-------------------------------------------\n";
    cout << "\t\t FIN DE INFORMACION ";
    cout << "\n-------------------------------------------\n";
}

/************ Contenedor::GenerarNumeroOchoCifras ************//**
*
* Genera un numero de 8 cifras
*
* @return Numero de 8 cifras
*
*//************************************************************/
int Contenedor::GenerarNumeroOchoCifras()
{
    static std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> dis (Potencia (10, 8 - 1), Potencia (10, 8) - 1);
    
    return dis (gen);
}

/************ Contenedor::Potencia ***************************//**
*
* Resuelve una potencia
*
* @param[in] base Numero a elevar
* @param[in] exp  Cantidad de veces que hay que multiplicar la base
*
* @return Potencia
*
*//*************************************************************/
unsigned int Contenedor::Potencia(int base, unsigned int exp)
{
    int res = 1;
    
    for (unsigned int i = 0; i < exp; i++)
        res *= base;
    
    return res;
}

/************ Contenedor::CalcularPaquetes *******************//**
*
* Calcula la cantidad de paquetes que caben en el contenedor
*
* @return Cantidad de paquetes que caben en el contenedor
*
*//*************************************************************/
int Contenedor::CalcularPaquetes()
{
    int c_ancho, c_largo, c_hondo;
    
    c_ancho = ancho / l_paquete;
    c_largo = largo / l_paquete;
    c_hondo = profundidad / l_paquete;
    
    return (c_ancho * c_largo * c_hondo);
}

/************ Contenedor::MayorVolumen ******************//**
*
* Indica cual de los dos contenedores tiene mayor capacidad
*
* @param[in] x Contendor
*
* @return Contenedor con mayor capacidad
*
*//*************************************************************/
Contenedor Contenedor::MayorVolumen(Contenedor x)
{
    float total1, total2;
    Contenedor z;
    
    total1 = this->ancho * this->largo * this->profundidad;
    total2 = x.ancho * x.largo * x.profundidad;
    
    if (total1 > total2)
    {
        z = *this;
    }
    else
        z = x;
    
    return z;
}
