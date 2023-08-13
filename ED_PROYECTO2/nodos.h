#ifndef NODOS_H
#define	NODOS_H

#include "std.h"

template <class T>
class nodos
{
protected:
    // Los tipos de dato que contedr�n los nodos
    T* dato;
    nodos<T>* izquierda;
    nodos<T>* derecha;

    // Contenedor de cedula o codigo
    string codigo;

public:
    // Constructor
    nodos(T* _datos);

    // Destructor
    virtual ~nodos();

    //Obtendr� los datos del nodo
    virtual T* obtenerDatos() const;

    // Obtendr� ya sea la cedula o el codigo
    virtual string obtenerCodigo();

    // Obtendr� los datos del nodo de la izquierda
    virtual nodos<T>* obtenerIzquierda() const;

    // Obtendr� los datos del nodo de la derecha
    virtual nodos<T>* obtenerDerecha() const;

    // Guardar� el dato del nodo
    virtual void fijarNodo(T* _datos);

    // Guardar� el dato del nodo de la izquierda
    virtual void fijarIzquierda(nodos<T>* _izquierda);

    // Guardar� el dato del nodo de la derecha
    virtual void fijarDerecha(nodos<T>* _derecha);
};

template<class T>
nodos<T>::nodos(T* _datos) : dato(_datos), izquierda(nullptr), derecha(nullptr) { }

template <class T>
nodos<T>::~nodos() { }

template <class T>
T* nodos<T>::obtenerDatos() const 
{
    return dato;
}

template<class T>
string nodos<T>::obtenerCodigo()
{
    // Verificamos si dato es de la clase doctores
    if (doctores* _doctor = dynamic_cast<doctores*>(dato))
    {
        codigo = _doctor -> getCedula();
    }
    else if (pacientes* _paciente = dynamic_cast<pacientes*>(dato))
    {
        codigo = _paciente -> getCedula();
    }
    else if (medicamentos* _medicamento = dynamic_cast<medicamentos*>(dato))
    {
        codigo = _medicamento -> getCodigo();
    }

    return codigo;
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