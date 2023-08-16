#include "std.h"

// Clases de datos
#include "recetasMedicas.h"

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
	void guardarFactura(arboles<facturas> _arbolFactura);
	void guardarRecetaMedica(arboles<recetasMedicas> _arbolReceta);

	// Cargar Datos
	arboles<doctores> cargarDoctor();
	arboles<pacientes> cargarPaciente();
	arboles<medicamentos> cargarMedicamento();
	arboles<citas> cargarCita(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente);
	arboles<facturas> cargarFactura(arboles<pacientes> _arbolPaciente);
	arboles<recetasMedicas> cargarReceta(arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento, arboles<doctores> _arbolDoctor);
};

