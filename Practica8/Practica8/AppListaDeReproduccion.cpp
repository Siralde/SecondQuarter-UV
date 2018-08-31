/**
 * @file AppListaDeReproduccion.cpp
 *
 * @brief Practica 8, Lista de Reproduccion
 *
 * Aplicacion para gestionar una lista de reproduccion
 *
 * @version 1
 * @author Aldemaro Gonzalez
 * @date 05/05/2018
 */
#include <fstream>
#include <cctype>
#include <string>
#include "Lista.h"

const int MAX_LISTA = 100;
const string NOMBRELISTAS = "NombreDeLasListas.dat";

typedef string Nombres[MAX_LISTA];

// Menus
void MenuFunciones(Lista &, string, bool &);
void MenuEliminar();
void MenuRecuperar(Lista&, bool &);

// Prototipos de Funcionalidades de las Lista
void AnadirElementoAntes(Lista &);
void AnadirElementoDespues(Lista &);
void AnadirAlFinal(Lista &);
void EliminarElemento(Lista &);
void MoverAlFinal(Lista &);
void Avanzar(Lista &);
void Retroceder(Lista &);
//Gestion de almacenamiento de una lista
void GuardarLista(Lista &);
// Guardar Nombre de Listas
bool GuardarNombreLista(string);

bool GuardarLista(string, Lista &);
//Funciones para leer los nombres de las listas
bool LeerNombresListas(Nombres &, int &);
bool LeerFicheroNL(ifstream &, string &);
string MostrarNombres(const Nombres &, int);
//Funciones para leer los elementos de una lista
bool LeerElementosLista(Lista&, string);
bool LeerFicheroL(ifstream &, Media &);

int main(void)
{
    Lista lista_principal;
    int op;
    bool finalizar = false;
    
    while (!finalizar)
    {
        cout << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Nueva Lista" << endl;
        cout << "2. Recuperar Lista" << endl;
        cout << "3. Finalizar" << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
        
        switch (op)
        {
            case 1:
                MenuFunciones(lista_principal, "Nueva Lista", finalizar);
                break;
            case 2:
                MenuRecuperar(lista_principal, finalizar);
                break;
            case 3:
                finalizar = true;
                break;
            default:
                cout << "\nOpcion no valida, vuelve a intentarlo." << endl;
                break;
        }
        
        lista_principal.Vaciar();
    }
    
    return 0;
}


/************************* MenuFunciones ************************/ /**
*
* Operaciones que se le pueden aplicar a la Lista
*
* @param[in, out]   lr         Lista de Reproduccion
* @param[in]        nom_menu   Nombre del menu
* @param[in, out]   finalizar  Finalizar programa
*
*/ /*******************************************************************/
void MenuFunciones(Lista & lr, string nom_menu, bool & finalizar)
{
    int op;
    bool terminar = false;
    
    while (!finalizar && !terminar)
    {
        cout << "Opciones de " << nom_menu << endl;
        cout << " 1. Anadir Elemento antes del punto de Interes" << endl;
        cout << " 2. Anadir Elemento despues del punto de Interes" << endl;
        cout << " 3. Anadir Elemento al final del punto de Interes" << endl;
        cout << " 4. Eliminar Elemento de la Lista" << endl;
        cout << " 5. Mover archivo al final de la Lista" << endl;
        cout << " 6. Avanzar Punto de Interes" << endl;
        cout << " 7. Retroceder Punto de Interes" << endl;
        cout << " 8. Guardar Lista" << endl;
        cout << " 9. Finalizar" << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
        
        switch (op)
        {
            case 1:
                AnadirElementoAntes(lr);
                break;
            case 2:
                AnadirElementoDespues(lr);
                break;
            case 3:
                AnadirAlFinal(lr);
                break;
            case 4:
                EliminarElemento(lr);
                break;
            case 5:
                MoverAlFinal(lr);
                break;
            case 6:
                Avanzar(lr);
                break;
            case 7:
                Retroceder(lr);
                break;
            case 8:
                GuardarLista(lr);
                terminar = true;
                finalizar = false;
                break;
            case 9:
                terminar = true;
                finalizar = true;
                break;
            default:
                cout << "\nOpcion no valida, vuelve a intentarlo." << endl;
                break;
        }
    }
}

/********************** AnadirElementoAntes **********************/ /**
*
* Anadir el elemento antes de punto de interes
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*******************************************************************/
void AnadirElementoAntes(Lista & lr)
{
    Media m1;
    
    cout << endl;
    
    cin.ignore();
    cin >> m1;
    
    lr.InsertarElementoAntes(m1);
    
    cout << lr;
    cout << endl;
}

/********************** AnadirElementoDespues **********************/ /**
*
* Anadir el elemento despues de punto de interes
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*******************************************************************/
void AnadirElementoDespues(Lista & lr)
{
    Media m1;
    
    cout << endl;
    
    cin.ignore();
    cin >> m1;
    
    lr.InsertarElementoDespues(m1);
    
    cout << lr;
    cout << endl;
}

