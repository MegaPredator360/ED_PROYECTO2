#include "facturas.h"

facturas::facturas(void) { }

facturas::facturas(
	int _numeroFactura,
	string _fecha,
	citas _cita,
	float _monto
) {
	numeroFactura = _numeroFactura;
	fecha = _fecha;
	cita = _cita;
	monto = _monto;
}

facturas::~facturas() { }

// Getters
int facturas::getNumeroFactura() { return numeroFactura; }
string facturas::getFecha() { return fecha; }
citas facturas::getCita() { return cita; }
float facturas::getMonto() { return monto; }

// Setters
void facturas::setNumeroFactura(int _numeroFactura) { numeroFactura = _numeroFactura; }
void facturas::setFecha(string _fecha) { fecha = _fecha; }
void facturas::setCita(citas _cita) { cita = _cita; }
void facturas::setMonto(float _monto) { monto = _monto; }
