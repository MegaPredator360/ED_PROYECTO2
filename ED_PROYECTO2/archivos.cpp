#include "archivos.h"

int archivos::tamañoString(string _texto)
{
	int cantidad = 0;						// Cantidad de letras en el string
	for (int i = 0; _texto[i] != '\0'; i++)	// Contará la cantidad de letras que hay en el string
	{
		cantidad++;
	}
	return cantidad;
}

void archivos::guardarDoctor(arboles<doctores> _arbolDoctor) 
{
	try
	{
		if (_arbolDoctor.verificarVacio())
		{
			ofstream guardarDoctor("datosDoctor.dat");
			doctores* doctor;
			queue<doctores*> colaDoctor = _arbolDoctor.colaDatos();
			string dato;

			while (!colaDoctor.empty())
			{
				doctor = colaDoctor.front();
				dato = doctor -> getCedula() + "/" + doctor -> getNombre() + "/" + doctor -> getEspecialidad() + "/" + doctor -> getDireccion() + "/" + doctor -> getHoraInicio() + "/" + doctor -> getHoraFin() + "/" + doctor -> getTelefono();
				guardarDoctor << dato << "\n";
				colaDoctor.pop();
			}

			guardarDoctor.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

arboles<doctores> archivos::cargarDoctor()
{
	try
	{
		arboles<doctores> arbolDoctor;
		doctores _doctor;
		doctores* doctor;

		// Cargar datos del archivo
		ifstream cargarDoctor("datosDoctor.dat");
		if (cargarDoctor.is_open())
		{
			string datos;
			int cantidadLetras;
			while (getline(cargarDoctor, datos))
			{
				_doctor.setCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getCedula()) + 1);

				_doctor.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getNombre()) + 1);

				_doctor.setEspecialidad(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getEspecialidad()) + 1);

				_doctor.setDireccion(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getDireccion()) + 1);

				_doctor.setHoraInicio(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getHoraInicio()) + 1);

				_doctor.setHoraFin(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getHoraFin()) + 1);

				_doctor.setTelefono(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_doctor.getTelefono()) + 1);

				doctor = new doctores(_doctor.getCedula(), _doctor.getNombre(), _doctor.getEspecialidad(), _doctor.getDireccion(), _doctor.getHoraInicio(), _doctor.getHoraFin(), _doctor.getTelefono());

				arbolDoctor.registrarDatos(doctor, _doctor.getCedula());
			}
		}
		cargarDoctor.close();

		return arbolDoctor;
	}
	catch (exception& e)
	{
		throw e;
	}
}
