// Validaciones en la interface
#include "metodoInterfaz.h"

class interfaz
{
protected:
	// Variables del men�
	int opcion;

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
	archivos _archivo;

public:
	void menuPrincipal();
};

