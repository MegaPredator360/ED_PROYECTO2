#include "interfaz.h"

int main()
{
	// Para mostrar caracteres especiales
	setlocale(LC_ALL, "");

	// Llamado a la clase interfaz
	interfaz _interfaz;

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); // Guarda las dimensiones actuales de la ventana de la consola

	MoveWindow(console, r.left, r.top, 920, 520, TRUE); // 800 width, 100 height

	// Menú Principal
	_interfaz.menuPrincipal();

	return 0;
}