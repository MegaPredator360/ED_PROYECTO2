#include "interfaz.h"

void interfaz::menuPrincipal()
{
	// Opción seleccionada
	opcion = 1;				
	// Se coloca a todas las opciones con el color por defecto
	int Set[] = { 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
	// Se marcará la primera opción como seleccionada
	Set[0] = 71;
	// Encargada de recibir el valor de la tecla pulsada en ASCII
	int key = 0;

	// Series de string usados para el diseño de la interface
	// Repetirá un caracter X cantidad de veces cada vez que se llame
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
	arbolFactura = _archivo.cargarFactura(arbolPaciente);
	arbolRecetaMedica = _archivo.cargarReceta(arbolPaciente, arbolMedicamento, arbolDoctor);

	while (1)
	{
		system("cls");

		// Se genera el cuadro del menú principal
		cout << "\033[44m\033[30m" << espacios << endl;
		cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

		for (int i = 0; i < 21; i++)
		{
			cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
		}

		cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
		cout << "\033[44m\033[30m" << espacios << endl << espacios << endl << espacios << endl << espacios;

		_mInterfaz.moverXY(53, 4);
		cout << "\033[100m" << "Menú Principal";

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
			cout << "        Consultar Factura        ";

			// Opcion 7
			_mInterfaz.moverXY(44, 14);
			_mInterfaz.color(Set[8]);
			cout << "     Consultar Receta Medica     ";

			// Opcion 8
			_mInterfaz.moverXY(44, 15);
			_mInterfaz.color(Set[9]);
			cout << "          Mostrar Arbol          ";

			// Opcion 9
			_mInterfaz.moverXY(44, 16);
			_mInterfaz.color(Set[10]);
			cout << "        Recorrido Profundo       ";

			// Opcion 10
			_mInterfaz.moverXY(44, 17);
			_mInterfaz.color(Set[11]);
			cout << "      Recorrido por niveles      ";

			// Opcion 11
			_mInterfaz.moverXY(44, 18);
			_mInterfaz.color(Set[12]);
			cout << "         Altura del arbol        ";

			// Opcion 12
			_mInterfaz.moverXY(44, 19);
			_mInterfaz.color(Set[13]);
			cout << "           Contar Nodos          ";

			// Opcion 13
			_mInterfaz.moverXY(44, 20);
			_mInterfaz.color(Set[14]);
			cout << "           Contar Hojas          ";

			// Opcion 14
			_mInterfaz.moverXY(44, 21);
			_mInterfaz.color(Set[15]);
			cout << "              Salir              ";

			key = _getch();

			if (key == 72)		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				opcion--;

				if (opcion == 0)
				{
					opcion = 16;
				}
			}
			else if (key == 80)	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				opcion++;

				if (opcion == 17)
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
							cout << "\033[100m" << "Ingresar Doctor";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de cedula del doctor: (9 digitos)";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_doctor.setCedula(_mInterfaz.ingresarNumeros());

							// Si la cedula no contiene 9 digitos o ya existe, entrará en el ciclo while
							while (_doctor.getCedula().length() != 9 || arbolDoctor.verificarDatos(_doctor.getCedula()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "Lo ingresado no coincide con el formato solicitado o ya existe.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de cedula.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_doctor.setCedula(_mInterfaz.ingresarNumeros());
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el nombre completo del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, dato);
							_doctor.setNombre(dato);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Selecciona la especialidad del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;

							// En lugar de hacer que el usuario escriba el nombre de el tipo de doctor
							// el usuario selecciona el tipo de doctor mediante una lista que se le presenta
							int oEspecialidad[] = { 71, 128, 128, 128 };
							int nEspecialidad = 1;

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

								if (key == 72)		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
								{
									nEspecialidad--;

									if (nEspecialidad == 0)
									{
										nEspecialidad = 4;
									}
								}
								else if (key == 80)	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
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
								_doctor.setEspecialidad("Cardiólogo");
								break;

							case 2:
								_doctor.setEspecialidad("Pediatra");
								break;

							case 3:
								_doctor.setEspecialidad("Ginecólogo");
								break;

							case 4:
								_doctor.setEspecialidad("Dermatólogo");
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
							getline(cin, dato);
							_doctor.setDireccion(dato);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la hora de entrada del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_doctor.setHoraInicio(_mInterfaz.ingresarHora());

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la hora de salida del doctor:";
							_mInterfaz.moverXY(25, 7);
							cout << cuadroIngresarTexto;
							_doctor.setHoraFin(_mInterfaz.ingresarHora());

							// Si la hora de salida del doctor es menor que la hora de entrada, se entrará a este ciclo while
							if (stoi(_doctor.getHoraFin().substr(0, 2)) < stoi(_doctor.getHoraInicio().substr(0, 2)))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "La hora de salida es menor que la hora de entrada. Hora de entrada: " << _doctor.getHoraInicio();
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa una hora de salida mayor a la hora de entrada.";
								_doctor.setHoraFin(_mInterfaz.ingresarHora());
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
							_doctor.setTelefono(_mInterfaz.ingresarNumeros());

							// Si el telefono no continene 8 digitos, se ingresará al ciclo while
							while (_doctor.getTelefono().length() != 8)
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "Lo ingresado no coincide con el formato solicitado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de telefono.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_doctor.setTelefono(_mInterfaz.ingresarNumeros());
							}

							cout << "\033[44m\033[30m";

							// Una vez que el usuario termina de ingresar todos los datos se le mostrará un resumen con todos los datos ingresados.
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
							cout << _doctor.getCedula();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre Completo:";
							_mInterfaz.moverXY(25, 7);
							cout << _doctor.getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Tipo de Especialidad:";
							_mInterfaz.moverXY(25, 10);
							cout << _doctor.getEspecialidad();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Dirección:";
							_mInterfaz.moverXY(25, 13);
							cout << _doctor.getDireccion();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de Entrada:";
							_mInterfaz.moverXY(25, 16);
							cout << _doctor.getHoraInicio();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 18);
							cout << "Hora de Salida:";
							_mInterfaz.moverXY(25, 19);
							cout << _doctor.getHoraFin();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 21);
							cout << "Telefono:";
							_mInterfaz.moverXY(25, 22);
							cout << _doctor.getTelefono();

							// Se le preguntará al usuario si los datos ingresados son correctos, de lo contrario se le solicitará que vuelva a ingresar todos los datos
							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 24) == 1)
							{
								doctor = new doctores(_doctor.getCedula(), _doctor.getNombre(), _doctor.getEspecialidad(), _doctor.getDireccion(), _doctor.getHoraInicio(), _doctor.getHoraFin(), _doctor.getTelefono());
								arbolDoctor.registrarDatos(doctor, _doctor.getCedula());
								_archivo.guardarDoctor(arbolDoctor);
								_doctor.~doctores();
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
							cout << "\033[100m" << "Ingresar Paciente";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de cedula del paciente: (9 digitos)";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_paciente.setCedula(_mInterfaz.ingresarNumeros());

							// Si la cedula no tiene 9 digitos, o ya existe en el arbol, entrará al ciclo while
							// y se le solicitará al usuario que vuelva a ingresar los datos hasta que ingrese una cedula que 
							// cumpla con los requisitos
							while (_paciente.getCedula().length() != 9 || arbolPaciente.verificarDatos(_paciente.getCedula()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "Lo ingresado no coincide con el formato solicitado o ya existe.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de cedula.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_paciente.setCedula(_mInterfaz.ingresarNumeros());
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el nombre completo del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, dato);
							_paciente.setNombre(dato);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la dirección del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, dato);
							_paciente.setDireccion(dato);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el número de telefono del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_paciente.setTelefono(_mInterfaz.ingresarNumeros());

							// Si el telefono no tiene 8 digitos, se le solicitará al usuario que vuelva a ingresar el telefono
							while (_paciente.getTelefono().length() != 8)
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "Lo ingresado no coincide con el formato solicitado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor vuelve a ingresar el número de telefono.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_paciente.setTelefono(_mInterfaz.ingresarNumeros());
							}

							cout << "\033[44m\033[30m";

							// Cuando el usuario termina de ingresar los datos se le mostrará un resumen con los datos ingresados
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
							cout << _paciente.getCedula();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre Completo:";
							_mInterfaz.moverXY(25, 7);
							cout << _paciente.getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Dirección:";
							_mInterfaz.moverXY(25, 10);
							cout << _paciente.getDireccion();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Telefono:";
							_mInterfaz.moverXY(25, 13);
							cout << _paciente.getTelefono();

							// Se le preguntará al usuario si los datos ingresados son correctos, de lo contrario, se le pedira que vuelva a ingresar los datos
							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 15) == 1)
							{
								paciente = new pacientes(_paciente.getCedula(), _paciente.getNombre(), _paciente.getDireccion(), _paciente.getTelefono());
								arbolPaciente.registrarDatos(paciente, _paciente.getCedula());
								_archivo.guardarPaciente(arbolPaciente);
								_paciente.~pacientes();
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
							cout << "\033[100m" << "Ingresar Medicamento";

							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa el codigo del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_medicamento.setCodigo(_mInterfaz.ingresarNumeros());

							// Si el codigo de el medicamento ya existe, se le solicitará al usuario que vuelva a ingresar otro codigo
							while (arbolMedicamento.verificarDatos(_medicamento.getCodigo()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "El codigo ingresado ya está registrado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa otro codigo de medicamento.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_medicamento.setCodigo(_mInterfaz.ingresarNumeros());
							}

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el nombre del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							getline(cin, dato);
							_medicamento.setNombre(dato);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 6);
							cout << "Ingresa la cantidad en inventario del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_medicamento.setCantidadInventario(stoi(_mInterfaz.ingresarNumeros()));

							cout << "\033[44m\033[30m";

							// Una vez que el usuario termine de ingresar los datos, se le mostrará un resumen de los datos ingresados
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
							cout << _medicamento.getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del medicamento:";
							_mInterfaz.moverXY(25, 7);
							cout << _medicamento.getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Cantidad en inventario del medicamento:";
							_mInterfaz.moverXY(25, 10);
							cout << _medicamento.getCantidadInventario();

							// Se le preguntará al usuario si los datos ingresados son correctos, de los contrario
							// se le predirá que los vuelva a ingresar
							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 12) == 1)
							{
								medicamento = new medicamentos(_medicamento.getCodigo(), _medicamento.getNombre(), _medicamento.getCantidadInventario());
								arbolMedicamento.registrarDatos(medicamento, _medicamento.getCodigo());
								_archivo.guardarMedicamento(arbolMedicamento);
								_medicamento.~medicamentos();
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
							cout << "\033[100m" << "Registrar Cita";

							// Se genera un codigo para la cita
							_cita.setCodigo(to_string(_mInterfaz.generarCodigo()));

							// Si el codigo ya existe, se generará otro hasta que no esté repetido
							while (arbolCita.verificarDatos(_cita.getCodigo()))
							{
								_cita.setCodigo(to_string(_mInterfaz.generarCodigo()));
							}

							// Se generará un codigo para las facturas
							_factura.setCodigo(to_string(_mInterfaz.generarCodigo()));

							// Si el codigo ya existe, se generará otro hasta que no esté repetido
							while (arbolFactura.verificarDatos(_factura.getCodigo()))
							{
								_factura.setCodigo(to_string(_mInterfaz.generarCodigo()));
							}

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el número de cedula del paciente registrado:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_paciente.setCedula(_mInterfaz.ingresarNumeros());
							
							// Se le solicitará la cedula del paciente que ya registrado y se verificará
							// si la cedula no existe, se le solicitará al usuario volver a ingresar el número de cedula
							while (!arbolPaciente.verificarDatos(_paciente.getCedula()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "La cedula ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa un número de cedula registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_paciente.setCedula(_mInterfaz.ingresarNumeros());
							}
							
							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(0, 6);
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa la cedula del doctor registrado:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_doctor.setCedula(_mInterfaz.ingresarNumeros());

							// Se le solicitará la cedula del doctor que ya registrado y se verificará
							// si la cedula no existe, se le solicitará al usuario volver a ingresar el número de cedula
							while (!arbolDoctor.verificarDatos(_doctor.getCedula()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "La cedula ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa un número de cedula registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_doctor.setCedula(_mInterfaz.ingresarNumeros());
							}

							// Se obtendrá el nodo con los datos para vincular al doctor con la cita
							doctor = arbolDoctor.obtenerDatos(_doctor.getCedula());

							_mInterfaz.moverXY(0, 8);
							cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;

							// Se le pedirá al usuario que ingrese la fecha y la hora de la cita, y se obtendrán los valores retornados de esa funcion
							_mInterfaz.mostrarHoraCita(arbolCita, doctor, dato, hora);

							_cita.setFecha(dato);
							_cita.setHora(hora);

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m\033[30m" << "Ingresa el costo de la cita: (En Colones)";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_factura.setMonto(stoi(_mInterfaz.ingresarNumeros()));

							cout << "\033[44m\033[30m";
							
							// Una vez que el usuario termina de ingresar los datos, se le mostrará un resumen con los datos
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

							// Se obtendrá el nodo del paciente para vincular la cita con el paciente
							paciente = arbolPaciente.obtenerDatos(_paciente.getCedula());

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 3);
							cout << "Codigo de la cita:";
							_mInterfaz.moverXY(25, 4);
							cout << _cita.getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Codigo de la factura:";
							_mInterfaz.moverXY(25, 7);
							cout << _factura.getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 10);
							cout << paciente -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 13);
							cout << doctor -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << "Dia: " << _cita.getFecha().substr(0, 2) << " - Mes: " << _cita.getFecha().substr(2, 2) << " - Año: " << _cita.getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 18);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 19);
							cout << _cita.getHora();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 21);
							cout << "Costo total de la cita:";
							_mInterfaz.moverXY(25, 22);
							cout << _factura.getMonto();

							// Se le preguntará si los datos ingresados son correctos
							if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 24) == 1)
							{
								// Registramos la cita
								cita = new citas(_cita.getCodigo(), _cita.getFecha(), _cita.getHora(), doctor, paciente);
								arbolCita.registrarDatos(cita, _cita.getCodigo());
								_archivo.guardarCita(arbolCita);

								// Registramos la factura
								factura = new facturas(_factura.getCodigo(), _cita.getFecha(), paciente, _factura.getMonto());
								arbolFactura.registrarDatos(factura, _factura.getCodigo());
								_archivo.guardarFactura(arbolFactura);

								_cita.~citas();
								_paciente.~pacientes();
								_doctor.~doctores();
								_factura.~facturas();
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
						// Se realizará una verificacion para revisar si alguna cita registrada en el sistema
						if (!arbolCita.verificarVacio())
						{
							// Si no hay, se activará el try-catch enviando el siguiente mensaje
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
							cout << "\033[100m" << "Atender Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_cita.setCodigo(_mInterfaz.ingresarNumeros());

							// Se le solicitará al usuario que ingrese el codigo de la cita, y se verificará si ese codigo existe
							while (!arbolCita.verificarDatos(_cita.getCodigo()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "El codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_cita.setCodigo(_mInterfaz.ingresarNumeros());
							}

							cita = arbolCita.obtenerDatos(_cita.getCodigo());

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
							cout << cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << cita -> getFecha().substr(0, 2) << " - Mes: " << cita -> getFecha().substr(2, 2) << " - Año: " << cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << cita -> getHora();

							// Se le pregunatará al usuario si desea atender la cita
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
									cout << "\033[100m" << "Atender Cita";

									// Se generará un codigo para la receta medica
									_recetaMedica.setCodigo(to_string(_mInterfaz.generarCodigo()));

									// Si el codigo generado ya existe, se generará otro hasta que no salga repetido
									while (arbolRecetaMedica.verificarDatos(_recetaMedica.getCodigo()))
									{
										_recetaMedica.setCodigo(to_string(_mInterfaz.generarCodigo()));
									}

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa el diagnostico del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									getline(cin, dato);
									_recetaMedica.setDiagnostico(dato);

									_mInterfaz.moverXY(0, 6);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa el codigo del medicamento a recetar:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									_medicamento.setCodigo(_mInterfaz.ingresarNumeros());

									// Se le solicitará al usuario el codigo del medicamento, se verificará si el codigo existe
									while (!arbolMedicamento.verificarDatos(_medicamento.getCodigo()))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31m" << "El codigo ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa el codigo de medicamento registrado.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										_medicamento.setCodigo(_mInterfaz.ingresarNumeros());
									}

									// Se obtendrá el nodo del medicamento para vincular el medicamento con la receta
									medicamento = arbolMedicamento.obtenerDatos(_medicamento.getCodigo());

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa la cantidad de medicamentos a recetar:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									_recetaMedica.setCantidad(stoi(_mInterfaz.ingresarNumeros()));

									// Se verificará si la cantidad de medicamentos que el usuario ingresa es menor que la cantidad de medicamentos que hay en inventario
									while (!_mInterfaz.verificarCantidadMedicamento(medicamento -> getCantidadInventario(), _recetaMedica.getCantidad()))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31m" << "No hay suficiente cantidad en inventario de ese medicamento.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa una cantidad igual a " << medicamento -> getCantidadInventario() << " o menor.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										_recetaMedica.setCantidad(stoi(_mInterfaz.ingresarNumeros()));
									}

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa la dosis en la que el paciente debe tomar el medicamento:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									getline(cin, dato);
									_recetaMedica.setDosis(dato);

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
									cout << _recetaMedica.getCodigo();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 6);
									cout << "Nombre del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << cita -> getPaciente() -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 9);
									cout << "Diagnostico del paciente:";
									_mInterfaz.moverXY(25, 10);
									cout << _recetaMedica.getDiagnostico();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 12);
									cout << "Nombre del medicamento:";
									_mInterfaz.moverXY(25, 13);
									cout << medicamento -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Cantidad de medicamentos:";
									_mInterfaz.moverXY(25, 16);
									cout << _recetaMedica.getCantidad();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Dosis del medicamento:";
									_mInterfaz.moverXY(25, 16);
									cout << _recetaMedica.getDosis();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Doctor encargado:";
									_mInterfaz.moverXY(25, 16);
									cout << cita -> getDoctor() -> getNombre();

									// Se le solicitará al usuario si los datos ingresados son correctos
									if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 18) == 1)
									{
										// Se crea un dato de receta medica
										recetaMedica = new recetasMedicas(_recetaMedica.getCodigo(), cita -> getPaciente(), _recetaMedica.getDiagnostico(), medicamento, _recetaMedica.getCantidad(), _recetaMedica.getDosis(), cita -> getDoctor());
										arbolRecetaMedica.registrarDatos(recetaMedica, _recetaMedica.getCodigo());
										_archivo.guardarRecetaMedica(arbolRecetaMedica);

										// Se actualiza la cantidad en inventario del medicamento
										medicamento -> setCantidadInventario(medicamento -> getCantidadInventario() - _recetaMedica.getCantidad());
										_archivo.guardarMedicamento(arbolMedicamento);

										// Se elimina la cita del sistema
										arbolCita.eliminarDatos(cita, cita -> getCodigo());
										_archivo.guardarCita(arbolCita);
										_cita.~citas();
										_recetaMedica.~recetasMedicas();
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
						// Se verificará si hay citas registradas en el sistema
						if (!arbolCita.verificarVacio())
						{
							// En caso de no haber citas, se activará el try-catch con el siguiente mensaje
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
							cout << "\033[100m" << "Modificar Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_cita.setCodigo(_mInterfaz.ingresarNumeros());

							// Se verificará si el codigo de la cita de existe en el arbol
							while (!arbolCita.verificarDatos(_cita.getCodigo()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "El codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_cita.setCodigo(_mInterfaz.ingresarNumeros());
							}

							// Se obtendrá el nodo de la cita para ser modificada
							cita = arbolCita.obtenerDatos(_cita.getCodigo());

							cout << "\033[44m\033[30m";

							// Se le mostrará al usuario los datos de ese nodo
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
							cout << cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << cita -> getFecha().substr(0, 2) << " - Mes: " << cita -> getFecha().substr(2, 2) << " - Año: " << cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << cita -> getHora();

							// Se le preguntará si desea editar esa cita
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
									cout << "\033[100m" << "Modificar Cita";

									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa el número de cedula del paciente registrado:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									_paciente.setCedula(_mInterfaz.ingresarNumeros());

									// Se verificará si la cedula ingresada existe
									while (!arbolPaciente.verificarDatos(_paciente.getCedula()))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31m" << "La cedula ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa un número de cedula registrada.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										_paciente.setCedula(_mInterfaz.ingresarNumeros());
									}

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(0, 6);
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;
									_mInterfaz.moverXY(25, 6);
									cout << "\033[100m" << "Ingresa la cedula del doctor registrado:";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									_doctor.setCedula(_mInterfaz.ingresarNumeros());

									// Se verificará si la cedula ingresada existe
									while (!arbolDoctor.verificarDatos(_doctor.getCedula()))
									{
										_mInterfaz.moverXY(25, 8);
										cout << "\033[100m\033[31m" << "La cedula ingresada no está registrada.";
										_mInterfaz.moverXY(25, 9);
										cout << "Por favor ingresa un número de cedula registrada.";
										_mInterfaz.moverXY(25, 7);
										cout << "\033[40m\033[37m" << cuadroIngresarTexto;
										_mInterfaz.moverXY(25, 7);
										_doctor.setCedula(_mInterfaz.ingresarNumeros());
									}

									// Se obtendrá el nodo para vincular el doctor con la cita
									doctor = arbolDoctor.obtenerDatos(_doctor.getCedula());

									_mInterfaz.moverXY(0, 8);
									cout << "\033[44m\033[30m" << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
									cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal;

									_mInterfaz.mostrarHoraCita(arbolCita, doctor, dato, hora);

									_cita.setFecha(dato);
									_cita.setHora(hora);

									cout << "\033[44m\033[30m";

									// Se le mostrará al usuario los nuevos datos ingresados
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

									// Se obtendrá el nodo para vincular el paciente con la cita
									paciente = arbolPaciente.obtenerDatos(_paciente.getCedula());

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 3);
									cout << "Codigo de la cita:";
									_mInterfaz.moverXY(25, 4);
									cout << cita -> getCodigo();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 6);
									cout << "Nombre del paciente:";
									_mInterfaz.moverXY(25, 7);
									cout << paciente -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 9);
									cout << "Nombre del doctor:";
									_mInterfaz.moverXY(25, 10);
									cout << doctor -> getNombre();

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 12);
									cout << "Fecha de la cita:";
									_mInterfaz.moverXY(25, 13);
									cout << "Dia: " << _cita.getFecha().substr(0, 2) << " - Mes: " << _cita.getFecha().substr(2, 2) << " - Año: " << _cita.getFecha().substr(4, 4);

									cout << "\033[100m\033[30m";
									_mInterfaz.moverXY(25, 15);
									cout << "Hora de la cita:";
									_mInterfaz.moverXY(25, 16);
									cout << _cita.getHora();

									// Se le preguntará si los datos ingresados son correctos
									if (_mInterfaz.confirmarDatos("¿Los datos ingresados son correctos?", 18) == 1)
									{
										cita -> setFecha(_cita.getFecha());
										cita -> setHora(_cita.getHora());
										cita -> setDoctor(doctor);
										cita -> setPaciente(paciente);

										_archivo.guardarCita(arbolCita);
										_mInterfaz.mostrarMensajeExito("¡La cita fue actualizada con exito!");

										_cita.~citas();
										_paciente.~pacientes();
										_doctor.~doctores();
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
						// Se verificará si hay citas registradas en el sistema
						if (!arbolCita.verificarVacio())
						{
							// Se activará el try-catch con el siguiente mensaje
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
							cout << "\033[100m" << "Cancelar Cita";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el codigo de cita registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_cita.setCodigo(_mInterfaz.ingresarNumeros());

							// Se verificará si el codigo ingresado existe
							while (!arbolCita.verificarDatos(_cita.getCodigo()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "El codigo ingresada no está registrada.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de cita registrado.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_cita.setCodigo(_mInterfaz.ingresarNumeros());
							}

							// Se obtendrán los datos de ese nodo para mostrar al usuario y ser eliminado
							cita = arbolCita.obtenerDatos(_cita.getCodigo());

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
							cout << cita -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << cita -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Nombre del doctor:";
							_mInterfaz.moverXY(25, 10);
							cout << cita -> getDoctor() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Fecha de la cita:";
							_mInterfaz.moverXY(25, 13);
							cout << "Dia: " << cita -> getFecha().substr(0, 2) << " - Mes: " << cita -> getFecha().substr(2, 2) << " - Año: " << cita -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 15);
							cout << "Hora de la cita:";
							_mInterfaz.moverXY(25, 16);
							cout << cita -> getHora();

							// Se le preguntará al usuario si desea cancelar la cita
							if (_mInterfaz.confirmarDatos("¿Deseas cancelar esta cita?", 18) == 1)
							{
								// Se eliminará el nodo del arbol
								arbolCita.eliminarDatos(cita, cita -> getCodigo());
								_archivo.guardarCita(arbolCita);
								_mInterfaz.mostrarMensajeExito("¡La cita fue cancelada con exito!");
								_cita.~citas();
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
					// Consultar Facturas
					try
					{
						// Se verificará si hay facturas registradas en el sistema
						if (!arbolFactura.verificarVacio())
						{
							throw exception("!No hay facturas registradas en el sistema!");
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
							cout << "\033[100m" << "Consultar factura";

							_mInterfaz.moverXY(25, 6);
							cout << "\033[100m" << "Ingresa el codigo de la factura registrada:";
							_mInterfaz.moverXY(25, 7);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							_factura.setCodigo(_mInterfaz.ingresarNumeros());

							// Se verificará si el codigo existe
							while (!arbolFactura.verificarDatos(_factura.getCodigo()))
							{
								_mInterfaz.moverXY(25, 8);
								cout << "\033[100m\033[31m" << "El codigo ingresado no está registrado.";
								_mInterfaz.moverXY(25, 9);
								cout << "Por favor ingresa el codigo de la factura registrada.";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_factura.setCodigo(_mInterfaz.ingresarNumeros());
							}

							// Se obtendrá el nodo de la factura para mostrar al usuario
							factura = arbolFactura.obtenerDatos(_factura.getCodigo());

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
							cout << "Codigo de la factura:";
							_mInterfaz.moverXY(25, 4);
							cout << factura -> getCodigo();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 6);
							cout << "Nombre del paciente:";
							_mInterfaz.moverXY(25, 7);
							cout << factura -> getPaciente() -> getNombre();

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 9);
							cout << "Fecha de facturación:";
							_mInterfaz.moverXY(25, 10);
							cout << "Dia: " << factura -> getFecha().substr(0, 2) << " - Mes: " << factura -> getFecha().substr(2, 2) << " - Año: " << factura -> getFecha().substr(4, 4);

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 12);
							cout << "Costo de la cita:";
							_mInterfaz.moverXY(25, 13);
							// wcout permite inprimir caracteres la codificacion / formato UTF-8
							wcout << colon << factura -> getMonto();

							// Se le preguntará al usuario si desea consultar otra factura
							if (_mInterfaz.confirmarDatos("¿Deseas consultar otra factura?", 15) == 2)
							{
								_factura.~facturas();
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
						// Consultar Receta Medica
						try
						{
							// Se verificará si hay recetas medicas registradas
							if (!arbolRecetaMedica.verificarVacio())
							{
								// Se activará el try-catch con el siguiente mensaje
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
								cout << "\033[100m" << "Consultar receta medica";

								_mInterfaz.moverXY(25, 6);
								cout << "\033[100m" << "Ingresa el codigo de la receta medica registrada:";
								_mInterfaz.moverXY(25, 7);
								cout << "\033[40m\033[37m" << cuadroIngresarTexto;
								_mInterfaz.moverXY(25, 7);
								_recetaMedica.setCodigo(_mInterfaz.ingresarNumeros());

								// Se verificará si el codigo existe en el arbol
								while (!arbolRecetaMedica.verificarDatos(_recetaMedica.getCodigo()))
								{
									_mInterfaz.moverXY(25, 8);
									cout << "\033[100m\033[31m" << "El codigo ingresado no está registrado.";
									_mInterfaz.moverXY(25, 9);
									cout << "Por favor ingresa el codigo de la receta medica registrada.";
									_mInterfaz.moverXY(25, 7);
									cout << "\033[40m\033[37m" << cuadroIngresarTexto;
									_mInterfaz.moverXY(25, 7);
									_recetaMedica.setCodigo(_mInterfaz.ingresarNumeros());
								}

								// Se obtendrá el nodo de la receta medica para mostrar al usuario
								recetaMedica = arbolRecetaMedica.obtenerDatos(_recetaMedica.getCodigo());

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
								cout << "Codigo de la receta medica:";
								_mInterfaz.moverXY(25, 4);
								cout << recetaMedica -> getCodigo();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 6);
								cout << "Nombre del paciente:";
								_mInterfaz.moverXY(25, 7);
								cout << recetaMedica -> getPaciente() -> getNombre();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 9);
								cout << "Diagnostico del paciente:";
								_mInterfaz.moverXY(25, 10);
								cout << recetaMedica -> getDiagnostico();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 12);
								cout << "Nombre del medicamento:";
								_mInterfaz.moverXY(25, 13);
								cout << recetaMedica -> getMedicamento() -> getNombre();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 15);
								cout << "Cantidad de medicamentos:";
								_mInterfaz.moverXY(25, 16);
								cout << recetaMedica -> getCantidad();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 18);
								cout << "Dosis del medicamento:";
								_mInterfaz.moverXY(25, 19);
								cout << recetaMedica -> getDosis();

								cout << "\033[100m\033[30m";
								_mInterfaz.moverXY(25, 21);
								cout << "Doctor encargado:";
								_mInterfaz.moverXY(25, 22);
								cout << recetaMedica -> getDoctor() -> getNombre();

								// Se le preguntará al usuario si desea consultar otra receta medica
								if (_mInterfaz.confirmarDatos("¿Deseas consultar otra receta medica?", 24) == 2)
								{
									_recetaMedica.~recetasMedicas();
									break;
								}
							}
						}
						catch (exception& e)
						{
							_mInterfaz.mostrarMensajeFallido(e.what());
						}
						break;

				case 10:
					// Mostrar Arbol
					try
					{
						// Se le mostrará al usuario los arboles que existen, y se le solicitará que seleccione uno
						int arbol = _mInterfaz.seleccionarArbol("Mostrar Arbol", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores

							// Se verificará si el hay doctores registrados
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							// Se limpiará el vector en caso de ser usado anteriormente
							listaCodigos.clear();

							// Se obtendrá la lista de codigos en forma de In-Orden
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
							cout << "\033[100m" << "Mostrando arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							// Se esperará a que el usuario pulse ENTER para continuar
							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Mostrando arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Mostrando arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Mostrando arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolFactura.mostrarArbol(listaCodigos);
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
							cout << "\033[100m" << "Mostrando arbol de facturas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
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
							cout << "\033[100m" << "Mostrando arbol de recetas medicas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
					// Recorrido Profundo
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Recorrido Profundo", 50);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							listaCodigos.clear();

							// Se obtendrá la lista de codigos en forma de Pre-Orden
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
							cout << "\033[100m" << "Recorrido profundo del arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Recorrido profundo del arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Recorrido profundo del arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Recorrido profundo del arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolFactura.recorridoProfundidad(listaCodigos);
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
							cout << "\033[100m" << "Recorrido profundo del arbol de facturas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
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
							cout << "\033[100m" << "Recorrido profundo del arbol de recetas medicas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
					// Recorrido por Niveles
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Recorrido por Niveles", 50);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							listaCodigos.clear();

							// Se obtendrá la lista de codigos para el recorrido por niveles
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
							cout << "\033[100m" << "Recorrido por niveles del arbol de doctores:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Recorrido por niveles del arbol de pacientes:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100mRecorrido por niveles del arbol de medicamentos:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[100m" << "Recorrido por niveles del arbol de citas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							listaCodigos.clear();

							arbolFactura.recorridoPorNiveles(listaCodigos);
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
							cout << "\033[100m" << "Recorrido por niveles del arbol de facturas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
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
							cout << "\033[100m" << "Recorrido por niveles del arbol de recetas medicas:";

							for (int i = 0; i < cantidad; i++)
							{
								_mInterfaz.moverXY(25, 7 + i);
								cout << listaCodigos[i];
							}

							_mInterfaz.moverXY(55, cantidad + 8);
							cout << "\033[41m\033[37m" << "Continuar";

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
					// Altura del arbol
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Altura del Arbol", 51);

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
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[41m\033[37m" << "Continuar";

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
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							cantidad = arbolFactura.alturaArbol();

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
							cout << "La altura de el arbol de facturas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
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
							cout << "\033[41m\033[37m" << "Continuar";

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

				case 14:
					// Contar Nodos
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Contar Nodos", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							cantidad = arbolDoctor.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de doctores es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

							cantidad = arbolPaciente.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de pacientes es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

							cantidad = arbolMedicamento.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de medicamentos es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

							cantidad = arbolCita.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de citas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							cantidad = arbolFactura.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de facturas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							cantidad = arbolRecetaMedica.contarNodos();

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
							cout << "La cantidad de nodos en el arbol de recetas medicas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

				case 15:
					// Contar Hojas
					try
					{
						int arbol = _mInterfaz.seleccionarArbol("Contar Hojas", 53);

						switch (arbol)
						{
						case 1:
							// Arbol Doctores
							if (!arbolDoctor.verificarVacio())
							{
								throw exception("No hay doctores registrados en el sistema.");
							}

							cantidad = arbolDoctor.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de doctores es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

							cantidad = arbolPaciente.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de pacientes es:";

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

							cantidad = arbolMedicamento.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de medicamentos es:";

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

							cantidad = arbolCita.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de citas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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
							// Arbol Facturas
							if (!arbolFactura.verificarVacio())
							{
								throw exception("No hay facturas registrados en el sistema.");
							}

							cantidad = arbolFactura.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de facturas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

						case 6:
							// Arbol Recetas Medicas
							if (!arbolRecetaMedica.verificarVacio())
							{
								throw exception("No hay recetas medicas registrados en el sistema.");
							}

							cantidad = arbolRecetaMedica.contarHojas();

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
							cout << "La cantidad de hojas en el arbol de recetas medicas es:";

							_mInterfaz.moverXY(25, 7);
							cout << cantidad;

							_mInterfaz.moverXY(55, 9);
							cout << "\033[41m\033[37m" << "Continuar";

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

				case 16:
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
						cout << "\033[100m" << "Salir";

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
			Set[15] = 128;

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

			case 16:
				Set[15] = 71;
				break;
			}
		}
	}
}
