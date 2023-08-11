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

	int oEspecialidad[] = { 128, 128, 128, 128 };
	int oConfirmacion[] = { 128, 128 };

	while (1)
	{
		system("cls");

		string espacios(120, ' ');
		string cuadroLado(20, ' ');
		string cuadroFinal(18, ' ');
		string cuadroBorde(76, '_');
		string cuadroRelleno(76, ' ');
		string cuadroMenuTexto(31, ' ');
		string cuadroIngresarTexto(50, ' ');
		string cuadroOpcion(21, ' ');

		cout << "\033[44m\033[30m" << espacios << endl << espacios << endl;
		cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m |" << cuadroMenuTexto << "Menú Principal" << cuadroMenuTexto << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
		cout << cuadroLado << "\033[100m | " << cuadroOpcion;

		for (int i = 0;;)
		{
			// Opcion 1
			// Indica donde se va a posicionar el cursor en la consola
			_mInterfaz.moverXY(44, 7);
			// Inidicará el color a ingresar marcar si la opcion es seleccionada
			_mInterfaz.color(Set[0]);
			// Texto de la opción
			cout << "         Ingresar Doctor         ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 2
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 8);
			_mInterfaz.color(Set[1]);
			cout << "        Ingresar Paciente        ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 3
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 9);
			_mInterfaz.color(Set[2]);
			cout << "      Ingresar Medicamentos      ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 4
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 10);
			_mInterfaz.color(Set[3]);
			cout << "          Registrar Cita         ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 5
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 11);
			_mInterfaz.color(Set[4]);
			cout << "          Modificar Cita         ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 6
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 12);
			_mInterfaz.color(Set[5]);
			cout << "          Eliminar Cita          ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 7
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 13);
			_mInterfaz.color(Set[6]);
			cout << "     Consultar Receta Medica     ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 8
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 14);
			_mInterfaz.color(Set[7]);
			cout << "          Mostrar Arbol          ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 9
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 15);
			_mInterfaz.color(Set[8]);
			cout << "        Recorrido Profundo       ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 10
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 16);
			_mInterfaz.color(Set[9]);
			cout << "      Recorrido por niveles      ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 11
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 17);
			_mInterfaz.color(Set[10]);
			cout << "         Altura del arbol        ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 12
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 18);
			_mInterfaz.color(Set[11]);
			cout << "           Contar Nodos          ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 13
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 19);
			_mInterfaz.color(Set[12]);
			cout << "           Contar Hojas          ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			// Opcion 14
			cout << cuadroLado << "\033[100m | " << cuadroOpcion;
			_mInterfaz.moverXY(44, 20);
			_mInterfaz.color(Set[13]);
			cout << "              Salir              ";
			cout << "\033[100m\033[30m" << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

			cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << "\033[44m\033[30m" << espacios << espacios << espacios;

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
				switch (opcion)
				{
				case 1:
					try
					{
						while (1)
						{
							system("cls");
							cout << "\033[44m\033[30m" << espacios << endl << espacios << endl;
							cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;
							cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m |" << cuadroOpcion << "          Ingresar Doctor         " << cuadroOpcion << "| \033[40m  \033[44m" << cuadroFinal << endl;

							for (int i = 0; i < 7; i++)
							{
								cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
							}
							cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
							cout << "\033[44m\033[30m" << espacios << espacios << espacios;

							cout << "\033[100m\033[30m";
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa el número de cedula del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, cedula);

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa el nombre completo del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, nombre);

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Selecciona la especialidad del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << cuadroIngresarTexto;

							int nEspecialidad = 1;
							oEspecialidad[0] = { 71 };

							while (1)
							{
								_mInterfaz.moverXY(25, 8);
								_mInterfaz.color(oEspecialidad[0]);
								cout << "Cardiólogo ";

								_mInterfaz.moverXY(25, 9);
								_mInterfaz.color(oEspecialidad[1]);
								cout << "Pediatra   ";

								_mInterfaz.moverXY(25, 10);
								_mInterfaz.color(oEspecialidad[2]);
								cout << "Ginecólogo ";

								_mInterfaz.moverXY(25, 11);
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

							_mInterfaz.moverXY(25, 8);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 9);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 10);
							cout << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 11);
							cout << cuadroIngresarTexto;

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa la dirección del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, direccion);

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa la hora de entrada del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, horaInicio);

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa la hora de salida del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, horaFinal);

							_mInterfaz.moverXY(25, 7);
							cout << "\033[100m\033[30m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 7);
							cout << "Ingresa el número de telefono del doctor:";
							_mInterfaz.moverXY(25, 8);
							cout << "\033[40m\033[37m" << cuadroIngresarTexto;
							_mInterfaz.moverXY(25, 8);
							getline(cin, telefono);

							_mInterfaz.moverXY(0, 7);
							for (int i = 0; i < 22; i++)
							{
								cout << "\033[44m" << cuadroLado << "\033[100m\033[30m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
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

							_mInterfaz.moverXY(25, 24);
							cout << "¿Los datos ingresados son correctos?" << endl;
							_mInterfaz.moverXY(28, 25);
							cout << "/";

							int nConfirmacion = 1;
							oConfirmacion[0] = 71;

							while (1)
							{
								_mInterfaz.moverXY(25, 25);
								_mInterfaz.color(oConfirmacion[0]);
								cout << "Sí";

								_mInterfaz.moverXY(30, 25);
								_mInterfaz.color(oConfirmacion[1]);
								cout << "No";

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
								// Valida si la flecha izquierda fue pulsada, valor 224 en ASCII
								else if (key == 224)
								{
									nConfirmacion++;

									if (nConfirmacion == 3)
									{
										nConfirmacion = 1;
									}

									// Se invoca al _getch() porque por alguna razón retorna un segundo valor que es el 77
									_getch();
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

							if (nConfirmacion == 1)
							{
								_doctor = new doctores(cedula, nombre, especialidad, direccion, horaInicio, horaFinal, telefono);
								arbolDoctor.registrarDatos(_doctor, cedula);
								break;
							}
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 2:
					// Ingresar Paciente
					try
					{
						confirmacion = "N";

						while (confirmacion == "N")
						{
							system("cls");
							cout << "Ingresar Paciente" << endl << endl;

							cout << "Ingresa el número de cedula del paciente:" << endl;
							cin >> cedula;

							cout << "Ingresa el nombre del paciente:" << endl;
							cin >> nombre;

							cout << "Ingresa la direccion del paciente:" << endl;
							cin >> direccion;

							cout << "Ingresa el número de telefono del paciente:" << endl;
							cin >> telefono;

							cout << "¿Los datos ingresados son correctos?" << endl;
							cin >> confirmacion;

							if (confirmacion == "S")
							{

							}
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 3:
					// Ingresar Medicamento
					try
					{
						confirmacion = "N";

						while (confirmacion == "N")
						{
							system("cls");
							cout << "Ingresar Medicamento" << endl << endl;

							cout << "Ingresa el codigo del medicamento:" << endl;
							cin >> codigo;

							cout << "Ingresa el nombre del medicamento:" << endl;
							cin >> nombre;

							cout << "Ingresa la cantidad en inventario del medicamento:" << endl;
							cin >> direccion;

							cout << "¿Los datos ingresados son correctos?" << endl;
							cin >> confirmacion;

							if (confirmacion == "S")
							{

							}
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
					}
					break;

				case 4:
					// Registrar Cita
					try
					{
						confirmacion = "N";

						while (confirmacion == "N")
						{
							system("cls");
							cout << "Ingresar Cita" << endl << endl;

							cout << "Ingresa el nombre del paciente:" << endl;
							cin >> paciente;

							cout << "Ingresa el nombre del doctor:" << endl;
							cin >> doctor;

							cout << "Ingresa la fecha de la cita:" << endl;
							cin >> fecha;

							cout << "Ingresa la hora de la cita:" << endl;
							cin >> hora;

							cout << "¿Los datos ingresados son correctos?" << endl;
							cin >> confirmacion;

							if (confirmacion == "S")
							{

							}
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al Menu Principal." << endl << endl;
						system("pause");
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
