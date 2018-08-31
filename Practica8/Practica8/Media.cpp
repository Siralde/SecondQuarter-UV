/****** Media.cpp ************************************************/ /**
 *
 * @file Media.cpp
 *
 * @brief Implementacion de los metodos de la clase Media
 *
 * @version 1.0
 * @author Vicente Cerverón
 * @date 27-04-2018
 */ /**************************************************************************/

#include <iomanip>
#include "Media.h"

/**** Media::Media () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Media.
 *
 */ /********************************************************************************/
Media::Media()
{
    Tiempo t;
    titulo = "sin titulo";
    info = "sin informacion";
    // los objetos de la clase Tiempo, como duracion, por defecto se establece a 0
    ruta = "sin ruta";
    duracion = t;
}

/**** Media::Media (string, string, string, Tiempo) *******************************/ /**
*
* Constructor por defecto de la clase Media.
*
* @param[in] m_titulo   Titulo del archivo
* @param[in] m_info     Informacion del archivo
* @param[in] m_ruta     Ruta del archivo
* @param[in] m_duracion Duracion del archivo
*
*/ /********************************************************************************/
Media::Media(string m_titulo, string m_info, string m_ruta, Tiempo m_duracion)
{
    SetTitulo(m_titulo);
    SetInfo(m_info);
    SetRuta(m_ruta);
    duracion = m_duracion;
}

/******************************* Media::SetTitulo *******************************/ /**
*
* Establece el titulo del archivo, si no se pasa un nombre establece el nombre
* "DESCONOCIDO"
*
* @param[in] m_titulo   Titulo del archivo
*
* @retval true  Si el nombre se ha establecido correctamente
* @retval false Si el parametro pasado es un string vacio
*
*/ /********************************************************************************/
bool Media::SetTitulo(string m_titulo)
{
    bool ok;
    
    if (m_titulo.empty())
    {
        titulo = "DESCONOCIDO";
        ok = false;
    }
    else
    {
        titulo = m_titulo;
        ok = true;
    }
    
    return ok;
}

/******************************* Media::SetInfo *******************************/ /**
*
* Establece la informacion del archivo, si no se pasa informacion, su contenido se
* establece como "SIN INFORMACION"
*
* @param[in] m_info Informacion del archivo
*
* @retval true  Si la informacion se ha establecido correctamente
* @retval false Si el parametro pasado es un string vacio
*
*/ /********************************************************************************/
bool Media::SetInfo(string m_info)
{
    bool ok;
    
    if (m_info.empty())
    {
        info = "SIN INFORMACION";
        ok = false;
    }
    else
    {
        info = m_info;
        ok = true;
    }
    
    return ok;
}

/******************************* Media::SetRuta *******************************/ /**
*
* Establece la ruta/direccion del archivo, si no se pasa informacion, su contenido se
* establece como "SIN RUTA"
*
* @param[in] m_ruta Ruta del archivo
*
* @retval true  Si la ruta se ha establecido correctamente
* @retval false Si el parametro pasado es un string vacio
*
*/ /********************************************************************************/
bool Media::SetRuta(string m_ruta)
{
    bool ok;
    
    if (m_ruta.empty())
    {
        ruta = "SIN INFORMACION";
        ok = false;
    }
    else
    {
        ruta = m_ruta;
        ok = true;
    }
    
    return ok;
}

/******************************* Media::SetDuracion *******************************/ /**
*
* Establece la duracion del archivo.
*
* @param[in] m_duracion Duracion del archivo
*
* @retval true  Si la duracion se ha establecido correctamente
* @retval false Si el parametro pasado no cumple los requerimientos establecido por
*               por el metodo SetTiempo del fichero Tiempo.cpp
*
*/ /********************************************************************************/
bool Media::SetDuracion(Tiempo m_duracion)
{
    return duracion.SetTiempo(m_duracion.GetHoras(), m_duracion.GetMinutos(), m_duracion.GetSegundos());
}

/**** Tiempo Media::GetDuracion () ***************************************************/ /**
 *
 * Devuelve la duración de un objeto Media
 *
 * @return  Tiempo duración
 *
 */ /********************************************************************************/
Tiempo Media::GetDuracion()
{
    return duracion;    
}
              
/**** string Media::GetTitulo () ***************************************************/ /**
 *
 * Devuelve el título de un objeto Media
 *
 * @return  título
 *
 */ /********************************************************************************/
string Media::GetTitulo()
{
    return titulo;    
}

/**** Media::GetInfo() ***************************************************/ /**
*
* Devuelve la informacion de un archivo
*
* @return Informacion del archivo
*
*/ /***********************************************************************/
string Media::GetInfo()
{
    return info;
}

/**** Media::GetRuta() ***************************************************/ /**
*
* Devuelve la ruta del archivo
*
* @return Ruta del archivo
*
*/ /****************************************************************************/
string Media::GetRuta()
{
    return ruta;
}


/*** istream & operator>> (istream & in, Media & m) ************************/ /**
 *
 *  Sobrecarga del operador '>>' para asignar la información de un Media 
 *  desde un stream (fichero, teclado, ...).
 *
 *  @param [in, out]  in  stream del que vamos a obtener la informacion.
 *  @param [out]     m        objeto Media que queremos rellenar con la
 *                            informacion obtenida del stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
istream& operator>> (istream & in, Media & m)
{
    string findelinea;
    
    cout << "Introduce el titulo: ";
    getline(in, m.titulo);
    cout << "Introduce la informacion del archivo: ";
    getline(in, m.info);
    cout << "Introduce la ruta del archivo: ";
    getline(in, m.ruta);
    cout << "Introduce la Duracion: ";
    in >> m.duracion;
    getline(in, findelinea);
    
    return in;
}

/*** ostream & operator<< (ostream & out, Media& m) ******************/ /**
 *
 *  Sobrecarga del operador '<<' para sacar la información de un Media 
 *  por un stream (fichero, consola, ...).
 *
 *  @param [in, out]  out    stream por el que vamos a sacar la informacion.
 *  @param [in]      m      objeto Media que queremos sacar por el stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
ostream& operator<< (ostream& out, Media m)
{
    out << m.titulo << endl;
    out << m.info << endl;
    out << m.ruta << endl;
    out << m.duracion << endl;

    return out;
}

/**** void MostrarVersion(ostream& out, Media m, string version) *********************/ /** *
 *
 * Muestra un objeto Media 
 *
 * param[in]    out stream donde sale la informacion
 * param[in]    m   Media que se detalla
 * param[in]    version modo en que se quiere mostrar
 *
 */ /********************************************************************************/
void MostrarVersion(ostream& out, Media m, string version)
{
    if(version == "rotulada")
    {
        out << setw(36) << left << m.titulo << " " << right << m.duracion;
        out << endl;
        out << setw(40) << left << m.info;
        out << endl;
        out << setw(40) << left << m.ruta;
        out << endl;
//        out << "Titulo: " << m.titulo << endl;
//        out << "Duracion: " << m.duracion << endl;
//        out << "Informacion: " << m.info << endl;
//        out << "Ruta en el sistema: (" << m.ruta << ")" << endl;
    }
    else if(version == "reducida")
    {
        out << setw(36) << left << m.titulo << " " << right << m.duracion;
    }
    
    return;    
}

