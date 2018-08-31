/****** Lista.cpp ************************************************/ /**
*
* @file Lista.cpp
*
* @brief Implementacion de los metodos de la clase Lista
*
* @version 1.0
* @author Aldemaro Gonzalez
* @date 26-04-2018
*/ /****************************************************************/
#include <iomanip>
#include "Lista.h"

/************************* Lista::Lista *****************************/ /**
*
* Constructor por defecto de la clase lista
*
*/ /*******************************************************************/
Lista::Lista()
{
    Tiempo t;
    
    cab = new Nodo;
    cab->sig = cab;
    cab->ant = cab;
    pto = cab;
    cab->num = 0;
    total = 0;
    duracion_total = t;
}

/************************* Lista::Lista **************************/ /**
*
* Constructor de copia
*
* @param[in] ori Lista Original
*
*/ /*******************************************************************/
Lista::Lista(const Lista & ori)
{
    Tiempo t;
    //inicia la lista como vacía
    //y después copia
    cab = new Nodo;
    cab->sig = cab;
    cab->ant = cab;
    pto = cab;
    cab->num = 0;
    total = ori.total;
    duracion_total = t;
    Copiar (ori) ;
}

/************************* Lista::~Lista ******************************/ /**
*
* Destructor de la clase
*
*/ /*******************************************************************/
Lista::~Lista (void)
{
    Vaciar();
}

/******************** Lista::operator= ***************************/ /**
*
* Operador asignación
*
* @param[in] orig Lista Original
*
* @return Lista copiada
*
*/ /*****************************************************************/
const Lista & Lista::operator= (const Lista & orig)
{
    Vaciar();
    Copiar (orig);
    return (*this);
}

/***************** Lista::InsertarElementoAntes ********************/ /**
*
* Inserción de nuevos elementos delante del punto de interés
*
* @param[in] archivo Archivo multimedia
*
*/ /*******************************************************************/
void Lista::InsertarElementoAntes(Media archivo)
{
    Puntero q_aux;
    Tiempo t;
    
    // Sumamos el tiempo
    t = archivo.GetDuracion();
    duracion_total += t;
    
    q_aux = new Nodo;
    q_aux->info = archivo;
    q_aux->sig = pto;
    q_aux->ant = pto->ant;
    pto->ant->sig = q_aux;
    pto->ant = q_aux;
    
    ActualizarPosicion();
    total++;
}

/***************** Lista::InsertarElementoDespues ********************/ /**
*
* Inserción de nuevos elementos detras del punto de interés,
* excepto que el punto de interes este en la cabeza, si esta en
* cabeza lo colocara de ultimo
*
* @param[in] archivo Archivo multimedia
*
*/ /*******************************************************************/
void Lista::InsertarElementoDespues(Media archivo)
{
    Puntero q_aux ;
    Tiempo t;
    
    if (pto == cab)
    {
        InsertarElementoAntes(archivo);
    }
    else
    {
        // Sumamos el tiempo
        t = archivo.GetDuracion();
        duracion_total += t;
        
        q_aux = new Nodo;
        q_aux->info = archivo;
        q_aux->sig = pto->sig;
        q_aux->ant = pto;
        pto->sig->ant = q_aux;
        pto->sig = q_aux;
        
        ActualizarPosicion();
        total++;
    }
    
}

/***************** Lista::InsertarElementoAlFinal ********************/ /**
*
* Inserción de nuevos elementos al final de la Lista
* excepto que el punto de interes este en la cabeza, si esta en
* cabeza lo colocara de ultimo
*
* @param[in] archivo Archivo multimedia
*
*/ /*******************************************************************/
void Lista::InsertarElementoAlFinal(Media archivo)
{
    Puntero q_aux;
    Tiempo t;
   
    // Sumamos el tiempo
    t = archivo.GetDuracion();
    duracion_total += t;

    q_aux = new Nodo;
    q_aux->info = archivo;
    q_aux->sig = cab;
    q_aux->ant = cab->ant;
    cab->ant->sig = q_aux;
    cab->ant = q_aux;
    
    ActualizarPosicion();
    total++;
}

