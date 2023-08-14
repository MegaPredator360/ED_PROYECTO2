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

	// Cargar Datos
	arboles<doctores> cargarDoctor();
};

