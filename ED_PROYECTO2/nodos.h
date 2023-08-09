#ifndef NODOS_H
#define	NODOS_H

#include "std.h"

template <class T>
class nodos 
{
protected:
    // Los tipos de dato que contedrán los nodos
    T* dato;
    nodos<T>* izquierda;
    nodos<T>* derecha;

public:
    // Constructor
    nodos(T* _datos, nodos<T>* _izquierda, nodos<T>* _derecha);

    // Destructor
    virtual ~nodos();

    //Obtendrá los datos del nodo
    virtual T* obtenerDatos() const;

    // Obtendrá los datos del nodo de la izquierda
    virtual nodos<T>* obtenerIzquierda() const;

    // Obtendrá los datos del nodo de la derecha
    virtual nodos<T>* obtenerDerecha() const;

    // Guardará el dato del nodo
    virtual void fijarNodo(T* _datos);

    // Guardará el dato del nodo de la izquierda
    virtual void fijarIzquierda(nodos<T>* _izquierda);

    // Guardará el dato del nodo de la derecha
    virtual void fijarDerecha(nodos<T>* _derecha);
};

template <class T>
nodos<T>::nodos(T* _datos, nodos<T>* _izquierda, nodos<T>* _derecha)
{
    dato = _datos;
    this -> izquierda = _izquierda;
    this -> derecha = _derecha;
}

template <class T>
nodos<T>::~nodos() { }

template <class T>
T* nodos<T>::obtenerDatos() const 
{
    return dato;
}

template <class T>
nodos<T>* nodos<T>::obtenerIzquierda() const 
{
    return izquierda;
}

template <class T>
nodos<T>* nodos<T>::obtenerDerecha() const 
{
    return derecha;
}

template<class T>
void nodos<T>::fijarNodo(T* _datos)
{
    dato = _datos;
}

template <class T>
void nodos<T>::fijarIzquierda(nodos<T>* _izquierda) 
{
    this -> izquierda = _izquierda;
}

template <class T>
void nodos<T>::fijarDerecha(nodos<T>* _derecha)
{
    this -> derecha = _derecha;
}

#endif	/* NODOS_H */