#include "interfaz.h"

void interfaz::menuPrincipal()
{
	while (1)
	{
		cout << "1. Ingresar Doctora" << endl;
		cout << "2. Ingresar Paciente" << endl;
		cout << "3. Ingresar Medicamento" << endl;
		cout << "4. Registrar Cita" << endl;
		cout << "5. Modificar Cita" << endl;
		cout << "6. Eliminar Cita" << endl;
		cout << "7. Consultar Receta Medica" << endl;
		cout << "8. Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			try
			{
				// Valores para el procedimiento de la secuencia
				string secuencia;
				string confirmacion = "N";
				int cantidadMarcos = 0;

				while (confirmacion == "N")
				{
					system("cls");
					cout << endl;
					cout << "		[]--------------------------------------------[]" << endl;
					cout << "		|          Realizar procedimiento de           |" << endl;
					cout << "		|         remplazo de marcos de pagina         |" << endl;
					cout << "		[]--------------------------------------------[]" << endl;
					cout << endl;

					
			}
			catch (exception& e) {
				cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
				cout << "-------------------------" << endl;
				cout << "Volviendo al Menu Principal." << endl << endl;
				system("pause");
			}
			break;
		}
	}
}
