#include "recetaMedica.h"

recetaMedica::recetaMedica(void) { }

recetaMedica::recetaMedica(
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

recetaMedica::~recetaMedica() { }

// Getters
string recetaMedica::getCodigo() { return codigo; }
pacientes* recetaMedica::getPaciente() { return paciente; }
string recetaMedica::getDiagnostico() { return diagnostico; }
medicamentos* recetaMedica::getMedicamento() { return medicamento; }
int recetaMedica::getCantidad() { return cantidad; }
string recetaMedica::getDosis() { return dosis; }
doctores* recetaMedica::getDoctor() { return doctor; }

// Setters
void recetaMedica::setCodigo(string _codigo) { codigo = _codigo; }
void recetaMedica::setPaciente(pacientes* _paciente) { paciente = _paciente; }
void recetaMedica::setDiagnostico(string _diagnostico) { diagnostico = _diagnostico; }
void recetaMedica::setMedicamento(medicamentos* _medicamento) { medicamento = _medicamento; }
void recetaMedica::setCantidad(int _cantidad) { cantidad = _cantidad; }
void recetaMedica::setDosis(string _dosis) { dosis = _dosis; }
void recetaMedica::setDoctor(doctores* _doctor) { doctor = _doctor; }