#include "medicamentos.h"
#include "pacientes.h"

class recetaMedica
{
protected:
	string codigo;
	pacientes paciente;
	medicamentos medicamento;
	int cantidad;
	float dosis;
	string frecuencia;

public:
	// Constructor vacio
	recetaMedica(void);

	// Constructor lleno
	recetaMedica(
		string _codigo,
		pacientes _paciente,
		medicamentos _medicamento,
		int _cantidad,
		float _dosis,
		string _frecuencia
	);

	// Destructor
	~recetaMedica();

	// Getters
	string getCodigo();
	pacientes getPaciente();
	medicamentos getMedicamento();
	int getCantidad();
	float getDosis();
	string getFrecuencia();

	// Setters
	void setCodigo(string _codigo);
	void setPaciente(pacientes _paciente);
	void setMedicamento(medicamentos _medicamento);
	void setCantidad(int _cantidad);
	void setDosis(float _dosis);
	void setFrecuencia(string _frecuencia);
};

