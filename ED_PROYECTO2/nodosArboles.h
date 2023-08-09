#ifndef NODOSARBOLES_H
#define	NODOSARBOLES_H

#include "nodos.h"

template <class T>
class nodosArboles
{
public:
    void registrarDatos(nodos<T>*& _nodo, T* _dato);
    nodos<T>* buscarDatos(nodos<T>* _nodo, T* _dato);
    nodos<T>* eliminarDatos(nodos<T>*& _nodo, T* _dato);
    void mostrarArbol(nodos<T>* _nodo);
    void recorridoProfundidad(nodos<T>* _nodo);
    nodos<T>* encontrarNodoMinimo(nodos<T>* _nodo);
    int alturaArbol(nodos<T>* _nodo);
    int contarNodos(nodos<T>* _nodo);
    int contarHojas(nodos<T>* _nodo);
};

#endif	/* LISTA_H */

template<class T>
void nodosArboles<T>::registrarDatos(nodos<T>*& _nodo, T* _dato)
{
    try
    {
        if (_nodo == nullptr) 
        {
            _nodo = new nodos(_dato);
        }
        else if (_dato < _nodo -> dato) 
        {
            registrarDatos(_nodo -> izquierda, _dato);
        }
        else if (_dato > _nodo -> derecha) 
        {
            registrarDatos(_nodo -> derecha, _dato);
        }
    }
    catch (excepcion& e)
    {
        throw e;
    }
}

template<class T>
nodos<T>* nodosArboles<T>::buscarDatos(nodos<T>* _nodo, T* _dato)
{
    try
    {
        if (_nodo == nullptr || _nodo -> dato == _dato) 
        {
            return _nodo;
        }
        else if (_dato < _nodo -> dato) 
        {
            return buscarDatos(_nodo -> izquierda, _dato);
        }
        else 
        {
            return buscarDatos(_nodo -> derecha, _dato);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
inline nodos<T>* nodosArboles<T>::eliminarDatos(nodos<T>*& _nodo, T* _dato)
{
    try
    {
        if (_nodo == nullptr) 
        {
            return _nodo;
        }

        if (_dato < _nodo -> dato) 
        {
            _nodo -> izquierda = eliminarDatos(_nodo -> izquierda, _dato);
        }
        else if (_dato > _nodo -> dato) 
        {
            _nodo -> derecha = eliminarDatos(_nodo -> derecha, _dato);
        }
        else 
        {
            if (_nodo -> izquierda == nullptr) 
            {
                nodos<T>* temp = _nodo -> derecha;
                delete _nodo;
                return temp;
            }
            else if (_nodo -> derecha == nullptr) 
            {
                nodos<T>* temp = _nodo -> izquierda;
                delete _nodo;
                return temp;
            }

            nodos<T>* temp = encontrarNodoMinimo(_nodo -> derecha);
            _nodo -> dato = temp -> dato;
            _nodo -> derecha = eliminarDatos(_nodo -> derecha, temp -> dato);
        }
        return nodo;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void nodosArboles<T>::mostrarArbol(nodos<T>* _nodo)
{
    try
    {
        if (_nodo == nullptr) 
        {
            return 0;
        }

        int alturaIzq = alturaArbol(_nodo -> izquierda);
        int alturaDer = alturaArbol(_nodo -> derecha);

        return 1 + max(alturaIzq, alturaDer);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void nodosArboles<T>::recorridoProfundidad(nodos<T>* _nodo)
{
    try
    {
        if (_nodo != nullptr) 
        {
            cout << _nodo -> dato << " ";
            recorridoProfundidad(_nodo -> izquierda);
            recorridoProfundidad(_nodo -> derecha);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
nodos<T>* nodosArboles<T>::encontrarNodoMinimo(nodos<T>* _nodo)
{
    try
    {
        if (_nodo == nullptr)
        {
            return nullptr;
        }

        while (_nodo -> izquierda != nullptr)
        {
            _nodo = _nodo -> izquierda;
        }

        return _nodo;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int nodosArboles<T>::alturaArbol(nodos<T>* _nodo)
{
    try
    {
        if (_nodo == nullptr) 
        {
            return 0;
        }

        int alturaIzq = alturaArbol(_nodo -> izquierda);
        int alturaDer = alturaArbol(_nodo -> derecha);

        return 1 + max(alturaIzq, alturaDer);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int nodosArboles<T>::contarNodos(nodos<T>* _nodo)
{
    try
    {
        if (_nodo == nullptr)
        {
            return 0;
        }

        return 1 + contarNodos(_nodo -> izquierda) + contarNodos(_nodo -> derecha);
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
int nodosArboles<T>::contarHojas(nodos<T>* _nodo)
{
    try
    {
        if (_nodo == nullptr) 
        {
            return 0;
        }

        if (_nodo -> izquierda == nullptr && _nodo -> derecha == nullptr)
        {
            return 1;
        }

        return contarHojas(_nodo -> izquierda) + contarHojas(_nodo -> derecha);
    }
    catch (exception& e)
    {
        throw e;
    }
}
