#include "recetasMedicas.h"

recetasMedicas::recetasMedicas(void) { }

recetasMedicas::recetasMedicas(
	string _codigo,
	pacientes* _paciente,
	string _diagnostico,
	medicamentos* _medicamento,
	int _cantidad,
	string _dosis,
	doctores* _doctor
) {
	codigo = _codigo;
	paciente = _paciente;
	diagnostico = _diagnostico;
	medicamento = _medicamento;
	cantidad = _cantidad;
	dosis = _dosis;
	doctor = _doctor;
}

recetasMedicas::~recetasMedicas() { }

// Getters
string recetasMedicas::getCodigo() { return codigo; }
pacientes* recetasMedicas::getPaciente() { return paciente; }
string recetasMedicas::getDiagnostico() { return diagnostico; }
medicamentos* recetasMedicas::getMedicamento() { return medicamento; }
int recetasMedicas::getCantidad() { return cantidad; }
string recetasMedicas::getDosis() { return dosis; }
doctores* recetasMedicas::getDoctor() { return doctor; }

// Setters
void recetasMedicas::setCodigo(string _codigo) { codigo = _codigo; }
void recetasMedicas::setPaciente(pacientes* _paciente) { paciente = _paciente; }
void recetasMedicas::setDiagnostico(string _diagnostico) { diagnostico = _diagnostico; }
void recetasMedicas::setMedicamento(medicamentos* _medicamento) { medicamento = _medicamento; }
void recetasMedicas::setCantidad(int _cantidad) { cantidad = _cantidad; }
void recetasMedicas::setDosis(string _dosis) { dosis = _dosis; }
void recetasMedicas::setDoctor(doctores* _doctor) { doctor = _doctor; }