#include "facturas.h"

facturas::facturas(void) { }

facturas::facturas(
	string _codigo,
	string _fecha,
	pacientes* _paciente,
	int _monto
) {
	codigo = _codigo;
	fecha = _fecha;
	paciente = _paciente;
	monto = _monto;
}

facturas::~facturas() { }

// Getters
string facturas::getCodigo() { return codigo; }
string facturas::getFecha() { return fecha; }
pacientes* facturas::getPaciente() { return paciente; }
int facturas::getMonto() { return monto; }

// Setters
void facturas::setCodigo(string _codigo) { codigo = _codigo; }
void facturas::setFecha(string _fecha) { fecha = _fecha; }
void facturas::setPaciente(pacientes* _paciente) { paciente = _paciente; }
void facturas::setMonto(int _monto) { monto = _monto; }
