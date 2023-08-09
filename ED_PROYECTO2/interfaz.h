#include "metodoInterfaz.h"
#include "doctores.h"
#include "arboles.h"

class interfaz
{
protected:
	// Variables del menú
	int opcion;
	char confirmacion;

	// Variables para llenar datos
	string cedula;
	string codigo;
	string nombre;
	string especialidad;
	string direccion;
	string horaInicio;
	string horaFinal;
	string telefono;
	string paciente;
	string doctor;
	string fecha;
	string hora;

	// Arboles
	arboles<doctores> arbolDoctor;

	// Llamados a clases
	doctores* _doctor;
public:
	void menuPrincipal();
};

