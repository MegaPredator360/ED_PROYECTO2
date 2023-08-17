#ifndef RECETASMEDICAS_H
#define	RECETASMEDICAS_H

#include "medicamentos.h"
#include "doctores.h"
#include "pacientes.h"

class recetasMedicas
{
protected:
	string codigo;
	pacientes* paciente;
	string diagnostico;
	medicamentos* medicamento;
	int cantidad;
	string dosis;
	doctores* doctor;

public:
	// Constructor vacio
	recetasMedicas(void);

	// Constructor lleno
	recetasMedicas(
		string _codigo,
		pacientes* _paciente,
		string _diagnostico,
		medicamentos* _medicamento,
		int _cantidad,
		string _dosis,
		doctores* _doctor
	);

	// Destructor
	virtual ~recetasMedicas();

	// Getters
	virtual string getCodigo();
	virtual pacientes* getPaciente();
	virtual string getDiagnostico();
	virtual medicamentos* getMedicamento();
	virtual int getCantidad();
	virtual string getDosis();
	virtual doctores* getDoctor();

	// Setters
	void setCodigo(string _codigo);
	void setPaciente(pacientes* _paciente);
	void setDiagnostico(string _diagnostico);
	void setMedicamento(medicamentos* _medicamento);
	void setCantidad(int _cantidad);
	void setDosis(string _dosis);
	void setDoctor(doctores* _doctor);
};

#endif