/********************** AnadirAlFinal **********************/ /**
*
* Anadir el elemento al final de la lista
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*************************************************************/
void AnadirAlFinal(Lista & lr)
{
    Media m1;
    
    cout << endl;
    
    cin.ignore();
    cin >> m1;
    
    lr.InsertarElementoAlFinal(m1);
    
    cout << lr;
    cout << endl;
}

/*************** EliminarElemento ***************/ /**
*
* Eliminar un elemento de la Lista
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*************************************************/
void EliminarElemento(Lista & lr)
{
    cout << endl;
    
    lr.EliminarElemento();
    
    cout << lr;
    cout << endl;
}

/*************** MoverAlFinal ***************/ /**
*
* Mover el elemento del punto de interes al final
* de la Lista
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*************************************************/
void MoverAlFinal(Lista & lr)
{
    cout << endl;
    
    lr.MoverElementoAlFinal();
    
    cout << lr;
    cout << endl;
}

/******************* Avanzar *********************/ /**
*
* Avanzar el punto de interes a la siguiente
* posicion
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*********************************************/
void Avanzar(Lista & lr)
{
    cout << endl;
    
    lr.Avanzar();
    
    cout << lr;
    cout << endl;
}

/******************* Retroceder *********************/ /**
*
* Retroceder el punto de interes a la anterior posicion
*
* @param[in, out] lr Lista de Reproduccion
*
*/ /*****************************************************/
void Retroceder(Lista & lr)
{
    cout << endl;
    
    if (lr.Retroceder() == false)
    {
        cout << "\n\nNo se puede retroceder estando en el primer elemento de la lista\n\n";
    }
    else
    {
        cout << lr;
        cout << endl;
    }
    
}

/*********************** GuardarLista **********************/ /**
*
* Gestiona el guardado de las Listas reproduccion en ficheros
*
* @param[in] lr Lista de Reproduccion
*
*/ /*********************************************************/
void GuardarLista(Lista & lr)
{
    Nombres nombre_lista;
    string nombre_lista_us;
    int cantidad_nombres, i;
    
    if (LeerNombresListas(nombre_lista, cantidad_nombres))
    {
        cout << "No puedes utilizar ninguno de los siguientes nombres: " << endl;
        
        for (i = 0 ; i < cantidad_nombres; i++)
        {
            cout << "\t" << i + 1 << ". " << nombre_lista[i] << endl;
        }
    }

    cout << "\nIntroduce el nombre de la Lista(Palabras sin espacios): ";
    cin >> nombre_lista_us;
    cout << endl;
    
    GuardarNombreLista(nombre_lista_us);
    GuardarLista(nombre_lista_us, lr);
    
}

/*************************** GuardarNombreLista *************************/ /**
*
* Guarda el nombre de las listas en un fichero llamado
* NombreDeLaLista.dat
*
* @param[in] nombre_lista Nombre que el usuario le dio a las lista
*
*/ /****************************************************************/
bool GuardarNombreLista(string nombre_lista)
{
    ofstream f;
    bool abrio;
    
    f.open(NOMBRELISTAS, ios::app);
    if(!f)
    {
        cout << "Error abriendo el fichero para guardar nombre de la lista(Funcion: GuardarNombreLista" << endl;
        abrio = false;
    }
    else
    {
        f << nombre_lista << endl;
        abrio = true;
        f.close();
    }
    
    return abrio;
}

/*********************************** GuardarLista ******************************/ /**
*
* Guarda la lista de reproduccion en un fichero
*
* @param[in]        nombre_lista    Nombre que el usuario le dio a las lista
* @param[in, out]   lr              Lista de Reproducion
*
*/ /**********************************************************************************/
bool GuardarLista(string nombre_lista, Lista & lr)
{
    ofstream f;
    bool abrio;
    string nombre;
    Media archivo;
    
    nombre = nombre_lista + ".dat";
    
    f.open(nombre);
    if(!f)
    {
        cout << "Error abriendo el fichero para guardar la lista (Funcion: GuardarLista)" << endl;
        abrio = false;
    }
    else
    {
        f << lr.DevuelveTotalDeElementos() << endl;
        // Ir a Inicio de la Lista
        lr.IrAInicio();
        // Escribir en el fichero hasta el final de la lista
        while (!lr.FinalLista())
        {
            lr.ConsultarElemento(archivo);
            f << archivo;
            lr.Avanzar();
        }
        abrio = true;
        f.close();
    }
    
    return abrio;
}

/*********************************** MenuRecuperar ******************************/ /**
*
* Menu de gestion para la recuperacion de una Lista de Reproduccion
*
* @param[in] lr        Lista de Reproduccion a recuperar
* @param[in] finalizar Si se finaliza o no la aplicacion
*
*/ /**********************************************************************************/
void MenuRecuperar(Lista & lr, bool & finalizar)
{
    Nombres nombre_lista;
    int cantidad_nombres = 0;
    string lista_elegida;
    
    if (LeerNombresListas(nombre_lista, cantidad_nombres))
    {
        lista_elegida = MostrarNombres(nombre_lista, cantidad_nombres);
        
        LeerElementosLista(lr, lista_elegida);
        cout << endl;
        MenuFunciones(lr, lista_elegida, finalizar);
    }
    else
    {
        cout << "\nNo hay listas guardadas. Volviendo al Menu Principal...\n\n";
    }
    
}

