// Validaciones en la interface
#include "metodoInterfaz.h"

// Clases de datos
#include "recetaMedica.h"

// Arboles
#include "arboles.h"

class interfaz
{
protected:
	// Variables del menú
	int opcion;
	string confirmacion;

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
	int cantidad;

	// Arboles
	arboles<doctores> arbolDoctor;
	arboles<pacientes> arbolPaciente;
	arboles<medicamentos> arbolMedicamento;
	arboles<citas> arbolCita;
	arboles<recetaMedica> arbolRecetaMedica;

	// Llamados a clases
	doctores* _doctor;
	pacientes* _paciente;
	medicamentos* _medicamento;
	citas* _citas;
	recetaMedica* _recetaMedica;
	metodoInterfaz _mInterfaz;

public:
	void menuPrincipal();
};

