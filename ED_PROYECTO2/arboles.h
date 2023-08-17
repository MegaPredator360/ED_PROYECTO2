#ifndef ARBOLES_H
#define	ARBOLES_H

#include "nodosArboles.h"

template <class T>
class arboles
{
protected:
    nodos<T>* raiz = nullptr;
    nodosArboles<T>* _nArboles;

public:
    // Agregarán datos al arbol, recibido el nodo y un número codigo / cedula que se usará 
    // para distribuir los nodos en el arbol
	void registrarDatos(T* _dato, string _numero);

    // Se usará para verificar el hay un nodo que contenga el codigo / cedula que estamos recibiendo
    bool verificarDatos(string _numero);

    // Se usará para verificar si el arbol está vario
    bool verificarVacio();

    // Se devuelve una cola con datos para ser almacenado en los archivos
    queue<T*> colaDatos();

    // Se devuelve el nodo donde el codigo / cedula que recibimos se encuentra
    T* obtenerDatos(string _numero);

    // Se devuelve un vector con las horas que citas que hayan sido programadas, para eso se requerira la fecha de la cita y la cedula del doctor
    void obtenerCita(vector<string>& _citasRealizadas, string _fecha, string _cedula);

    // Será usado para el eliminar nodos, en este caso, se recibe la clase pertenenciente a eliminar y su codigo / cedula identificar el nodo a eliminar
	void eliminarDatos(T* _dato, string _numero);

    // Será usado para mostrar los codigos / cedula registrados en el arbol seleccionado, usando el formato de In-Orden
    void mostrarArbol(vector<string>& _listaCodigos);

    // Será usado para mostrar los codigos / cedula registrados en el arbol seleccionado, usando el formato de Pre-Orden
    void recorridoProfundidad(vector<string>& _listaCodigos);

    // Será usado para mostrar los codigos / cedula registrados en cada nivel del arbol seleccionado
    void recorridoPorNiveles(vector<string>& _listaCodigos);

    // Mostrará la altura del arbol seleccionado
    int alturaArbol();

    // Contará cuantos nodos hay registrados en el arbol seleccionado
    int contarNodos();

    // Contará la cantidad de hojas que hay registradas en el arbol seleccionado
    int contarHojas();
};

template<class T>
void arboles<T>::registrarDatos(T* _dato, string _numero)
{
    try
    {
        // Se registra el arbol, y raiz contendrá los nuevos datos del arbol
        _nArboles -> registrarDatos(raiz, _dato, _numero);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
bool arboles<T>::verificarDatos(string _numero)
{
    try
    {
        nodos<T>* resultado = _nArboles -> buscarDatos(raiz, _numero);

        if (resultado != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
bool arboles<T>::verificarVacio()
{
    if (raiz == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<class T>
queue<T*> arboles<T>::colaDatos()
{
    try
    {
        queue<T*> cola;
        return _nArboles -> colaDatos(raiz, cola);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
T* arboles<T>::obtenerDatos(string _numero)
{
    try
    {
        T* resultado = _nArboles -> obtenerDatos(raiz, _numero);

        if (resultado != nullptr)
        {
            return resultado;
        }
        else
        {
            throw exception("Ocurrio un error al encontrar el nodo");
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::obtenerCita(vector<string>& _citasRealizadas, string _fecha, string _cedula)
{
    try
    {
        _nArboles -> obtenerCita(raiz, _citasRealizadas, _cedula, _fecha);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::eliminarDatos(T* _dato, string _numero)
{
    try
    {
        raiz = _nArboles -> eliminarDatos(raiz, _dato, _numero);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::mostrarArbol(vector<string>& _listaCodigos)
{
    try
    {
        _nArboles -> mostrarArbol(raiz, _listaCodigos);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::recorridoProfundidad(vector<string>& _listaCodigos)
{
    try
    {
        _nArboles -> recorridoProfundidad(raiz, _listaCodigos);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::recorridoPorNiveles(vector<string>& _listaCodigos)
{
    try
    {
        if (raiz == nullptr) 
        {
            return;
        }

        queue<nodos<T>*> cola;
        cola.push(raiz);

        while (!cola.empty()) 
        {
            nodos<T>* nodo = cola.front();
            cola.pop();

            _listaCodigos.push_back(nodo -> obtenerCodigo());

            if (nodo -> obtenerIzquierda() != nullptr) 
            {
                cola.push(nodo -> obtenerIzquierda());
            }

            if (nodo -> obtenerDerecha() != nullptr) 
            {
                cola.push(nodo -> obtenerDerecha());
            }
        }

        cout << endl;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int arboles<T>::alturaArbol()
{
    try
    {
        return _nArboles -> alturaArbol(raiz);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int arboles<T>::contarNodos()
{
    try
    {
        return _nArboles -> contarNodos(raiz);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int arboles<T>::contarHojas()
{
    try
    {
        return _nArboles -> contarHojas(raiz);
    }
    catch (exception& e)
    {
        throw e;
    }
}

#endif	/* ARBOLES_H */