/********************** Lista::EliminarElemento *********************/ /**
*
* Eliminación del elemento apuntado por el punto de interés
*
*/ /*******************************************************************/
bool Lista::EliminarElemento ()
{
    bool ok;
    Puntero p_aux;
    Tiempo t;
    
    if (pto == cab)
        ok = false;
    else
    {
        ok = true;
        
        // Eliminamos el tiempo
        t = pto->info.GetDuracion();
        duracion_total -= t;
        
        p_aux = pto->sig;
        pto->sig->ant = pto->ant;
        pto->ant->sig = pto->sig;
        delete pto;
        pto = p_aux;
        
        ActualizarPosicion();
        total--;
    }
    
    return ok;
}

/************************* Lista::Consultar ************************/ /**
*
* Consulta del elemento apuntado por el punto de interés
*
* @param[out] archivo Archivo multimedia
*
*/ /*******************************************************************/
bool Lista::ConsultarElemento(Media & archivo)
{
    bool ok;
    
    if (pto == cab)
        ok = false;
    else
    {
        ok = true;
        archivo = pto->info;
    }
    return ok;
}

/***************** Lista::MoverElementoAlFinal() **********************/ /**
*
* Mueve el elemento que esta en el punto de interes a la ultima posicion y
* situa el punto en el elemento que estaba seguido del anterior punto de
* interes
*
* @retval true  Si el elemento se pudo mover al final de la Lista
* @retval false El elemento no se pudo mover al final de la Lista
*
*/ /*******************************************************************/
bool Lista::MoverElementoAlFinal()
{
    bool ok;
    Puntero interes_orig;
    Media aux_media;
    
    if (pto == cab)
        ok = false;
    else
    {
        ok = true;
        aux_media = pto -> info;
        EliminarElemento();
        interes_orig = pto;
        pto = cab;
        InsertarElementoAntes(aux_media);
        pto = interes_orig;
        
        ActualizarPosicion();
    }
    
    return ok;
}

/************************* Lista::ListaVacia *************************/ /**
*
* Comprobación de si existen elementos en la lista (además de la cabeza)
*
*/ /*******************************************************************/
bool Lista::ListaVacia()
{
    return (cab == cab->sig);
}

/*********************** Lista::IrAInicio ************************/ /**
*
* Situar el punto de interés en el primer elemento de la lista
*
*/ /****************************************************************/
void Lista::IrAInicio()
{
    pto = cab->sig;
}

/************************* Lista::Avanzar ************************/ /**
*
* Mueve el punto de interes a la posicion siguiente de donde estaba
* En el caso que el pto de interes este en el final de la Lista
* vuelve al inicio
*
*
* @retval true  El punto de interes ha sido movido satisfactoriamente
* @retval false El punto de interes no ha sido movido satisfactoriamente
*
*/ /*******************************************************************/
bool Lista::Avanzar()
{
    pto = pto -> sig;
    
    return true;
}

/************************* Lista::Retroceder ************************/ /**
*
* Mueve el punto de interes a la posicion anterior de donde estaba
* Excepto si esta en la primera posicion.
*
* @retval true  El punto de interes ha sido movido satisfactoriamente
* @retval false El punto de interes no ha sido movido satisfactoriamente
*
*/ /***********************************************************************/
bool Lista::Retroceder()
{
    bool ok;
    
    if (pto == cab -> sig)
    {
        ok = false;
    }
    else
    {
        ok = true;
        pto = pto -> ant;
    }
    
    return ok;
}

/************************* Lista::FinalLista ************************/ /**
*
* Comprueba que el punto del interes esta al final de lista
*
* @retval true  Lista Vacia
* @retval false Lista no Vacia
*
*/ /*******************************************************************/
bool Lista::FinalLista()
{
    return (pto == cab);
}

