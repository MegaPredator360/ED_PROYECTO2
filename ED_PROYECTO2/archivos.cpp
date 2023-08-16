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
		else
		{
			ofstream guardarDoctor("datosDoctor.dat");
			guardarDoctor << "";
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
		else
		{
			ofstream guardarPaciente("datosPaciente.dat");
			guardarPaciente << "";
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
		else
		{
			ofstream guardarMedicamentos("datosMedicamento.dat");
			guardarMedicamentos << "";
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
		else
		{
			ofstream guardarCitas("datosCita.dat");
			guardarCitas << "";
			guardarCitas.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void archivos::guardarFactura(arboles<facturas> _arbolFactura)
{
	try
	{
		if (_arbolFactura.verificarVacio())
		{
			ofstream guardarFacturas("datosFactura.dat");
			facturas* factura;
			queue<facturas*> colaFactura = _arbolFactura.colaDatos();
			string dato;

			while (!colaFactura.empty())
			{
				factura = colaFactura.front();
				dato = factura -> getCodigo() + "/" + factura -> getFecha() + "/" + factura -> getPaciente() -> getCedula() + "/" + to_string(factura -> getMonto());
				guardarFacturas << dato << "\n";
				colaFactura.pop();
			}

			guardarFacturas.close();
		}
		else
		{
			ofstream guardarFacturas("datosFactura.dat");
			guardarFacturas << "";
			guardarFacturas.close();
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void archivos::guardarRecetaMedica(arboles<recetasMedicas> _arbolReceta)
{
	try
	{
		if (_arbolReceta.verificarVacio())
		{
			ofstream guardarReceta("datosReceta.dat");
			recetasMedicas* receta;
			queue<recetasMedicas*> colaReceta = _arbolReceta.colaDatos();
			string dato;

			while (!colaReceta.empty())
			{
				receta = colaReceta.front();
				dato = receta -> getCodigo() + "/" + receta -> getPaciente() -> getCedula() + "/" + receta -> getDiagnostico() + "/" + receta -> getMedicamento() -> getCodigo() + "/" + to_string(receta -> getCantidad()) + "/" + receta -> getDosis() + "/" + receta -> getDoctor() -> getCedula();
				guardarReceta << dato << "\n";
				colaReceta.pop();
			}

			guardarReceta.close();
		}
		else
		{
			ofstream guardarReceta("datosReceta.dat");
			guardarReceta << "";
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
				datos.erase(0, tamañoString(_paciente.getCedula()) + 1);

				_paciente.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_paciente.getNombre()) + 1);

				_paciente.setDireccion(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_paciente.getDireccion()) + 1);

				_paciente.setTelefono(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_paciente.getTelefono()) + 1);

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
				datos.erase(0, tamañoString(_medicamento.getCodigo()) + 1);

				_medicamento.setNombre(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_medicamento.getNombre()) + 1);

				_medicamento.setCantidadInventario(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tamañoString(to_string(_medicamento.getCantidadInventario())) + 1);

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
				datos.erase(0, tamañoString(_cita.getCodigo()) + 1);

				_cita.setFecha(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_cita.getFecha()) + 1);

				_cita.setHora(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_cita.getHora()) + 1);

				doctor = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(doctor) + 1);

				paciente = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(paciente) + 1);

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

arboles<facturas> archivos::cargarFactura(arboles<pacientes> _arbolPaciente)
{
	try
	{
		arboles<facturas> arbolFactura;
		facturas _factura;
		facturas* factura;
		string paciente;

		// Cargar datos del archivo
		ifstream cargarFactura("datosFactura.dat");
		if (cargarFactura.is_open())
		{
			string datos;
			while (getline(cargarFactura, datos))
			{
				_factura.setCodigo(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_factura.getCodigo()) + 1);

				_factura.setFecha(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_factura.getFecha()) + 1);

				paciente = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(paciente) + 1);

				_factura.setMonto(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tamañoString(to_string(_factura.getMonto())) + 1);

				factura = new facturas(_factura.getCodigo(), _factura.getFecha(), _arbolPaciente.obtenerDatos(paciente), _factura.getMonto());

				arbolFactura.registrarDatos(factura, _factura.getCodigo());
			}
		}
		cargarFactura.close();

		return arbolFactura;
	}
	catch (exception& e)
	{
		throw e;
	}
}

arboles<recetasMedicas> archivos::cargarReceta(arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento, arboles<doctores> _arbolDoctor)
{
	try
	{
		arboles<recetasMedicas> arbolReceta;
		recetasMedicas _receta;
		recetasMedicas* receta;
		string paciente;
		string medicamento;
		string doctor;

		// Cargar datos del archivo
		ifstream cargarReceta("datosReceta.dat");
		if (cargarReceta.is_open())
		{
			string datos;
			while (getline(cargarReceta, datos))
			{
				_receta.setCodigo(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_receta.getCodigo()) + 1);

				paciente = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(paciente) + 1);

				_receta.setDiagnostico(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_receta.getDiagnostico()) + 1);

				medicamento = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(medicamento) + 1);

				_receta.setCantidad(stoi(datos.substr(0, datos.find("/"))));
				datos.erase(0, tamañoString(to_string(_receta.getCantidad())) + 1);

				_receta.setDosis(datos.substr(0, datos.find("/")));
				datos.erase(0, tamañoString(_receta.getDosis()) + 1);

				doctor = datos.substr(0, datos.find("/"));
				datos.erase(0, tamañoString(doctor) + 1);

				receta = new recetasMedicas(_receta.getCodigo(), _arbolPaciente.obtenerDatos(paciente), _receta.getDiagnostico(), _arbolMedicamento.obtenerDatos(medicamento), _receta.getCantidad(), _receta.getDosis(), _arbolDoctor.obtenerDatos(doctor));

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
