#include "medicamentos.h"

medicamentos::medicamentos() { }

medicamentos::medicamentos(
	string _codigo,
	string _nombre,
	int _cantidadInventario
) {
	codigo = _codigo;
	nombre = _nombre;
	cantidadInventario = _cantidadInventario;
}

medicamentos::~medicamentos() { }

// Getters
string medicamentos::getCodigo() { return codigo; }
string medicamentos::getNombre() { return nombre; }
int medicamentos::getCantidadInventario() { return cantidadInventario; }

// Setters
void medicamentos::setCodigo(string _codigo) { codigo = _codigo; }
void medicamentos::setNombre(string _nombre) { nombre = _nombre; }
void medicamentos::setCantidadInventario(int _cantidadInventario) { cantidadInventario = _cantidadInventario; }