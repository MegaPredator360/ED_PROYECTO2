#include "std.h"

class doctores
{
protected:
	string cedula;
	string nombre;
	string especialidad;
	string direccion;
	string horaInicio;
	string horaFin;
	string telefono;

public:
	// Constructor vacio
	doctores();

	// Constructor lleno
	doctores(
		string _cedula,
		string _nombre,
		string _especialidad,
		string _direccion,
		string _horaInicio,
		string _horaFin,
		string _telefono
	);

	// Destructor
	~doctores();

	// Getters
	string getCedula();
	string getNombre();
	string getEspecialidad();
	string getDireccion();
	string getHoraInicio();
	string getHoraFin();
	string getTelefono();

	// Setters
	void setCedula(string _cedula);
	void setNombre(string _nombre);
	void setEspecialidad(string _especialidad);
	void setDireccion(string _direccion);
	void setHoraInicio(string _horaInicio);
	void setHoraFin(string _horaFin);
	void setTelefono(string _telefono);
};

