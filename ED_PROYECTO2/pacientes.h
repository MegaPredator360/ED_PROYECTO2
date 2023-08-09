#include "doctores.h"

class pacientes
{
protected:
	string cedula;
	string nombre;
	string direccion;
	string telefono;

public:
	// Constructor vacio
	pacientes();

	// Constructor llenos
	pacientes(
		string _cedula,
		string _nombre,
		string _direccion,
		string _telefono
	);

	// Destructor
	~pacientes();

	// Getters
	string getCedula();
	string getNombre();
	string getDireccion();
	string getTelefono();

	// Setters
	void setCedula(string _cedula);
	void setNombre(string _nombre);
	void setDireccion(string _direccion);
	void setTelefono(string _telefono);
};

