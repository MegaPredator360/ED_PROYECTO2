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
	void registrarDatos(T* _dato, string _numero);
    bool verificarDatos(string _numero);
    bool verificarVacio();
    queue<T*> colaDatos();
    T* obtenerDatos(string _numero);
    void obtenerCita(vector<string>& _citasRealizadas, string _fecha, string _cedula);
	void buscarDatos(string _numero);
	void eliminarDatos(T* _dato, string _numero);
    void mostrarArbol(vector<string>& _listaCodigos);
    void recorridoProfundidad(vector<string>& _listaCodigos);
    void recorridoPorNiveles(vector<string>& _listaCodigos);
    int alturaArbol();
    int contarNodos();
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
void arboles<T>::buscarDatos(string _numero)
{
    try
    {
        nodos<T>* resultado = _nArboles.buscarDatos(raiz, _numero);

        if (resultado != nullptr) 
        {
            cout << "El elemento " << _numero << " se encuentra en el Arbol." << endl;
        }
        else 
        {
            cout << "El elemento " << _numero << " no se encuentra en el Arbol." << endl;
        }
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
        return _nArboles.contarNodos(raiz);
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
        return _nArboles.contarHojas(raiz);
    }
    catch (exception& e)
    {
        throw e;
    }
}

#endif	/* ARBOLES_H */