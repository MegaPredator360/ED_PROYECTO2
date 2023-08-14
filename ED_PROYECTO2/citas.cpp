#include "citas.h"

citas::citas(void) { }

citas::citas(
	string _codigo,
	string _fecha,
	string _hora,
	doctores* _doctor,
	pacientes* _paciente
) {
	codigo = _codigo;
	fecha = _fecha;
	hora = _hora;
	doctor = _doctor;
	paciente = _paciente;
}

citas::~citas() { }

// Getters
string citas::getCodigo() { return codigo; }
string citas::getFecha() { return fecha; }
string citas::getHora() { return hora; }
doctores* citas::getDoctor() { return doctor; }
pacientes* citas::getPaciente() { return paciente; }

// Setters
void citas::setCodigo(string _codigo) { codigo = _codigo; }
void citas::setFecha(string _fecha) { fecha = _fecha; }
void citas::setHora(string _hora) { hora = _hora; }
void citas::setDoctor(doctores* _doctor) { doctor = _doctor; }
void citas::setPaciente(pacientes* _paciente) { paciente = _paciente; }