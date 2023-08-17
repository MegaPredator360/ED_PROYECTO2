#ifndef MEDICAMENTOS_H
#define	MEDICAMENTOS_H

#include "std.h"

class medicamentos
{
protected:
	string codigo;
	string nombre;
	int cantidadInventario;

public:
	// Constructor vacio
	medicamentos();

	// Constructor lleno
	medicamentos(
		string _codigo,
		string _nombre,
		int _cantidadInventario
	);

	// Destructor
	virtual ~medicamentos();

	// Getters
	virtual string getCodigo();
	virtual string getNombre();
	virtual int getCantidadInventario();

	// Setters
	void setCodigo(string _codigo);
	void setNombre(string _nombre);
	void setCantidadInventario(int _cantidadInventario);
};

#endif