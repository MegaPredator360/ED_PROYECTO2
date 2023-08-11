#include "interfaz.h"

int main()
{
	// Para mostrar caracteres especiales
	setlocale(LC_ALL, "");

	// Llamado a la clase interfaz
	interfaz _interfaz;

	// Obtener el handle de la consola actual
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Definir la nueva posici�n y tama�o de la ventana
	SMALL_RECT windowSize = { 0, 0, 130, 35 };  // Cambia los valores seg�n tus necesidades

	// Establecer el nuevo tama�o de la ventana
	SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);

	// Men� Principal
	_interfaz.menuPrincipal();

	return 0;
}