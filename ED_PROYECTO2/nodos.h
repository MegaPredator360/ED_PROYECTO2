template <class T>
class nodos
{
protected:
	// Informaci�n del nodo actual
	T* info;

	// Informacion del nodo siguiente
	nodos<T>* siguiente;

public:
	// Contenedor
	nodos(T*, nodos<T>*);
	~nodo();
};

