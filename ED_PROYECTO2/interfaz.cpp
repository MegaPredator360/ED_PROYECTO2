#include "interfaz.h"

void interfaz::menuPrincipal()
{
	while (1)
	{
		system("cls");
		cout << "1. Ingresar Doctor" << endl;
		cout << "2. Ingresar Paciente" << endl;
		cout << "3. Ingresar Medicamento" << endl;
		cout << "4. Registrar Cita" << endl;
		cout << "5. Modificar Cita" << endl;
		cout << "6. Eliminar Cita" << endl;
		cout << "7. Consultar Receta Medica" << endl;
		cout << "8. Mostrar Arbol" << endl;
		cout << "9. Recorrido por profunidad" << endl;
		cout << "10. Recorrido por niveles" << endl;
		cout << "11. Altura del arbol" << endl;
		cout << "12. Contar Nodos" << endl;
		cout << "13. Contar Hojas" << endl;
		cout << "14. Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			try
			{
				confirmacion = 'N';

				while (confirmacion == 'N')
				{
					system("cls");
					cout << "Ingresar Doctor" << endl;

					cout << endl << "Ingresa el número de cedula del doctor:" << endl;
					cin >> cedula;

					cout << endl << "Ingresa el nombre del doctor:" << endl;
					cin >> nombre;

					cout << endl << "Ingresa la especialidad del doctor:" << endl;
					cin >> especialidad;

					cout << endl << "Ingresa la direccion del doctor:" << endl;
					cin >> direccion;

					cout << endl << "Ingresa la hora de inicio:" << endl;
					cin >> horaInicio;

					cout << endl << "Ingresa la hora de salida:" << endl;
					cin >> horaFinal;

					cout << endl << "Ingresa el número de telefono del doctor:" << endl;
					cin >> telefono;

					cout << endl << "¿Los datos ingresados son correctos?" << endl;
					cin >> confirmacion;

					if (confirmacion == 'S')
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

		case 2:
			// Ingresar Paciente
			try
			{
				confirmacion = 'N';

				while (confirmacion == 'N')
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

					if (confirmacion == 'S')
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
				confirmacion = 'N';

				while (confirmacion == 'N')
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

					if (confirmacion == 'S')
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
				confirmacion = 'N';

				while (confirmacion == 'N')
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

					if (confirmacion == 'S')
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
			// Salir
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

		}
	}
}
