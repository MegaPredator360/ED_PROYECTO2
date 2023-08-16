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

    // Contenedor de cedula o codigo
    string codigo;

public:
    // Constructor
    nodos(T* _datos);

    // Destructor
    virtual ~nodos();

    //Obtendrá los datos del nodo
    virtual T* obtenerDatos() const;

    // Obtendrá ya sea la cedula o el codigo
    virtual string obtenerCodigo();

    // Obtendrá la fecha de una cita realizada
    virtual string obtenerFecha();

    // Obtendrá la hora de cita realizada
    virtual string obtenerHora();

    // Obtendrá el codigo del doctor de una cita realizada
    virtual string obtenerDoctorCita();

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
    // El "dynamic_cast" se encargará de verificar en tiempo de ejecucion si es posible hacer una conversion de "dato" a la clase de datos que se necesite
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
    else if (citas* _cita = dynamic_cast<citas*>(dato))
    {
        codigo = _cita -> getCodigo();
    }
    else if (facturas* _factura = dynamic_cast<facturas*>(dato))
    {
        codigo = _factura -> getCodigo();
    }
    else if (recetasMedicas* _recetaMedica = dynamic_cast<recetasMedicas*>(dato))
    {
        codigo = _recetaMedica -> getCodigo();
    }
    else
    {
        throw exception("Ocurrio un error al obtener codigo / cedula del nodo");
    }

    return codigo;
}

template<class T>
string nodos<T>::obtenerFecha()
{
    if (citas* _cita = dynamic_cast<citas*>(dato))
    {
        return _cita -> getFecha();
    }
}

template<class T>
string nodos<T>::obtenerHora()
{
    if (citas* _cita = dynamic_cast<citas*>(dato))
    {
        return _cita -> getHora();
    }
}

template<class T>
string nodos<T>::obtenerDoctorCita()
{
    if (citas* _cita = dynamic_cast<citas*>(dato))
    {
        return _cita -> getDoctor() -> getCedula();
    }
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