/************************* Lista::Copiar ************************/ /**
*
* Copia una lista
*
* @param[in] ori Lista original
*
*/ /***************************************************************/
void Lista::Copiar (const Lista & ori)
{
    Puntero p_aux, q_aux;
    //Se recorre la lista original
    p_aux = ori.cab->sig;
    
    duracion_total = ori.duracion_total;
    total = ori.total;
    
    while (p_aux != ori.cab)
    {
        //Se reserva espacio y actualiza la informacion
        q_aux = new Nodo;
        q_aux->info = p_aux->info;
        q_aux->num = p_aux->num;
        
        //Se van añadiendo los elementos delante de la cabeza
        //es decir, al final de la lista
        q_aux->sig = cab;
        q_aux->ant = cab->ant;
        cab->ant->sig = q_aux;
        cab->ant = q_aux;
        
        //Si estamos copiando el pto de interés lo fijamos en
        //la copia
        if (p_aux == ori.pto)
            pto = q_aux;
        p_aux = p_aux->sig;
    }
}

/************************* Lista::Vaciar ************************/ /**
*
* Vacia una lista
*
*/ /***************************************************************/
void Lista::Vaciar (void)
{
    pto = cab->sig;
    while ( EliminarElemento() );
}

/********** ostream& operator<< (ostream &, Pila) ********************/ /**
*
*  Sobrecarga del operador '<<' para llevar al stream de salida la
*  informacion de todo el contenido de la Lista
*
*  @param [in,out]  salida  stream por el que vamos a sacar la informacion.
*  @param [in]      lista   objeto Lista que queremos sacar por el stream.
*
*  @return  El stream modificado
*
*/ /**********************************************************************/
ostream& operator<< (ostream & salida, Lista lista)
{
    Lista::Puntero interes_orig;
    Media archivo;
    
    interes_orig = lista.pto;
    
    // Si el punto esta en el ultimo puesto no tienen ningun elemento seleccionado
    if (lista.FinalLista())
    {
        salida << "\nNo tiene ningun elemento seleccionado\n";
    }
    else // Si hay algun elemento seleccionado
    {
        lista.ConsultarElemento(archivo);
        salida << "[" << lista.pto->num << "/" << lista.total;
        salida << "]\t";
        MostrarVersion(salida, archivo, "rotulada");
    }
    
    salida << "======================================================\n";
    // Recorre la lista y muestra todos sus elemetos de forma reducida
    lista.IrAInicio();
    while (!lista.FinalLista())
    {
        lista.ConsultarElemento(archivo);
        salida << "[" << lista.DevuelvePosicion() << "/" << lista.total;
        salida << "]\t";
        MostrarVersion(salida, archivo, "reducida");
        salida << endl;
        lista.Avanzar();
    }
    salida << setw(45) << right << "TIEMPO TOTAL DE REPRODUCCION:  " << right << lista.duracion_total;
    salida << endl;
    
    // Vuelve a poner el pto de interes en su posicion original
    lista.pto = interes_orig;
    
    return salida;
}

/********************** Lista::ActualizarPosicion ************************/ /**
*
* Actualiza la posicion de los elementos de la lista
*
* @retval true  Si la lista fue actualizada correctamente
* @retval false Si la lista no fue actualizada correctamente
*
*/ /**********************************************************************/
bool Lista::ActualizarPosicion()
{
    Puntero aux;
    bool ok;
    int i = cab->num;
    
    if (ListaVacia() == true)
    {
        ok = false;
    }
    else
    {
        ok = true;
        aux = pto;
        
        // Recorremos la lista
        IrAInicio();
        while (!FinalLista())
        {
            i++;
            pto->num = i;
            Avanzar();
        }
        
        pto = aux;
    }
    
    return ok;
}

/********************** Lista::DevuelvePosicion ************************/ /**
*
* Devuelve la posicion de un solo elemento de la lista
*
* @return Posicion del elemento dentro de la lista
*
*/ /**********************************************************************/
int Lista::DevuelvePosicion()
{
    return pto->num;
}

/******************** Lista::DevuelveTotalDeElementos ******************/ /**
*
* Devuelve el total de elementos
*
* @return Posicion del elemento dentro de la lista
*
*/ /*******************************************************************/
int Lista::DevuelveTotalDeElementos()
{
    return total;
}
