#ifndef NODOSARBOLES_H
#define	NODOSARBOLES_H

#include "nodos.h"

template <class T>
class nodosArboles
{
public:
    void registrarDatos(nodos<T>*& _nodo, T* _dato, string _numero);
    nodos<T>* buscarDatos(nodos<T>* _nodo, T* _dato);
    nodos<T>* eliminarDatos(nodos<T>*& _nodo, T* _dato);
    void mostrarArbol(nodos<T>* _nodo);
    void recorridoProfundidad(nodos<T>* _nodo);
    nodos<T>* encontrarNodoMinimo(nodos<T>* _nodo);
    int alturaArbol(nodos<T>* _nodo);
    int contarNodos(nodos<T>* _nodo);
    int contarHojas(nodos<T>* _nodo);
};

template<class T>
void nodosArboles<T>::registrarDatos(nodos<T>*& _nodo, T* _dato, string _numero)
{
    try
    {
        if (_nodo == nullptr) 
        {
            _nodo = new nodos<T>(_dato);
        }
        else if (_numero < _nodo -> obtenerCodigo()) 
        {
            // Se crea una variable temporal que obtendr� el dato del nodo izquierda
            nodos<T>* nodoNuevo = _nodo -> obtenerIzquierda();

            // Se envia esa variable temporal ya que regresa a su vez con un dato nuevo
            registrarDatos(nodoNuevo, _dato, _numero);

            // Se guardar� ese dato nuevo en la izquierda del nodo
            _nodo -> fijarIzquierda(nodoNuevo);
        }
        else if (_numero > _nodo -> obtenerCodigo())
        {

            // Se crea una variable temporal que obtendr� el dato del nodo derecha
            nodos<T>* nodoNuevo = _nodo -> obtenerDerecha();

            // Se envia esa variable temporal ya que regresa a su vez con un dato nuevo
            registrarDatos(nodoNuevo, _dato, _numero);

            // Se guardar� ese dato nuevo en la derecha del nodo
            _nodo -> fijarDerecha(nodoNuevo);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
nodos<T>* nodosArboles<T>::buscarDatos(nodos<T>* _nodo, T* _dato)
{
    try
    {
        if (_nodo == nullptr || _nodo -> obtenerDatos() == _dato)
        {
            return _nodo;
        }
        else if (_dato < _nodo -> obtenerDatos()) 
        {
            return buscarDatos(_nodo -> obtenerIzquierda(), _dato);
        }
        else 
        {
            return buscarDatos(_nodo -> obtenerDerecha(), _dato);
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

        if (_dato < _nodo -> obtenerDatos()) 
        {
            _nodo -> fijarIzquierda() = eliminarDatos(_nodo -> obtenerIzquierda(), _dato);
        }
        else if (_dato > _nodo -> obtenerDatos())
        {
            _nodo -> fijarDerecha() = eliminarDatos(_nodo -> obtenerDerecha(), _dato);
        }
        else 
        {
            if (_nodo -> obtenerIzquierda() == nullptr)
            {
                nodos<T>* temp = _nodo -> obtenerDerecha();
                delete _nodo;
                return temp;
            }
            else if (_nodo -> obtenerDerecha() == nullptr)
            {
                nodos<T>* temp = _nodo -> obtenerIzquierda();
                delete _nodo;
                return temp;
            }

            nodos<T>* temp = encontrarNodoMinimo(_nodo -> obtenerDerecha());
            _nodo -> fijarNodo() = temp -> obtenerDatos();
            _nodo -> fijarDerecha() = eliminarDatos(_nodo -> obtenerDerecha(), temp -> obtenerDato());
        }
        return _nodo;
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

        int alturaIzq = alturaArbol(_nodo -> obtenerIzquierda());
        int alturaDer = alturaArbol(_nodo -> obtenerDerecha());

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
            cout << _nodo -> obtenerDatos() << " ";
            recorridoProfundidad(_nodo -> obtenerIzquierda());
            recorridoProfundidad(_nodo -> obtenerDerecha());
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

        while (_nodo -> obtenerIzquierda() != nullptr)
        {
            _nodo = _nodo -> obtenerIzquierda();
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

        return 1 + contarNodos(_nodo -> obtenerIzquierda()) + contarNodos(_nodo -> obtenerDerecha());
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

        if (_nodo -> obtenerIzquierda() == nullptr && _nodo -> obtenerDerecha() == nullptr)
        {
            return 1;
        }

        return contarHojas(_nodo -> obtenerIzquierda()) + contarHojas(_nodo -> obtenerDerecha());
    }
    catch (exception& e)
    {
        throw e;
    }
}


#endif	/* LISTA_H */