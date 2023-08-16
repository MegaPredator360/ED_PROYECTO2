#include "interfaz.h"

void interfaz::menuPrincipal()
{
	// Opción seleccionada
	opcion = 1;				
	// Se coloca a todas las opciones con el color por defecto
	int Set[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
	// Se marcará la primera opción como seleccionada
	Set[0] = 71;
	// Encargada de recibir el valor de la tecla pulsada en ASCII
	int key = 0;

	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');
	string cuadroIngresarTexto(50, ' ');

	// Cargar Archivos
	arbolDoctor = _archivo.cargarDoctor();
	arbolPaciente = _archivo.cargarPaciente();
	arbolMedicamento = _archivo.cargarMedicamento();
	arbolCita = _archivo.cargarCita(arbolDoctor, arbolPaciente);
	arbolRecetaMedica = _archivo.cargarReceta(arbolPaciente, arbolMedicamento, arbolDoctor);

	while (1)
	{
		system("cls");

		// Se genera el cuadro del menú principal
		cout << "\033[44m\033[30m" << espacios << endl;
		cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

		for (int i = 0; i < 20; i++)
		{
			cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
		}

		cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
		cout << "\033[44m\033[30m" << espacios << espacios << espacios << espacios << espacios;

		_mInterfaz.moverXY(53, 4);
		cout << "\033[100mMenú Principal";

		for (int i = 0;;)
		{
			// Opcion 1
			// Indica donde se va a posicionar el cursor en la consola
			_mInterfaz.moverXY(44, 6);
			// Inidicará el color a ingresar marcar si la opcion es seleccionada
			_mInterfaz.color(Set[0]);
			// Texto de la opción
			cout << "         Ingresar Doctor         ";

			// Opcion 2
			_mInterfaz.moverXY(44, 7);
			_mInterfaz.color(Set[1]);
			cout << "        Ingresar Paciente        ";

			// Opcion 3
			_mInterfaz.moverXY(44, 8);
			_mInterfaz.color(Set[2]);
			cout << "      Ingresar Medicamentos      ";

			// Opcion 4
			_mInterfaz.moverXY(44, 9);
			_mInterfaz.color(Set[3]);
			cout << "          Registrar Cita         ";

			// Opcion 4
			_mInterfaz.moverXY(44, 10);
			_mInterfaz.color(Set[4]);
			cout << "           Atender Cita          ";

			// Opcion 5
			_mInterfaz.moverXY(44, 11);
			_mInterfaz.color(Set[5]);
			cout << "          Modificar Cita         ";

			// Opcion 6
			_mInterfaz.moverXY(44, 12);
			_mInterfaz.color(Set[6]);
			cout << "          Cancelar Cita          ";

			// Opcion 7
			_mInterfaz.moverXY(44, 13);
			_mInterfaz.color(Set[7]);
			cout << "     Consultar Receta Medica     ";

			// Opcion 8
			_mInterfaz.moverXY(44, 14);
			_mInterfaz.color(Set[8]);
			cout << "          Mostrar Arbol          ";

			// Opcion 9
			_mInterfaz.moverXY(44, 15);
			_mInterfaz.color(Set[9]);
			cout << "        Recorrido Profundo       ";

			// Opcion 10
			_mInterfaz.moverXY(44, 16);
			_mInterfaz.color(Set[10]);
			cout << "      Recorrido por niveles      ";

			// Opcion 11
			_mInterfaz.moverXY(44, 17);
			_mInterfaz.color(Set[11]);
			cout << "         Altura del arbol        ";

			// Opcion 12
			_mInterfaz.moverXY(44, 18);
			_mInterfaz.color(Set[12]);
			cout << "           Contar Nodos          ";

			// Opcion 13
			_mInterfaz.moverXY(44, 19);
			_mInterfaz.color(Set[13]);
			cout << "           Contar Hojas          ";

			// Opcion 14
			_mInterfaz.moverXY(44, 20);
			_mInterfaz.color(Set[14]);
			cout << "              Salir              ";

			key = _getch();

			if (key == 72)		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				opcion--;

				if (opcion == 0)
				{
					opcion = 15;
				}
			}
			else if (key == 80)	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				opcion++;

				if (opcion == 16)
				{
					opcion = 1;
				}
			}
			// Identifica si la tecla ENTER fue pulsada
			else if (key == '\r')
			{

				cout << "\033[44m\033[30m";

				switch (opcion)
				{
				case 1:
					// Ingresar Doctores
					try
					{
						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mIngresar Doctor";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de cedula del doctor: (9 digitos, incluir los 0)";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cedula = _mInterfaz.ingresarNumeros();

							while (cedula.length() != 9 || cedula.at(1) != '0' || cedula.at(5) != '0' || arbolDoctor.verificarDatos(cedula))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLo ingresado no coincide con el formato solicitado o ya existe.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de cedula.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								cedula = _mInterfaz.ingresarNumeros();
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el nombre completo del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, nombre);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Selecciona la especialidad del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;

							int oEspecialidad[] = { 128, 128, 128, 128 };
							int nEspecialidad = 1;
							oEspecialidad[0] = { 71 };

							while (1)
							{
								_mInterfaz.moverXY(25, 7);
								_mInterfaz.color(oEspecialidad[0]);
								cout << "Cardiólogo ";

								_mInterfaz.moverXY(25, 8);
								_mInterfaz.color(oEspecialidad[1]);
								cout << "Pediatra   ";

								_mInterfaz.moverXY(25, 9);
								_mInterfaz.color(oEspecialidad[2]);
								cout << "Ginecólogo ";

								_mInterfaz.moverXY(25, 10);
								_mInterfaz.color(oEspecialidad[3]);
								cout << "Dermatólogo";

								key = _getch();

								if (key == 72 && (nEspecialidad >= 1 && nEspecialidad <= 4))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
								{
									nEspecialidad--;

									if (nEspecialidad == 0)
									{
										nEspecialidad = 4;
									}
								}
								else if (key == 80 && (nEspecialidad >= 1 && nEspecialidad <= 4))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
								{
									nEspecialidad++;

									if (nEspecialidad == 5)
									{
										nEspecialidad = 1;
									}
								}
								else if (key == '\r')
								{
									break;
								}

								oEspecialidad[0] = 128;
								oEspecialidad[1] = 128;
								oEspecialidad[2] = 128;
								oEspecialidad[3] = 128;

								switch (nEspecialidad)
								{
								case 1:
									oEspecialidad[0] = 71;
									break;

								case 2:
									oEspecialidad[1] = 71;
									break;

								case 3:
									oEspecialidad[2] = 71;
									break;

								case 4:
									oEspecialidad[3] = 71;
									break;
								}
							}

							switch (nEspecialidad)
							{
							case 1:
								especialidad = "Cardiólogo";
								break;

							case 2:
								especialidad = "Pediatra";
								break;

							case 3:
								especialidad = "Ginecólogo";
								break;

							case 4:
								especialidad = "Dermatólogo";
								break;
							}

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la dirección del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, direccion);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la hora de entrada del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(27, 7);
							cout << ":";
							horaInicio = _mInterfaz.ingresarHora();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la hora de salida del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							horaFinal = _mInterfaz.ingresarHora();

							if (stoi(horaFinal.substr(0, 2)) < stoi(horaInicio.substr(0, 2)))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "La hora de salida es menor que la hora de entrada. Hora de entrada: " << horaInicio;
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa una hora de salida mayor a la hora de entrada.";
								horaFinal = _mInterfaz.ingresarHora();
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de telefono del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							telefono = _mInterfaz.ingresarNumeros();

							while (telefono.length() != 8)
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLo ingresado no coincide con el formato solicitado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de telefono.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								telefono = _mInterfaz.ingresarNumeros();
							}

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 24; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Número de cedula:";
							_mInterfaz.moverXY(25, 4);
							cout << cedula;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre Completo:";
							_mInterfaz.moverXY(25, 7);
							cout << nombre;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Tipo de Especialidad:";
							_mInterfaz.moverXY(25, 10);
							cout << especialidad;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Dirección:";
							_mInterfaz.moverXY(25, 13);
							cout << direccion;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de Entrada:";
							_mInterfaz.moverXY(25, 16);
							cout << horaInicio;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 18);
							cout << "Hora de Salida:";
							_mInterfaz.moverXY(25, 19);
							cout << horaFinal;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 21);
							cout << "Telefono:";
							_mInterfaz.moverXY(25, 22);
							cout << telefono;

							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 24) == 1)
							{
								_doctor = new doctores(cedula, nombre, especialidad, direccion, horaInicio, horaFinal, telefono);
								arbolDoctor.registrarDatos(_doctor, cedula);
								_archivo.guardarDoctor(arbolDoctor);
								_mInterfaz.mostrarMensajeExito("¡El doctor fue ingresado con exito!");

								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 2:
					// Ingresar Paciente
					try
					{
						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mIngresar Paciente";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de cedula del paciente: (9 digitos, incluir los 0)";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cedula = _mInterfaz.ingresarNumeros();

							while (cedula.length() != 9 || cedula.at(1) != '0' || cedula.at(5) != '0' || arbolPaciente.verificarDatos(cedula))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLo ingresado no coincide con el formato solicitado o ya existe.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de cedula.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								cedula = _mInterfaz.ingresarNumeros();
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el nombre completo del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, nombre);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la dirección del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, direccion);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de telefono del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							telefono = _mInterfaz.ingresarNumeros();

							while (telefono.length() != 8)
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLo ingresado no coincide con el formato solicitado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de telefono.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								telefono = _mInterfaz.ingresarNumeros();
							}

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 15; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Número de cedula:";
							_mInterfaz.moverXY(25, 4);
							cout << cedula;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre Completo:";
							_mInterfaz.moverXY(25, 7);
							cout << nombre;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Dirección:";
							_mInterfaz.moverXY(25, 10);
							cout << direccion;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Telefono:";
							_mInterfaz.moverXY(25, 13);
							cout << telefono;

							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 15) == 1)
							{
								_paciente = new pacientes(cedula, nombre, direccion, telefono);
								arbolPaciente.registrarDatos(_paciente, cedula);
								_archivo.guardarPaciente(arbolPaciente);
								_mInterfaz.mostrarMensajeExito("¡El paciente fue ingresado con exito!");

								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 3:
					// Ingresar Medicamento
					try
					{
						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mIngresar Medicamento";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el codigo del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							codigo = _mInterfaz.ingresarNumeros();

							while (arbolMedicamento.verificarDatos(codigo))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mEl codigo ingresado ya está registrado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa otro codigo de medicamento.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								codigo = _mInterfaz.ingresarNumeros();
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el nombre del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, nombre);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la cantidad en inventario del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cantidad = stoi(_mInterfaz.ingresarNumeros());

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 12; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo del medicamento:";
							_mInterfaz.moverXY(25, 4);
							cout << codigo;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << nombre;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Cantidad en inventario del medicamento:";
							_mInterfaz.moverXY(25, 10);
							cout << cantidad;

							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 12) == 1)
							{
								_medicamento = new medicamentos(codigo, nombre, cantidad);
								arbolMedicamento.registrarDatos(_medicamento, codigo);
								_archivo.guardarMedicamento(arbolMedicamento);
								_mInterfaz.mostrarMensajeExito("¡El medicamento fue ingresado con exito!");

								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 4:
					// Registrar Cita
					try
					{
						// Se verificará si hay doctores, pacientes y medicamentos registrados en el sistema
						_mInterfaz.verificarVacio(arbolDoctor, arbolPaciente, arbolMedicamento);

						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mRegistrar Cita";

							// Se genera un número
							codigo = to_string(_mInterfaz.generarCodigo());

							// Si el codigo ya existe, se generará otro hasta que no esté repetido
							while (arbolCita.verificarDatos(codigo))
							{
								codigo = to_string(_mInterfaz.generarCodigo());
							}

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el número de cedula del paciente registrado:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cedula = _mInterfaz.ingresarNumeros();
							
							while (!arbolPaciente.verificarDatos(cedula))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLa cedula ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa un número de cedula registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								cedula = _mInterfaz.ingresarNumeros();
							}
							
							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa la cedula del doctor registrado:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, nombre);

							while (!arbolDoctor.verificarDatos(nombre))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mLa cedula ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa un número de cedula registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								nombre = _mInterfaz.ingresarNumeros();
							}

							_doctor = arbolDoctor.obtenerDatos(nombre);

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;

							_mInterfaz.mostrarHoraCita(arbolCita, _doctor, fecha, hora);

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 18; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_paciente = arbolPaciente.obtenerDatos(cedula);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la cita:";
							_mInterfaz.moverXY(25, 4);
							cout << codigo;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << _paciente -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << _doctor -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << fecha.substr(0, 2) << " - Mes: " << fecha.substr(2, 2) << " - Año: " << fecha.substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << hora;

							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 18) == 1)
							{
								_cita = new citas(codigo, fecha, hora, _doctor, _paciente);
								arbolCita.registrarDatos(_cita, codigo);
								_archivo.guardarCita(arbolCita);
								_mInterfaz.mostrarMensajeExito("¡La cita fue registrada con exito!");

								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 5:
					// Atender Cita
					try
					{
						if (!arbolCita.verificarVacio())
						{
							throw exception("!No hay citas registradas en el sistema!");
						}

						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mAtender Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							codigo = _mInterfaz.ingresarNumeros();

							while (!arbolCita.verificarDatos(codigo))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mEl codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								codigo = _mInterfaz.ingresarNumeros();
							}

							_cita = arbolCita.obtenerDatos(codigo);

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 18; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la cita:";
							_mInterfaz.moverXY(25, 4);
							cout << _cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << _cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << _cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << _cita -> getFecha().substr(0, 2) << " - Mes: " << _cita -> getFecha().substr(2, 2) << " - Año: " << _cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << _cita -> getHora();

							if (_mInterfaz.confirmarDatos("¿Deseas atender esta cita?", 18) == 1)
							{
								while (1)
								{
									system("cls");
									cout << "\033[44m\033[30m" << espacios << endl;
									cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

									for (int i = 0; i < 9; i++)
									{
										cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									}

									cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << espacios;

									_mInterfaz.moverXY(52, 4);
									cout << "\033[100mAtender Cita";

									especialidad = to_string(_mInterfaz.generarCodigo());

									while (arbolRecetaMedica.verificarDatos(especialidad))
									{
										especialidad = _mInterfaz.generarCodigo();
									}

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa el diagnostico del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									getline(cin, nombre);

									_mInterfaz.moverXY(0, 6);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa el codigo del medicamento a recetar:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									codigo = _mInterfaz.ingresarNumeros();

									while (!arbolMedicamento.verificarDatos(codigo))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31mEl codigo ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa el codigo de medicamento registrado.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										codigo = _mInterfaz.ingresarNumeros();
									}

									_medicamento = arbolMedicamento.obtenerDatos(codigo);

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa la cantidad de medicamentos a recetar:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									paciente = _mInterfaz.ingresarNumeros();

									while (!_mInterfaz.verificarCantidadMedicamento(_medicamento -> getCantidadInventario(), stoi(paciente)))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31mNo hay suficiente cantidad en inventario de ese medicamento.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa una cantidad igual a " << _medicamento->getCantidadInventario() << " o menor.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										paciente = _mInterfaz.ingresarNumeros();
									}

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa la dosis en la que el paciente debe tomar el medicamento:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									getline(cin, doctor);

									cout << "\033[44m\033[30m";

									system("cls");
									cout << espacios << endl;
									cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

									for (int i = 0; i < 18; i++)
									{
										cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									}

									cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << espacios;

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 3);
									cout << "Codigo de la receta medica:";
									_mInterfaz.moverXY(25, 4);
									cout << especialidad;

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 6);
									cout << "Nombre del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << _cita->getPaciente() -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 9);
									cout << "Diagnostico del paciente:";
									_mInterfaz.moverXY(25, 10);
									cout << nombre;

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 12);
									cout << "Nombre del medicamento:";
									_mInterfaz.moverXY(25, 13);
									cout << _medicamento->getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Cantidad de medicamentos:";
									_mInterfaz.moverXY(25, 16);
									cout << paciente;

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Dosis del medicamento:";
									_mInterfaz.moverXY(25, 16);
									cout << doctor;

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Doctor encargado:";
									_mInterfaz.moverXY(25, 16);
									cout << _cita -> getDoctor() -> getNombre();

									if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 18) == 1)
									{
										// Se crea un dato de receta medica
										_recetaMedica = new recetaMedica(especialidad, _cita -> getPaciente(), nombre, _medicamento, stoi(paciente), doctor, _cita -> getDoctor());
										arbolRecetaMedica.registrarDatos(_recetaMedica, especialidad);
										_archivo.guardarRecetaMedica(arbolRecetaMedica);

										// Se actualiza la cantidad en inventario del medicamento
										_medicamento -> setCantidadInventario(_medicamento -> getCantidadInventario() - stoi(paciente));
										_archivo.guardarMedicamento(arbolMedicamento);

										// Se elimina la cita del sistema
										arbolCita.eliminarDatos(_cita, _cita -> getCodigo());
										_archivo.guardarCita(arbolCita);

										_mInterfaz.mostrarMensajeExito("¡La cita fue atendida con exito!");

										break;
									}
								}

								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;


				case 6:
					// Modificar Cita
					try
					{
						if (!arbolCita.verificarVacio())
						{
							throw exception("!No hay citas registradas en el sistema!");
						}

						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mModificar Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							codigo = _mInterfaz.ingresarNumeros();

							while (!arbolCita.verificarDatos(codigo))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mEl codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								codigo = _mInterfaz.ingresarNumeros();
							}

							_cita = arbolCita.obtenerDatos(codigo);

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 18; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la cita:";
							_mInterfaz.moverXY(25, 4);
							cout << _cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << _cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << _cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << _cita -> getFecha().substr(0, 2) << " - Mes: " << _cita -> getFecha().substr(2, 2) << " - Año: " << _cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << _cita -> getHora();

							if (_mInterfaz.confirmarDatos("¿Deseas modificar esta cita?", 18) == 1)
							{
								while (1)
								{
									system("cls");
									cout << "\033[44m\033[30m" << espacios << endl;
									cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

									for (int i = 0; i < 9; i++)
									{
										cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									}

									cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << espacios;

									_mInterfaz.moverXY(52, 4);
									cout << "\033[100mModificar Cita";

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa el número de cedula del paciente registrado:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									cedula = _mInterfaz.ingresarNumeros();

									while (!arbolPaciente.verificarDatos(cedula))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31mLa cedula ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa un número de cedula registrada.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										cedula = _mInterfaz.ingresarNumeros();
									}

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100mIngresa la cedula del doctor registrado:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									getline(cin, nombre);

									while (!arbolDoctor.verificarDatos(nombre))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31mLa cedula ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa un número de cedula registrada.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										nombre = _mInterfaz.ingresarNumeros();
									}

									_doctor = arbolDoctor.obtenerDatos(nombre);

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;

									_mInterfaz.mostrarHoraCita(arbolCita, _doctor, fecha, hora);

									cout << "\033[44m\033[30m";

									system("cls");
									cout << espacios << endl;
									cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

									for (int i = 0; i < 18; i++)
									{
										cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									}

									cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << espacios;

									_paciente = arbolPaciente.obtenerDatos(cedula);

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 3);
									cout << "Codigo de la cita:";
									_mInterfaz.moverXY(25, 4);
									cout << _cita -> getCodigo();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 6);
									cout << "Nombre del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << _paciente -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 9);
									cout << "Nombre del doctor:";
									_mInterfaz.moverXY(25, 10);
									cout << _doctor -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 12);
									cout << "Fecha de la cita:";
									_mInterfaz.moverXY(25, 13);
									cout << "Dia: " << fecha.substr(0, 2) << " - Mes: " << fecha.substr(2, 2) << " - Año: " << fecha.substr(4, 4);

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Hora de la cita:";
									_mInterfaz.moverXY(25, 16);
									cout << hora;

									if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 18) == 1)
									{
										_cita -> setFecha(fecha);
										_cita -> setHora(hora);
										_cita -> setDoctor(_doctor);
										_cita -> setPaciente(_paciente);

										_archivo.guardarCita(arbolCita);
										_mInterfaz.mostrarMensajeExito("¡La cita fue actualizada con exito!");

										break;
									}
								}

								// Salir del ciclo de Modificar Citas
								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 7:
					// Eliminar Cita
					try
					{
						if (!arbolCita.verificarVacio())
						{
							throw exception("!No hay citas registradas en el sistema!");
						}

						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(52, 4);
							cout << "\033[100mCancelar Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							codigo = _mInterfaz.ingresarNumeros();

							while (!arbolCita.verificarDatos(codigo))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mEl codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								codigo = _mInterfaz.ingresarNumeros();
							}

							_cita = arbolCita.obtenerDatos(codigo);

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 18; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la cita:";
							_mInterfaz.moverXY(25, 4);
							cout << _cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << _cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << _cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << _cita -> getFecha().substr(0, 2) << " - Mes: " << _cita -> getFecha().substr(2, 2) << " - Año: " << _cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << _cita -> getHora();

							if (_mInterfaz.confirmarDatos("¿Deseas cancelar esta cita?", 18) == 1)
							{
								arbolCita.eliminarDatos(_cita, _cita -> getCodigo());
								_archivo.guardarCita(arbolCita);
								_mInterfaz.mostrarMensajeExito("¡La cita fue cancelada con exito!");
								break;
							}
						}
					}
					catch (exception& e)
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 8:
					// Consultar Receta Medica
					try
					{
						if (!arbolRecetaMedica.verificarVacio())
						{
							throw exception("!No hay recetas medicas registradas en el sistema!");
						}

						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 9; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(50, 4);
							cout << "\033[100mConsultar receta medica";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mIngresa el codigo de la receta medica registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							codigo = _mInterfaz.ingresarNumeros();

							while (!arbolRecetaMedica.verificarDatos(codigo))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31mEl codigo ingresado no está registrado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de la receta medica registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								codigo = _mInterfaz.ingresarNumeros();
							}

							_recetaMedica = arbolRecetaMedica.obtenerDatos(codigo);

							cout << "\033[44m\033[30m";

							system("cls");
							cout << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

							for (int i = 0; i < 18; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}

							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la receta medica:";
							_mInterfaz.moverXY(25, 4);
							cout << _recetaMedica -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << _recetaMedica -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Diagnostico del paciente:";
							_mInterfaz.moverXY(25, 10);
							cout << _recetaMedica -> getDiagnostico();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Nombre del medicamento:";
							_mInterfaz.moverXY(25, 13);
							cout << _recetaMedica -> getMedicamento() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Cantidad de medicamentos:";
							_mInterfaz.moverXY(25, 16);
							cout << _recetaMedica -> getCantidad();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Dosis del medicamento:";
							_mInterfaz.moverXY(25, 16);
							cout << _recetaMedica -> getDosis();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Doctor encargado:";
							_mInterfaz.moverXY(25, 16);
							cout << _recetaMedica -> getDoctor() -> getNombre();

							if (_mInterfaz.confirmarDatos("¿Deseas consultar otra receta medica?", 18) == 0)
							{
								break;
							}
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 9:
					// Mostrar Arbol
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolDoctor.mostrarArbol(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 2:
							// Arbol Pacientes
							if (!arbolPaciente.verificarVacio())
							{
								throw exception("No hay pacientes registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolPaciente.mostrarArbol(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolMedicamento.verificarVacio())
							{
								throw exception("No hay medicamentos registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolMedicamento.mostrarArbol(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 4:
							// Arbol Citas
							if (!arbolCita.verificarVacio())
							{
								throw exception("No hay cita registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolCita.mostrarArbol(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolRecetaMedica.mostrarArbol(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de receta medica:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 10:
					// Recorrido Profundo
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolDoctor.recorridoProfundidad(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 2:
							// Arbol Pacientes
							if (!arbolPaciente.verificarVacio())
							{
								throw exception("No hay pacientes registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolPaciente.recorridoProfundidad(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolMedicamento.verificarVacio())
							{
								throw exception("No hay medicamentos registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolMedicamento.recorridoProfundidad(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 4:
							// Arbol Citas
							if (!arbolCita.verificarVacio())
							{
								throw exception("No hay cita registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolCita.recorridoProfundidad(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolRecetaMedica.recorridoProfundidad(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de receta medica:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 11:
					// Recorrido por Niveles
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolDoctor.recorridoPorNiveles(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 2:
							// Arbol Pacientes
							if (!arbolPaciente.verificarVacio())
							{
								throw exception("No hay pacientes registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolPaciente.recorridoPorNiveles(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolMedicamento.verificarVacio())
							{
								throw exception("No hay medicamentos registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolMedicamento.recorridoPorNiveles(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 4:
							// Arbol Citas
							if (!arbolCita.verificarVacio())
							{
								throw exception("No hay cita registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolCita.recorridoPorNiveles(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolRecetaMedica.recorridoPorNiveles(listaCodigos);
							cantidad = listaCodigos.size();

							_mInterfaz.moverXY(0, 6);
							for (int i = 0; i < cantidad + 3; i++)
							{
								cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios;

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100mMostrando arbol de receta medica:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";
							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 12:
					// Altura del arbol
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							cantidad = arbolDoctor.alturaArbol();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "La altura de el arbol de doctores es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";

							break;

						case 2:
							// Arbol Pacientes
							if (!arbolPaciente.verificarVacio())
							{
								throw exception("No hay pacientes registrados en el sistema.");
							}

							cantidad = arbolPaciente.alturaArbol();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "La altura de el arbol de pacientes es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";

							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolMedicamento.verificarVacio())
							{
								throw exception("No hay medicamentos registrados en el sistema.");
							}

							cantidad = arbolMedicamento.alturaArbol();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "La altura de el arbol de medicamentos es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";

							break;

						case 4:
							// Arbol Citas
							if (!arbolCita.verificarVacio())
							{
								throw exception("No hay citas registrados en el sistema.");
							}

							cantidad = arbolCita.alturaArbol();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "La altura de el arbol de citas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";

							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							cantidad = arbolRecetaMedica.alturaArbol();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 6);
							cout << "La altura de el arbol de recetas medicas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37mContinuar";

							while (1)
							{
								key = _getch();

								if (key == '\r')
								{
									break;
								}
							}
							cout << "\033[44m\033[30m";

							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 13:
					// Contar Nodos
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							

							break;

						case 2:
							// Arbol Pacientes
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 4:
							// Arbol Citas
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 14:
					// Contar Hojas
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 2:
							// Arbol Pacientes
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 3:
							// Arbol Medicamentos
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 4:
							// Arbol Citas
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;

						case 5:
							// Arbol Recetas Medicas
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							break;
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				case 15:
					// Salir
					try
					{
						system("cls");
						cout << "\033[44m\033[30m" << espacios << endl;
						cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

						for (int i = 0; i < 9; i++)
						{
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
						}

						cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
						cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
						cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
						cout << "\033[44m\033[30m" << espacios;

						_mInterfaz.moverXY(55, 4);
						cout << "\033[100mSalir";

						if (_mInterfaz.confirmarDatos("¿Deseas salir del programa?", 6) == 1)
						{
							cout << "\033[40m\033[37m";
							system("cls");

							cout << endl << endl;
							cout << "" << endl << endl;
							exit(0);
						}
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;

				default:
					// Opcion por defecto
					try
					{
						throw exception("Ocurrio un error al seleccionar una opción");
					}
					catch (exception& e) 
					{
						_mInterfaz.mostrarMensajeFallido(e.what());
					}
					break;
				}

				// Para salir del ciclo for
				break;
			}

			// Color por defecto de todas las opciones
			Set[0] = 128;
			Set[1] = 128;
			Set[2] = 128;
			Set[3] = 128;
			Set[4] = 128;
			Set[5] = 128;
			Set[6] = 128;
			Set[7] = 128;
			Set[8] = 128;
			Set[9] = 128;
			Set[10] = 128;
			Set[11] = 128;
			Set[12] = 128;
			Set[13] = 128;
			Set[14] = 128;

			// Cambiar color basado en la opcion seleccionada
			switch (opcion)
			{
			case 1:
				// Se indica el codigo de color con el que se usará en el texto
				// si la opción esta seleccionada
				Set[0] = 71;
				break;

			case 2:
				Set[1] = 71;
				break;

			case 3:
				Set[2] = 71;
				break;

			case 4:
				Set[3] = 71;
				break;

			case 5:
				Set[4] = 71;
				break;

			case 6:
				Set[5] = 71;
				break;

			case 7:
				Set[6] = 71;
				break;

			case 8:
				Set[7] = 71;
				break;

			case 9:
				Set[8] = 71;
				break;

			case 10:
				Set[9] = 71;
				break;

			case 11:
				Set[10] = 71;
				break;

			case 12:
				Set[11] = 71;
				break;

			case 13:
				Set[12] = 71;
				break;

			case 14:
				Set[13] = 71;
				break;

			case 15:
				Set[14] = 71;
				break;
			}
		}
	}
}
