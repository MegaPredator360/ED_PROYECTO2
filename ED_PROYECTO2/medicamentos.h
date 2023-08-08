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
	~medicamentos();

	// Getters
	string getCodigo();
	string getNombre();
	int getCantidadInventario();

	// Setters
	void setCodigo(string _codigo);
	void setNombre(string _nombre);
	void setCantidadInventario(int _cantidadInventario);
};

