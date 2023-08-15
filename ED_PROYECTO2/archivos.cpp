#include "archivos.h"

int archivos::tama�oString(string _texto)
{
	int cantidad = 0;						// Cantidad de letras en el string
	for (int i = 0; _texto[i] != '\0'; i++)	// Contar� la cantidad de letras que hay en el string
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

void archivos::guardarPaciente(arboles<pacientes> _arbolPaciente)
{
	try
	{
		if (_arbolPaciente.verificarVacio())
		{
			ofstream guardarPaciente("datosPaciente.dat");
			pacientes* paciente;
			queue<pacientes*> colaPaciente = _arbolPaciente.colaDatos();
			string dato;

			while (!colaPaciente.empty())
			{
				paciente = colaPaciente.front();
				dato = paciente -> getCedula() + "/" + paciente -> getNombre() + "/" + paciente -> getDireccion() + "/" + paciente -> getTelefono();
				guardarPaciente << dato << "\n";
				colaPaciente.pop();
			}

			guardarPaciente.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void archivos::guardarMedicamento(arboles<medicamentos> _arbolMedicamentos)
{
	try
	{
		if (_arbolMedicamentos.verificarVacio())
		{
			ofstream guardarMedicamentos("datosMedicamento.dat");
			medicamentos* medicamento;
			queue<medicamentos*> colaMedicamento = _arbolMedicamentos.colaDatos();
			string dato;

			while (!colaMedicamento.empty())
			{
				medicamento = colaMedicamento.front();
				dato = medicamento -> getCodigo() + "/" + medicamento -> getNombre() + "/" + to_string(medicamento -> getCantidadInventario());
				guardarMedicamentos << dato << "\n";
				colaMedicamento.pop();
			}

			guardarMedicamentos.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void archivos::guardarCita(arboles<citas> _arbolCita)
{
	try
	{
		if (_arbolCita.verificarVacio())
		{
			ofstream guardarCitas("datosCita.dat");
			citas* cita;
			queue<citas*> colaCita = _arbolCita.colaDatos();
			string dato;

			while (!colaCita.empty())
			{
				cita = colaCita.front();
				dato = cita -> getCodigo() + "/" + cita -> getFecha() + "/" + cita -> getHora() + "/" + cita -> getDoctor() -> getCedula() + "/" + cita -> getPaciente() -> getCedula();
				guardarCitas << dato << "\n";
				colaCita.pop();
			}

			guardarCitas.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void archivos::guardarRecetaMedica(arboles<recetaMedica> _arbolReceta)
{
	try
	{
		if (_arbolReceta.verificarVacio())
		{
			ofstream guardarReceta("datosReceta.dat");
			recetaMedica* receta;
			queue<recetaMedica*> colaReceta = _arbolReceta.colaDatos();
			string dato;

			while (!colaReceta.empty())
			{
				receta = colaReceta.front();
				dato = receta -> getCodigo() + "/" + receta -> getPaciente() -> getCedula() + "/" + receta -> getMedicamento() -> getCodigo() + "/" + to_string(receta -> getCantidad()) + "/" + to_string(receta -> getDosis()) + "/" + receta -> getFrecuencia();
				guardarReceta << dato << "\n";
				colaReceta.pop();
			}

			guardarReceta.close();
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
			while (getline(cargarDoctor, datos))
			{
				_doctor.setCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getCedula()) + 1);

				_doctor.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getNombre()) + 1);

				_doctor.setEspecialidad(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getEspecialidad()) + 1);

				_doctor.setDireccion(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getDireccion()) + 1);

				_doctor.setHoraInicio(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getHoraInicio()) + 1);

				_doctor.setHoraFin(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getHoraFin()) + 1);

				_doctor.setTelefono(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_doctor.getTelefono()) + 1);

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

arboles<pacientes> archivos::cargarPaciente()
{
	try
	{
		arboles<pacientes> arbolPaciente;
		pacientes _paciente;
		pacientes* paciente;

		// Cargar datos del archivo
		ifstream cargarPaciente("datosPaciente.dat");
		if (cargarPaciente.is_open())
		{
			string datos;
			while (getline(cargarPaciente, datos))
			{
				_paciente.setCedula(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_paciente.getCedula()) + 1);

				_paciente.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_paciente.getNombre()) + 1);

				_paciente.setDireccion(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_paciente.getDireccion()) + 1);

				_paciente.setTelefono(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_paciente.getTelefono()) + 1);

				paciente = new pacientes(_paciente.getCedula(), _paciente.getNombre(), _paciente.getDireccion(), _paciente.getTelefono());

				arbolPaciente.registrarDatos(paciente, _paciente.getCedula());
			}
		}
		cargarPaciente.close();

		return arbolPaciente;
	}
	catch (exception& e)
	{
		throw e;
	}
}

