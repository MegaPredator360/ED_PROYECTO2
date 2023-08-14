#include "citas.h"

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
		pacientes* _paciente,
		medicamentos* _medicamento,
		int _cantidad,
		float _dosis,
		string _frecuencia
	);

	// Destructor
	virtual ~recetaMedica();

	// Getters
	virtual string getCodigo();
	virtual pacientes* getPaciente();
	virtual medicamentos* getMedicamento();
	virtual int getCantidad();
	virtual float getDosis();
	virtual string getFrecuencia();

	// Setters
	void setCodigo(string _codigo);
	void setPaciente(pacientes* _paciente);
	void setMedicamento(medicamentos* _medicamento);
	void setCantidad(int _cantidad);
	void setDosis(float _dosis);
	void setFrecuencia(string _frecuencia);
};

