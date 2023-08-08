#include "pacientes.h"

pacientes::pacientes() { }

pacientes::pacientes(
	string _cedula,
	string _nombre,
	string _direccion,
	string _telefono
) {
	cedula = _cedula;
	nombre = _nombre;
	direccion = _direccion;
	telefono = _telefono;
}

pacientes::~pacientes() { }

// Getters
string pacientes::getCedula() { return cedula; }
string pacientes::getNombre() { return nombre; }
string pacientes::getDireccion() { return direccion; }
string pacientes::getTelefono() { return telefono; }

// Setters
void pacientes::setCedula(string _cedula) { cedula = _cedula; }
void pacientes::setNombre(string _nombre) { nombre = _nombre; }
void pacientes::setDireccion(string _direccion) { direccion = _direccion; }
void pacientes::setTelefono(string _telefono) { telefono = _telefono; }
