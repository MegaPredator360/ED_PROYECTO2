#include "metodoInterfaz.h"

void metodoInterfaz::color(int _color)
{
	// Obtendrá el codigo de color para la consola
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void metodoInterfaz::moverXY(int _x, int _y)
{
	// Este tipo de dato indica las coordenadas de donde se escribirá el texto
	COORD c;
	c.X = _x;
	c.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string metodoInterfaz::ingresarNumeros()
{
	int asciiChar = 0;
	string num = "";
	do 
	{
		asciiChar = _getch();						// Obtendra las teclas de formato ASCII 

		if (asciiChar == 13 && num != "")			// Hará la funcion del enter
		{
			break;									// Terminará el while
		}
		else if (asciiChar == 8 && num == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio esté vacio
		}
		else if (asciiChar == 8)					// Hará la funcion del Backspace
		{
			cout << '\b';							// Moverá el cursor un caracter atrás
			cout << " ";							// Remplazará el valor por un espacio
			cout << '\b';
			num = num.substr(0, num.size() - 1);	// Borrará el ultimo valor del string
		}
		else if (num.length() > 49)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio esté vacio
		}
		else if (asciiChar >= 48 && asciiChar <= 57)		// Validaremos solo los valores que sean equivalentes a numeros
		{
			asciiChar = (asciiChar - 48);			// Los valores de ASCII para numeros 0-9 es igual a 48 hasta 57, por lo que se le resta a 48 por ser equivalente a 0
			cout << asciiChar;						// Se imprime el valor
			num = num + to_string(asciiChar);		// Convertir de Int a String para poder concatenar
		}
	} 
	while (1);

	return (num);
}

string metodoInterfaz::ingresarHora()
{
	string hora = "12:00";
	int selector[] = { 71 };
	int marcador = 1;
	int key = 0;

	while (1)
	{
		moverXY(25, 7);
		color(selector[0]);
		cout << hora;

		key = _getch();


		// Valida si la flecha izquierda fue pulsada, valor 224 en ASCII
		if (key == 224)
		{
			key = _getch();

			if (key == 72)
			{
				int horaNum = stoi(hora.substr(0, 2));
				horaNum++;

				if (horaNum == 24)
				{
					horaNum = 0;
				}

				hora = to_string(horaNum);

				if (hora.size() == 1)
				{
					hora = "0" + hora + ":00";
				}
				else
				{
					hora = hora + ":00";
				}
			}
			else if (key == 80)
			{
				int horaNum = stoi(hora.substr(0, 2));
				horaNum--;

				if (horaNum == -1)
				{
					horaNum = 23;
				}

				hora = to_string(horaNum);

				if (hora.size() == 1)
				{
					hora = "0" + hora + ":00";
				}
				else
				{
					hora = hora + ":00";
				}
			}
		}
		else if (key == '\r')
		{
			break;
		}
	}

	return hora;
}

string metodoInterfaz::ingresarFecha()
{
	string dia = "01";
	string mes = "01";
	string año = "2023";

	int key;
	int selector[] = { 71, 128, 128 };
	int marcador = 1;

	moverXY(25, 7);
	cout << "Dia: ";

	moverXY(33, 7);
	cout << "- Mes: ";

	moverXY(43, 7);
	cout << "- Año: ";

	while (1)
	{
		moverXY(30, 7);
		color(selector[0]);
		cout << dia;

		moverXY(40, 7);
		color(selector[1]);
		cout << mes;

		moverXY(50, 7);
		color(selector[2]);
		cout << año;

		key = _getch();

		if (key == 224)
		{
			key = _getch();

			if (key == 72)
			{
				if (marcador == 1)
				{
					int diaNum = stoi(dia);

					diaNum++;

					if (diaNum == 32)
					{
						diaNum = 1;
					}

					dia = to_string(diaNum);

					if (dia.size() == 1)
					{
						dia = "0" + dia;
					}
				}
				else if (marcador == 2)
				{
					int mesNum = stoi(mes);

					mesNum++;

					if (mesNum == 13)
					{
						mesNum = 1;
					}

					mes = to_string(mesNum);

					if (mes.size() == 1)
					{
						mes = "0" + mes;
					}
				}
				else if (marcador == 3)
				{
					int añoNum = stoi(año);

					añoNum++;

					año = to_string(añoNum);

					if (año.size() == 1)
					{
						año = "0" + año;
					}
				}
			}
			else if (key == 80)
			{
				if (marcador == 1)
				{
					int diaNum = stoi(dia);

					diaNum--;

					if (diaNum == 0)
					{
						diaNum = 31;
					}

					dia = to_string(diaNum);

					if (dia.size() == 1)
					{
						dia = "0" + dia;
					}
				}
				else if (marcador == 2)
				{
					int mesNum = stoi(mes);

					mesNum--;

					if (mesNum == 0)
					{
						mesNum = 12;
					}

					mes = to_string(mesNum);

					if (mes.size() == 1)
					{
						mes = "0" + mes;
					}
				}
				else if (marcador == 3 && año != "2023")
				{
					int añoNum = stoi(año);

					añoNum--;

					año = to_string(añoNum);

					if (año.size() == 1)
					{
						año = "0" + año;
					}
				}
			}
			else if (key == 77)
			{
				marcador++;

				if (marcador == 4)
				{
					marcador = 1;
				}
			}
			else if (key == 75)
			{
				marcador--;

				if (marcador == 0)
				{
					marcador = 3;
				}
			}
		}
		else if (key == '\r')
		{
			break;
		}

		selector[0] = 128;
		selector[1] = 128;
		selector[2] = 128;

		switch (marcador)
		{
		case 1:
			selector[0] = 71;
			break;

		case 2:
			selector[1] = 71;
			break;

		case 3:
			selector[2] = 71;
			break;
		}
	}

	return dia + mes + año;
}

int metodoInterfaz::confirmarDatos(string _texto, int _posicion)
{
	// Usando el mismo sistema de la interface, se recibirá un texto para que el usuario escoja si desea realizar
	// la accion o no, y se recibira un "int _posicion" que en la posicion en Y donde aparecerá el texto
	int key;
	int nConfirmacion = 1;
	int oConfirmacion[] = { 71, 128 };

	color(128);
	moverXY(25, _posicion);
	cout << _texto;
	moverXY(28, _posicion + 1);
	cout << "/";

	while (1)
	{
		moverXY(25, _posicion + 1);
		color(oConfirmacion[0]);
		cout << "Sí";

		moverXY(30, _posicion + 1);
		color(oConfirmacion[1]);
		cout << "No";

		key = _getch();

		if (key == 224)
		{

			key = _getch();

			// Valida si la flecha izquierda fue pulsada, valor 77 en ASCII
			if (key == 77)
			{
				nConfirmacion--;

				if (nConfirmacion == 0)
				{
					nConfirmacion = 2;
				}
			}
			// Valida si la flecha izquierda fue pulsada, valor 75 en ASCII
			else if (key == 75)
			{
				nConfirmacion++;

				if (nConfirmacion == 3)
				{
					nConfirmacion = 1;
				}
			}
		}
		else if (key == '\r')
		{
			break;
		}

		oConfirmacion[0] = 128;
		oConfirmacion[1] = 128;

		switch (nConfirmacion)
		{
		case 1:
			oConfirmacion[0] = 71;
			break;

		case 2:
			oConfirmacion[1] = 71;
			break;
		}
	}
	cout << "\033[44m";

	return nConfirmacion;
}

void metodoInterfaz::mostrarMensajeExito(string _mensaje)
{
	// Se creará un cuadro de mensaje mostrando que una accion se la realizado con exito
	int key;
	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');

	system("cls");

	cout << "\033[44m\033[30m" << espacios << endl;
	cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
	}

	cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << "\033[44m\033[30m" << espacios;

	moverXY(55, 4);
	cout << "\033[100m\033[30m" << "¡Exito!";

	moverXY(25, 6);
	cout << _mensaje;

	moverXY(55, 8);
	cout << "\033[41m\033[37m" << "Aceptar";

	// Se esperará a que el usuario pulse la tecla ENTER para continuar
	while (1)
	{
		key = _getch();

		if (key == '\r')
		{
			break;
		}
	}

	cout << "\033[44m\033[30m";
}

