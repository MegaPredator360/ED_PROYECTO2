#include "recetaMedica.h"

recetaMedica::recetaMedica(void) { }

recetaMedica::recetaMedica(
	string _codigo,
	pacientes _paciente,
	medicamentos _medicamento,
	int _cantidad,
	float _dosis,
	string _frecuencia
) {
	codigo = _codigo;
	paciente = _paciente;
	medicamento = _medicamento;
	cantidad = _cantidad;
	dosis = _dosis;
	frecuencia = _frecuencia;
}

recetaMedica::~recetaMedica() { }

// Getters
string recetaMedica::getCodigo() { return codigo; }
pacientes recetaMedica::getPaciente() { return paciente; }
medicamentos recetaMedica::getMedicamento() { return medicamento; }
int recetaMedica::getCantidad() { return cantidad; }
float recetaMedica::getDosis() { return dosis; }
string recetaMedica::getFrecuencia() { return frecuencia; }

// Setters
void recetaMedica::setCodigo(string _codigo) { codigo = _codigo; }
void recetaMedica::setPaciente(pacientes _paciente) { paciente = _paciente; }
void recetaMedica::setMedicamento(medicamentos _medicamento) { medicamento = _medicamento; }
void recetaMedica::setCantidad(int _cantidad) { cantidad = _cantidad; }
void recetaMedica::setDosis(float _dosis) { dosis = _dosis; }
void recetaMedica::setFrecuencia(string _frecuencia) { frecuencia = _frecuencia; }