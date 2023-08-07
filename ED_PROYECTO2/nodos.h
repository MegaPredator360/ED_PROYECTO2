template <class T>
class nodos
{
protected:
	// Informaci�n del nodo actual
	T* info;

	// Informacion del nodo siguiente
	nodos<T>* siguiente;

public:
	// Constructor
	nodos(T*, nodos<T>*);

	// Destructor
	virtual ~nodos();

	// Obtendr� el contenido del nodo
	virtual T* obtenerInfo() const;

	// Obtendr� el contenido del siguiente nodo
	virtual nodos<T>* obtenerSiguiente() const;

	// Fijar� el siguiente nodo
	virtual void fijarSiguiente(nodos<T>*);
};

template<class T>
nodos<T>::nodos(T* _nuevaInfo, nodos<T>* _siguiente)
{
	info = _nuevaInfo;
	this -> siguiente = siguiente;
}

template<class T>
nodos<T>::~nodos() { }

template<class T>
T* nodos<T>::obtenerInfo() const
{
	return info;
}

template<class T>
nodos<T>* nodos<T>::obtenerSiguiente() const
{
	return siguiente;
}

template<class T>
void nodos<T>::fijarSiguiente(nodos<T>* _siguiente)
{
	this -> siguiente = _siguiente;
}