void metodoInterfaz::mostrarMensajeFallido(string _mensaje)
{
	// Se creará un cuadro de mensaje mostrando que ha ocurrido un error durante el proceso de X accion
	int key;
	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');

	system("cls");

	cout << "\033[44m\033[30m" << espacios << endl;
	cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
	}

	cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << "\033[44m\033[30m" << espacios;

	moverXY(55, 4);
	cout << "\033[100m\033[30m" << "¡Error!";

	moverXY(25, 6);
	cout << _mensaje;

	moverXY(55, 8);
	cout << "\033[41m\033[37m" << "Aceptar";

	while (1)
	{
		key = _getch();

		if (key == '\r')
		{
			break;
		}
	}

	cout << "\033[44m\033[30m";
}

void metodoInterfaz::verificarVacio(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento)
{
	try
	{
		// Este medodo se usa para el momento de ingresar cita, donde se verificara si hay datos en los 3 arboles, de los contrario
		// se le mostrará al usuario cual arbol no tiene datos para insertarlos
		string mensajeError = "No hay registros de los siguientes datos: ";
		bool doctor = false;
		bool paciente = false;
		bool medicamento = false;

		if (!_arbolDoctor.verificarVacio())
		{
			doctor = true;
		}

		if (!_arbolPaciente.verificarVacio())
		{
			paciente = true;
		}

		if (!_arbolMedicamento.verificarVacio())
		{
			medicamento = true;
		}

		if (doctor || paciente || medicamento)
		{
			if (doctor)
			{
				mensajeError = mensajeError + "doctores ";
			}

			if (paciente)
			{
				mensajeError = mensajeError + "pacientes ";
			}

			if (medicamento)
			{
				mensajeError = mensajeError + "medicamentos";
			}

			// Se convierte el string a char ya que los mensajes de excepcion solo reciben char
			const char* mensaje = mensajeError.c_str();

			throw exception(mensaje);
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

int metodoInterfaz::generarCodigo()
{
	try
	{
		random_device rd;										// Se crea el dispositivo que se utilizará para generar números aleatorios
		uniform_int_distribution<int> dist(10000, 99999);		// Se define tipo de dato y el rango de números
		return dist(rd);
	}
	catch (exception& e)
	{
		throw e;
	}
}

void metodoInterfaz::mostrarHoraCita(arboles<citas> _arbolCita, doctores* _doctor, string& _fecha, string& _hora)
{
	try
	{
		// Este metodo se usa para que el usuario ingrese una fecha e indicar la hora de la cita
		vector<string> horasDisponibles;
		vector<string> citasRealizadas;
		string espacios(120, ' ');
		string cuadroLado(20, ' ');
		string cuadroFinal(18, ' ');
		string cuadroBorde(76, '_');
		string cuadroRelleno(76, ' ');
		string cuadroIngresarTexto(50, ' ');
		string hora1;
		int horaInicio;
		int horaFinal;
		int horaTrabajo;
		int confirmacion;
		string horaCita;
		int key;
		int selector[] = { 71 };
		int opcion;

		while (1)
		{
			moverXY(0, 6);
			cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
			moverXY(25, 6);
			cout << "\033[100m" << "Ingresa la fecha de la cita:";
			moverXY(25, 7);
			cout << cuadroIngresarTexto;
			// Se le solicita la fecha de la cita
			_fecha = ingresarFecha();

			// Una vez con la fecha ingresada, se obtendrá de nodo del doctor seleccionado la horas de entrada y salida
			horaInicio = stoi(_doctor -> getHoraInicio().substr(0, 2));
			horaFinal = stoi(_doctor -> getHoraFin().substr(0, 2));

			// Se obtendrá las horas de trabajo del doctor
			horaTrabajo = horaFinal - horaInicio;

			// Se usuará un vector para obtener las horas en la que el doctor puede atender una cita
			for (int i = 0; i < horaTrabajo; i++)
			{
				hora1 = to_string(horaInicio + i);

				if (hora1.size() == 1)
				{
					hora1 = "0" + hora1 + ":00";
				}
				else
				{
					hora1 = hora1 + ":00";
				}

				horasDisponibles.push_back(hora1);
			}

			// Despues se usará el otro vector para obtener citas que hayan sido registradas con el doctor y la fecha que el usuario ingreso
			// Si hay algún nodo de cita que cumpla con los 2 requisitos se añadirá al vector
			_arbolCita.obtenerCita(citasRealizadas, _fecha, _doctor -> getCedula());

			while (!citasRealizadas.empty())
			{
				for (int i = 0; i < horasDisponibles.size(); i++)
				{
					if (citasRealizadas.empty())
					{
						// Pasa salir del ciclo for
						break;
					}

					// Se compará si hay una hora igual con el vector de horas disponibles con el de citas realizadas
					if (horasDisponibles[i] == citasRealizadas[0])
					{
						// Si se coincide, esa hora será borrada de ambos vectores
						horasDisponibles.erase(horasDisponibles.begin() + i);
						citasRealizadas.erase(citasRealizadas.begin());
					}
				}
			}

			// Ya cuando se hayan eliminado las horas de citas que ya están programadas se le mostrará al usuario las horas disponibles durante esa fecha
			moverXY(25, 6);
			cout << "\033[100m\033[30m" << cuadroIngresarTexto;
			moverXY(25, 6);
			cout << "Estas son las horas disponibles para la fecha: " << _fecha.substr(0, 2) << "/" << _fecha.substr(2, 2) << "/" << _fecha.substr(4, 4);
			moverXY(0, 7);
			
			for (int i = 0; i < horasDisponibles.size() + 3; i++)
			{
				cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
			}

			cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << "\033[44m\033[30m" << espacios;
			
			for (int i = 0; i < horasDisponibles.size(); i++)
			{
				moverXY(25, 7 + i);
				cout << "\033[100m" << horasDisponibles[i];
			}

			// Se le preguntará al usuario si desea programa la cita en la fecha indicada
			confirmacion = confirmarDatos("¿Deseas programar una cita en esta fecha?", 8 + horasDisponibles.size());

			moverXY(0, 6);

			for (int i = 0; i < 5; i++)
			{
				cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
			}
			cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;

			for (int i = 0; i < horasDisponibles.size(); i++)
			{
				cout << "\033[44m\033[30m" << espacios << endl;
			}

			// Si el usuario acepta, basado en el vector de horas disponibles, el usuario deberá de escojer una de las horas disponibles en esa fecha
			if (confirmacion == 1)
			{
				moverXY(25, 6);
				cout << "\033[100m" << "Selecciona la hora de la cita";
				moverXY(25, 7);
				opcion = 0;
				int tamaño = horasDisponibles.size() - 1;

				while (1)
				{
					moverXY(25, 7);
					color(selector[0]);
					cout << horasDisponibles[opcion];

					key = _getch();

					// Debido a que _getch manda 2 valores, se pondrá el primer valor al inicio
					if (key == 224)
					{
						key = _getch();

						// Se valida si el usuario pulsó la flecha hacia arriba
						if (key == 72)
						{
							opcion++;

							if (opcion > tamaño)
							{
								opcion = 0;
							}
						}
						// Se valida si el usuario pulsó la flecha hacia abajo
						else if (key == 80)
						{
							opcion--;

							if (opcion == -1)
							{
								opcion = tamaño;
							}
						}
					}
					else if (key == '\r')
					{
						break;
					}
				}

				// Pasa salir del while del la fecha ya que la fecha y hora fueron seleccionadas
				break;
			}
		}
		// Se igualará la hora selecciona para ser retornado
		_hora = horasDisponibles[opcion];

		horasDisponibles.clear();
		citasRealizadas.clear();
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool metodoInterfaz::verificarCantidadMedicamento(int _inventario, int _cantidad)
{
	try
	{
		// Se verificará si la cantidad solicitada por el usuario para la receta medica es menor
		// que la cantidad que existe en inventario
		int resultado = _inventario - _cantidad;

		if (resultado < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

int metodoInterfaz::seleccionarArbol(string _opcion, int _posicion)
{
	// Usando el sistema de interface, se le preguntará al usuario que arbol quiere seleccionar para la obtención de datos
	int key;
	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');
	int opcion = 1;
	int selector[] = { 71, 128, 128, 128, 128, 128 };

	system("cls");

	cout << "\033[44m\033[30m" << espacios << endl;
	cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
	}

	cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << "\033[44m\033[30m" << espacios;

	moverXY(_posicion, 4);
	cout << "\033[100m\033[30m" << _opcion;

	moverXY(25, 6);
	cout << "Selecciona un arbol:";

	while (1)
	{
		moverXY(25, 7);
		color(selector[0]);
		cout << "Arbol Doctores       ";

		moverXY(25, 8);
		color(selector[1]);
		cout << "Arbol Pacientes      ";

		moverXY(25, 9);
		color(selector[2]);
		cout << "Arbol Medicamentos   ";

		moverXY(25, 10);
		color(selector[3]);
		cout << "Arbol Citas          ";

		moverXY(25, 11);
		color(selector[4]);
		cout << "Arbol Facturas       ";

		moverXY(25, 12);
		color(selector[5]);
		cout << "Arbol Recetas Medicas";

		key = _getch();

		if (key == 72)		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
		{
			opcion--;

			if (opcion == 0)
			{
				opcion = 6;
			}
		}
		else if (key == 80)	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
		{
			opcion++;

			if (opcion == 7)
			{
				opcion = 1;
			}
		}
		else if (key == '\r')
		{
			break;
		}

		selector[0] = 128;
		selector[1] = 128;
		selector[2] = 128;
		selector[3] = 128;
		selector[4] = 128;
		selector[5] = 128;

		switch (opcion)
		{
		case 1:
			selector[0] = 71;
			break;

		case 2:
			selector[1] = 71;
			break;

		case 3:
			selector[2] = 71;
			break;

		case 4:
			selector[3] = 71;
			break;

		case 5:
			selector[4] = 71;
			break;

		case 6:
			selector[5] = 71;
			break;
		}
	}

	cout << "\033[44m\033[30m";

	return opcion;
}
