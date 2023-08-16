// Validaciones en la interface
#include "metodoInterfaz.h"

class interfaz
{
protected:
	// Variables del men�
	int opcion;

	// Variables para llenar datos
	string dato;
	string hora;
	int cantidad;
	vector<string> listaCodigos;

	// Arboles
	arboles<doctores> arbolDoctor;
	arboles<pacientes> arbolPaciente;
	arboles<medicamentos> arbolMedicamento;
	arboles<citas> arbolCita;
	arboles<facturas> arbolFactura;
	arboles<recetasMedicas> arbolRecetaMedica;

	// Llamados a clases - Punteros
	doctores* doctor;
	pacientes* paciente;
	medicamentos* medicamento;
	citas* cita;
	facturas* factura;
	recetasMedicas* recetaMedica;
;
	// Llamados a clases
	doctores _doctor;
	pacientes _paciente;
	medicamentos _medicamento;
	citas _cita;
	facturas _factura;
	recetasMedicas _recetaMedica;
	metodoInterfaz _mInterfaz;
	archivos _archivo;

public:
	void menuPrincipal();
};

