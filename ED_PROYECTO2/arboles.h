#ifndef ARBOLES_H
#define	ARBOLES_H

#include "nodosArboles.h"

template <class T>
class arboles
{
protected:
    nodos<T>* raiz;
    nodosArboles<T>* _nArboles;

public:
	void registrarDatos(T* _dato);
	void buscarDatos(T* _dato);
	void eliminarDatos(T* _dato);
    void mostrarArbol();
    void recorridoProfundidad();
    void recorridoPorNiveles();
    int alturaArbol();
    int contarNodos();
    int contarHojas();
};

template<class T>
void arboles<T>::registrarDatos(T* _dato)
{
    try
    {
        _nArboles -> registrarDatos(raiz, _dato);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::buscarDatos(T* _dato)
{
    try
    {
        nodos<T>* resultado = _nArboles.buscarDatos(raiz, _dato);

        if (resultado != nullptr) 
        {
            cout << "El elemento " << _dato << " se encuentra en el Arbol." << endl;
        }
        else 
        {
            cout << "El elemento " << _dato << " no se encuentra en el Arbol." << endl;
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::eliminarDatos(T* _dato)
{
    try
    {
        raiz = _nArboles.eliminarDatos(raiz, _dato);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::mostrarArbol()
{
    try
    {
        _nArboles.mostrarArbol(raiz);
        cout << endl;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::recorridoProfundidad()
{
    try
    {
        _nArboles.recorridoProfundidad(raiz);
        cout << endl;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void arboles<T>::recorridoPorNiveles()
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

            cout << nodo -> dato << " ";

            if (nodo -> izquierda != nullptr) 
            {
                cola.push(nodo -> izquierda);
            }

            if (nodo -> derecha != nullptr) 
            {
                cola.push(nodo -> derecha);
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
        return _nArboles.alturaArbol(raiz);
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