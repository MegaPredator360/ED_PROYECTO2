#include "std.h"

// Clases de datos
#include "recetaMedica.h"

// Arboles
#include "arboles.h"

class archivos
{
public:
	// Contar cantidad de letras
	int tamañoString(string _texto);

	// Guardar Datos
	void guardarDoctor(arboles<doctores> _arbolDoctor);
	void guardarPaciente(arboles<pacientes> _arbolPaciente);
	void guardarMedicamento(arboles<medicamentos> _arbolMedicamentos);
	void guardarCita(arboles<citas> _arbolCita);
	void guardarRecetaMedica(arboles<recetaMedica> _arbolReceta);

	// Cargar Datos
	arboles<doctores> cargarDoctor();
	arboles<pacientes> cargarPaciente();
	arboles<medicamentos> cargarMedicamento();
	arboles<citas> cargarCita(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente);
	arboles<recetaMedica> cargarReceta(arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento, arboles<doctores> _arbolDoctor);
};

