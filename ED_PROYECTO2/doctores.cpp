#include "doctores.h"

// Constructor vacio
doctores::doctores() { }

// Constructor lleno
doctores::doctores(
	string _cedula,
	string _nombre,
	string _especialidad,
	string _direccion,
	string _horaInicio,
	string _horaFin,
	string _telefono
) {
	cedula = _cedula;
	nombre = _nombre;
	especialidad = _especialidad;
	direccion = _direccion;
	horaInicio = _horaInicio;
	horaFin = _horaFin;
	telefono = _telefono;
}

// Destructor
doctores::~doctores() { }

// Getters
string doctores::getCedula() { return cedula; }
string doctores::getNombre() { return nombre; }
string doctores::getEspecialidad() { return especialidad; }
string doctores::getDireccion() { return direccion; }
string doctores::getHoraInicio() { return horaInicio; }
string doctores::getHoraFin() { return horaFin; }
string doctores::getTelefono() { return telefono; }

// Setters
void doctores::setCedula(string _cedula) { cedula = _cedula; }
void doctores::setNombre(string _nombre) { nombre = _nombre; }
void doctores::setEspecialidad(string _especialidad) { especialidad = _especialidad; }
void doctores::setDireccion(string _direccion) { direccion = _direccion; }
void doctores::setHoraInicio(string _horaInicio) { horaInicio = _horaInicio; }
void doctores::setHoraFin(string _horaFin) { horaFin = _horaFin; }
void doctores::setTelefono(string _telefono) { telefono = _telefono; }