/*********************************** LeerElementosLista ******************************/ /**
*
* Gestiona la lectura de los elementos de la lista
*
* @param[in] l      Lista de Reproduccion a recuperar
* @param[in] titulo Nombre del fichero
*
* @retval true  Si se leyo correctamente el fichero
* @retval false No se leyo correctamente el fichero
*
*/ /**********************************************************************************/
bool LeerElementosLista(Lista & l, string titulo)
{
    ifstream f;
    bool ok;
    string nombre;
    Media archivo;
    int cant_elem;
    string ignorar;
    
    nombre = titulo + ".dat";
    
    f.open(nombre);
    if(!f)
    {
        cout << "Error abriendo el fichero " << titulo << ".dat (Funcion: LeerElementosListas)" << endl;
        ok = false;
    }
    else
    {
        f >> cant_elem;
        getline(f, ignorar);
        while (LeerFicheroL(f, archivo))
        {
            l.InsertarElementoAntes(archivo);
            getline(f, ignorar);
        }
        f.close();
        ok = true;
    }
    
    return ok;
}
/*********************************** LeerFicheroL ******************************/ /**
**
*
* Gestiona la lectura de los elementos de la lista
*
* @param[in]  f        Descriptor del fichero
* @param[out] archivo  Archivo a rellenar
*
* @retval true  Si se leyo correctamente un archivo
* @retval false No se leyo correctamente un archivo
*
*/ /**********************************************************************************/
bool LeerFicheroL(ifstream & f, Media & archivo)
{
    bool lectura_ok = false;
    string titulo, info, ruta;
    int hora = 0, min = 0;
    float seg = 0;
    Tiempo t;
    
    if (getline (f, titulo))
    {
        getline (f, info);
        getline(f, ruta);
        f >> hora;
        f.ignore();
        f >> min;
        f.ignore();
        f >> seg;
        lectura_ok = true;

    }
    
    if (lectura_ok == true)
    {
        archivo.SetInfo(info);
        archivo.SetRuta(ruta);
        archivo.SetTitulo(titulo);
        t.SetTiempo(hora, min, seg);
        archivo.SetDuracion(t);
    }
    
    return lectura_ok;
}


/*********************************** MostrarNombres ******************************/ /**
*
* Muestra los nombres de las lista que estan disponibles para su recuperacion y
* devuelve un nombre elegido por el usuario
*
* @param[out] nombre_lista    Vector donde se guardaran los nombres de las listas
* @param[in]  cant            Cantidad de Nombres que hay en el vector
*
* @return Nombre de la lista a recuperar
*
*/ /**********************************************************************************/
string MostrarNombres(const Nombres & nombre_lista, int cant)
{
    int i, op;
    
    do
    {
        for (i = 0 ; i < cant; i++)
        {
            cout << "\t" << i + 1 << ". " << nombre_lista[i] << endl;
        }
        cout << "Numero de Lista Elegida: ";
        cin >> op;
    }
    while (op < 1 || op > cant);
    
    return nombre_lista[op - 1];
}

/*********************************** LeerNombresListas ******************************/ /**
*
* Lee todos los nombres del fichero de las List
*
* @param[out] nombre    Vector donde se guardaran los nombres de las listas
* @param[out] i         Cantidad de nombres en el fichero
*
*/ /**********************************************************************************/
bool LeerNombresListas(Nombres & nombre, int & i)
{
    ifstream f;
    bool ok;
    
    f.open(NOMBRELISTAS);
    if(!f)
    {
        ok = false;
    }
    else
    {
        while (LeerFicheroNL(f, nombre[i]))
        {
            i++;
        }
        f.close();
        ok = true;
    }
    
    return ok;
}

/*********************************** LeerFicheroNL ******************************/ /**
*
* Lee todos los nombres del fichero de las Lista
*
* @param[in]  f          Descriptor del fichero
* @param[out] nombre     Nombre del fichero
*
* @retval true  Si se pudo leer un nombre
* @retval false Si no se pudo leer un nombre
*
*/ /**********************************************************************************/
bool LeerFicheroNL(ifstream & f, string & nombre)
{
    bool lectura_ok = false;
    char ultimo_caracter;
    size_t cant_caracteres;
    string arreglo;
    
    if (getline(f, nombre))
    {
        cant_caracteres = nombre.length();
        ultimo_caracter = nombre[cant_caracteres];
        if ( ultimo_caracter == '\r' || ultimo_caracter == '\0')
        {
            arreglo = nombre.substr(0, cant_caracteres);
            nombre = arreglo;
        }

        lectura_ok = true;
    }

    return lectura_ok;
}
