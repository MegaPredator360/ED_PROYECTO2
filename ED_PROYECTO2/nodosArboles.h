#ifndef NODOSARBOLES_H
#define	NODOSARBOLES_H

#include "nodos.h"

template <class T>
class nodosArboles
{
public:
    // Se registrarán los datos en el nodo, según el número de codigo / cedula
    void registrarDatos(nodos<T>*& _nodo, T* _dato, string _numero);

    // Retornará un nodo en base a su numero de cedula / codigo
    nodos<T>* buscarDatos(nodos<T>* _nodo, string _numero);

    // Se eliminará el nodo del arbol
    nodos<T>* eliminarDatos(nodos<T>* _nodo, T* _dato, string _numero);

    // Obtendrá una cola con los datos del arbol que serán usado para guardar los datos en los archivos
    queue<T*> colaDatos(nodos<T>* _nodo, queue<T*>& _cola);

    // Obtendrá el Nodo solicitado basado en el tipo de clase y su numero de cedula / codigo
    T* obtenerDatos(nodos<T>* _nodo, string _numero);

    // Retornará un vector con las horas de las registradas que coincidan con la cedula del doctor y la fecha que el usuario escogio
    void obtenerCita(nodos<T>* _nodo, vector<string>& _citaRealizada, string _cedula, string _fecha);

    // Retornará un vector con la cedula / codigo del arbol registrado en formato de In-Orden
    void mostrarArbol(nodos<T>* _nodo, vector<string>& _listaCodigos);

    // Retornará un vector con la cedula / codigo del arbol registrado en formato de Pre-Orden
    void recorridoProfundidad(nodos<T>* _nodo, vector<string>& _listaCodigos);

    // Se encontrará el nodo con la cedula / codigo más bajo
    nodos<T>* encontrarNodoMinimo(nodos<T>* _nodo);

    // Retornará la altura del arbol seleccionado
    int alturaArbol(nodos<T>* _nodo);

    // Retornará la cantidad de nodos registrados en el arbol seleccionado
    int contarNodos(nodos<T>* _nodo);

    // Retornará la cantidad de hojas registradas en el arbol seleccionado
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
            // Se crea una variable temporal que obtendrá el dato del nodo izquierda
            nodos<T>* nodoNuevo = _nodo -> obtenerIzquierda();

            // Se envia esa variable temporal ya que regresa a su vez con un dato nuevo
            registrarDatos(nodoNuevo, _dato, _numero);

            // Se guardará ese dato nuevo en la izquierda del nodo
            _nodo -> fijarIzquierda(nodoNuevo);
        }
        else if (_numero > _nodo -> obtenerCodigo())
        {

            // Se crea una variable temporal que obtendrá el dato del nodo derecha
            nodos<T>* nodoNuevo = _nodo -> obtenerDerecha();

            // Se envia esa variable temporal ya que regresa a su vez con un dato nuevo
            registrarDatos(nodoNuevo, _dato, _numero);

            // Se guardará ese dato nuevo en la derecha del nodo
            _nodo -> fijarDerecha(nodoNuevo);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
nodos<T>* nodosArboles<T>::buscarDatos(nodos<T>* _nodo, string _numero)
{
    try
    {
        if (_nodo == nullptr || _nodo -> obtenerCodigo() == _numero)
        {
            return _nodo;
        }
        else if (_numero < _nodo -> obtenerCodigo())
        {
            return buscarDatos(_nodo -> obtenerIzquierda(), _numero);
        }
        else
        {
            return buscarDatos(_nodo -> obtenerDerecha(), _numero);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
nodos<T>* nodosArboles<T>::eliminarDatos(nodos<T>* _nodo, T* _dato, string _numero)
{
    try
    {
        if (_nodo == nullptr) 
        {
            return _nodo;
        }

        if (_numero < _nodo -> obtenerCodigo()) 
        {
            _nodo -> fijarIzquierda(eliminarDatos(_nodo -> obtenerIzquierda(), _dato, _numero));
        }
        else if (_numero > _nodo -> obtenerCodigo())
        {
            _nodo -> fijarDerecha(eliminarDatos(_nodo -> obtenerDerecha(), _dato, _numero));
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

            _nodo -> fijarNodo(temp -> obtenerDatos());

            _nodo -> fijarDerecha(eliminarDatos(_nodo -> obtenerDerecha(), temp -> obtenerDatos(), _numero));
        }
        return _nodo;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
queue<T*> nodosArboles<T>::colaDatos(nodos<T>* _nodo, queue<T*>& _cola)
{
    try
    {
        if (_nodo != nullptr)
        {
            _cola.push(_nodo -> obtenerDatos());

            colaDatos(_nodo -> obtenerIzquierda(), _cola);

            colaDatos(_nodo -> obtenerDerecha(), _cola);
        }

        return _cola;
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
T* nodosArboles<T>::obtenerDatos(nodos<T>* _nodo, string _numero)
{
    try
    {
        if (_nodo -> obtenerCodigo() == _numero)
        {
            return _nodo -> obtenerDatos();
        }
        else if (_numero < _nodo -> obtenerCodigo())
        {
            return obtenerDatos(_nodo -> obtenerIzquierda(), _numero);
        }
        else
        {
            return obtenerDatos(_nodo -> obtenerDerecha(), _numero);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void nodosArboles<T>::obtenerCita(nodos<T>* _nodo, vector<string>& _citaRealizada, string _cedula, string _fecha)
{
    try
    {
        if (_nodo != nullptr)
        {
            if (_nodo -> obtenerDoctorCita() == _cedula && _nodo -> obtenerFecha() == _fecha)
            {
                _citaRealizada.push_back(_nodo -> obtenerHora());
            }

            obtenerCita(_nodo -> obtenerIzquierda(), _citaRealizada, _cedula, _fecha);

            obtenerCita(_nodo -> obtenerDerecha(), _citaRealizada, _cedula, _fecha);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void nodosArboles<T>::mostrarArbol(nodos<T>* _nodo, vector<string>& _listaCodigos)
{
    try
    {
        if (_nodo != nullptr) 
        {
            mostrarArbol(_nodo -> obtenerIzquierda(), _listaCodigos);

            _listaCodigos.push_back(_nodo -> obtenerCodigo());

            mostrarArbol(_nodo -> obtenerDerecha(), _listaCodigos);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

template<class T>
void nodosArboles<T>::recorridoProfundidad(nodos<T>* _nodo, vector<string>& _listaCodigos)
{
    try
    {
        if (_nodo != nullptr) 
        {
            _listaCodigos.push_back(_nodo -> obtenerCodigo());

            recorridoProfundidad(_nodo -> obtenerIzquierda(), _listaCodigos);

            recorridoProfundidad(_nodo -> obtenerDerecha(), _listaCodigos);
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