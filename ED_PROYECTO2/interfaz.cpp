#include "interfaz.h"

void interfaz::menuPrincipal()
{
	// Opción seleccionada
	opcion = 1;				
	// Se coloca a todas las opciones con el color por defecto
	int Set[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
	// Se marcará la primera opción como seleccionada
	Set[0] = 71;
	// Encargada de recibir el valor de la tecla pulsada en ASCII
	int key = 0;

	
	int oConfirmacion[] = { 128, 128 };

	while (1)
	{
		system("cls");

		string espacios(120, ' ');
		string cuadroLado(20, ' ');
		string cuadroFinal(18, ' ');
		string cuadroBorde(76, '_');
		string cuadroRelleno(76, ' ');
		string cuadroIngresarTexto(50, ' ');


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

			// Opcion 5
			_mInterfaz.moverXY(44, 10);
			_mInterfaz.color(Set[4]);
			cout << "          Modificar Cita         ";

			// Opcion 6
			_mInterfaz.moverXY(44, 11);
			_mInterfaz.color(Set[5]);
			cout << "          Eliminar Cita          ";

			// Opcion 7
			_mInterfaz.moverXY(44, 12);
			_mInterfaz.color(Set[6]);
			cout << "     Consultar Receta Medica     ";

			// Opcion 8
			_mInterfaz.moverXY(44, 13);
			_mInterfaz.color(Set[7]);
			cout << "          Mostrar Arbol          ";

			// Opcion 9
			_mInterfaz.moverXY(44, 14);
			_mInterfaz.color(Set[8]);
			cout << "        Recorrido Profundo       ";

			// Opcion 10
			_mInterfaz.moverXY(44, 15);
			_mInterfaz.color(Set[9]);
			cout << "      Recorrido por niveles      ";

			// Opcion 11
			_mInterfaz.moverXY(44, 16);
			_mInterfaz.color(Set[10]);
			cout << "         Altura del arbol        ";

			// Opcion 12
			_mInterfaz.moverXY(44, 17);
			_mInterfaz.color(Set[11]);
			cout << "           Contar Nodos          ";

			// Opcion 13
			_mInterfaz.moverXY(44, 18);
			_mInterfaz.color(Set[12]);
			cout << "           Contar Hojas          ";

			// Opcion 14
			_mInterfaz.moverXY(44, 19);
			_mInterfaz.color(Set[13]);
			cout << "              Salir              ";

			key = _getch();

			if (key == 72 && (opcion >= 1 && opcion <= 14))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				opcion--;

				if (opcion == 0)
				{
					opcion = 14;
				}
			}
			else if (key == 80 && (opcion >= 1 && opcion <= 14))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				opcion++;

				if (opcion == 15)
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
								cout << "\033[100m\033[31mEl cedula ingresada no está registrada.";
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
								cout << "\033[100m\033[31mEl cedula ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa un número de cedula registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								nombre = _mInterfaz.ingresarNumeros();
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la fecha de la cita:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							fecha = _mInterfaz.ingresarFecha();

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la hora de la cita:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							hora = _mInterfaz.ingresarHora();

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
							cout << codigo;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Cedula del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << cedula;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Cedula del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << nombre;

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
								_medicamento = new medicamentos(codigo, nombre, cantidad);
								arbolMedicamento.registrarDatos(_medicamento, codigo);
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

				case 5:
					// Modificar Cita
					try
					{

					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 6:
					// Eliminar Cita
					try
					{

					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 7:
					// Consultar Receta Medica
					try
					{

					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 8:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 9:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 10:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 11:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 12:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 13:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 14:
					// Mostrar Arbol
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				default:
					// Opcion por defecto
					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
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
			}
		}
	}
}