arboles<medicamentos> archivos::cargarMedicamento()
{
	try
	{
		arboles<medicamentos> arbolMedicamento;
		medicamentos _medicamento;
		medicamentos* medicamento;

		// Cargar datos del archivo
		ifstream cargarMedicamento("datosMedicamento.dat");
		if (cargarMedicamento.is_open())
		{
			string datos;
			while (getline(cargarMedicamento, datos))
			{
				_medicamento.setCodigo(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_medicamento.getCodigo()) + 1);

				_medicamento.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_medicamento.getNombre()) + 1);

				_medicamento.setCantidadInventario(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tama�oString(to_string(_medicamento.getCantidadInventario())) + 1);

				medicamento = new medicamentos(_medicamento.getCodigo(), _medicamento.getNombre(), _medicamento.getCantidadInventario());

				arbolMedicamento.registrarDatos(medicamento, _medicamento.getCodigo());
			}
		}
		cargarMedicamento.close();

		return arbolMedicamento;
	}
	catch (exception& e)
	{
		throw e;
	}
}

arboles<citas> archivos::cargarCita(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente)
{
	try
	{
		arboles<citas> arbolCita;
		citas _cita;
		citas* cita;
		string doctor;
		string paciente;

		// Cargar datos del archivo
		ifstream cargarCita("datosCita.dat");
		if (cargarCita.is_open())
		{
			string datos;
			while (getline(cargarCita, datos))
			{
				_cita.setCodigo(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_cita.getCodigo()) + 1);

				_cita.setFecha(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_cita.getFecha()) + 1);

				_cita.setHora(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_cita.getHora()) + 1);

				doctor = datos.substr(0, datos.find("/"));
				datos.erase(0, tama�oString(doctor) + 1);

				paciente = datos.substr(0, datos.find("/"));
				datos.erase(0, tama�oString(paciente) + 1);

				cita = new citas(_cita.getCodigo(), _cita.getFecha(), _cita.getHora(), _arbolDoctor.obtenerDatos(doctor), _arbolPaciente.obtenerDatos(paciente));

				arbolCita.registrarDatos(cita, _cita.getCodigo());
			}
		}
		cargarCita.close();

		return arbolCita;
	}
	catch (exception& e)
	{
		throw e;
	}
}

arboles<recetaMedica> archivos::cargarReceta(arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento)
{
	try
	{
		arboles<recetaMedica> arbolReceta;
		recetaMedica _receta;
		recetaMedica* receta;
		string paciente;
		string medicamento;

		// Cargar datos del archivo
		ifstream cargarReceta("datosReceta.dat");
		if (cargarReceta.is_open())
		{
			string datos;
			while (getline(cargarReceta, datos))
			{
				_receta.setCodigo(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_receta.getCodigo()) + 1);

				paciente = datos.substr(0, datos.find("/"));
				datos.erase(0, tama�oString(paciente) + 1);

				medicamento = datos.substr(0, datos.find("/"));
				datos.erase(0, tama�oString(medicamento) + 1);

				_receta.setCantidad(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tama�oString(to_string(_receta.getCantidad())) + 1);

				_receta.setDosis(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tama�oString(to_string(_receta.getDosis())) + 1);

				_receta.setFrecuencia(datos.substr(0, datos.find("/")));
				datos.erase(0, tama�oString(_receta.getFrecuencia()) + 1);

				receta = new recetaMedica(_receta.getCodigo(), _arbolPaciente.obtenerDatos(paciente), _arbolMedicamento.obtenerDatos(medicamento), _receta.getCantidad(), _receta.getDosis(), _receta.getFrecuencia());

				arbolReceta.registrarDatos(receta, _receta.getCodigo());
			}
		}
		cargarReceta.close();

		return arbolReceta;
	}
	catch (exception& e)
	{
		throw e;
	}
}