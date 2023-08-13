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
	string hora = "12";
	string minuto = "00";
	string sufijo = "a.m";
	int selector[] = { 128, 128, 128 };
	selector[0] = 71;
	int marcador = 1;
	int key = 0;

	while (1)
	{
		moverXY(25, 7);
		color(selector[0]);
		cout << hora;

		moverXY(28, 7);
		color(selector[1]);
		cout << minuto;

		moverXY(31, 7);
		color(selector[2]);
		cout << sufijo;

		key = _getch();


		// Valida si la flecha izquierda fue pulsada, valor 224 en ASCII
		if (key == 224)
		{
			key = _getch();

			if (key == 72)
			{
				if (marcador == 1)
				{
					int horaNum = stoi(hora);

					horaNum++;

					if (horaNum == 13)
					{
						horaNum = 1;
					}

					hora = to_string(horaNum);

					if (hora.size() == 1)
					{
						hora = "0" + hora;
					}
				}
				else if (marcador == 2)
				{
					if (minuto == "00")
					{
						minuto = "30";
					}
					else if (minuto == "30")
					{
						minuto = "00";
					}
				}
				else if (marcador == 3)
				{
					if (sufijo == "a.m")
					{
						sufijo = "p.m";
					}
					else if (sufijo == "p.m")
					{
						sufijo = "a.m";
					}
				}
			}
			else if (key == 80)
			{
				if (marcador == 1)
				{
					int horaNum = stoi(hora);
					horaNum--;

					if (horaNum == 0)
					{
						horaNum = 12;
					}

					hora = to_string(horaNum);

					if (hora.size() == 1)
					{
						hora = "0" + hora;
					}
				}
				else if (marcador == 2)
				{
					if (minuto == "00")
					{
						minuto = "30";
					}
					else if (minuto == "30")
					{
						minuto = "00";
					}
				}
				else if (marcador == 3)
				{
					if (sufijo == "a.m")
					{
						sufijo = "p.m";
					}
					else if (sufijo == "p.m")
					{
						sufijo = "a.m";
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

	string horaFinal = hora + ":" + minuto + " " + sufijo;
	return horaFinal;
}

void metodoInterfaz::mostrarMensajeExito(string _mensaje)
{
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
	cout << "\033[100m\033[30m¡Exito!";

	moverXY(25, 6);
	cout << _mensaje;

	moverXY(55, 8);
	cout << "\033[41m\033[37mAceptar";

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
	cout << "\033[100m\033[30m¡Error!";

	moverXY(25, 6);
	cout << _mensaje;

	moverXY(55, 8);
	cout << "\033[41m\033[37mAceptar";

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
