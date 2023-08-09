#include "interfaz.h"

int main()
{
	// Llamado a la clase interfaz
	interfaz _interfaz;

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); // Guarda las dimensiones actuales de la ventana de la consola

	MoveWindow(console, r.left, r.top, 800, 100, TRUE); // 800 width, 100 height

	// Men� Principal
	_interfaz.menuPrincipal();

	return 0;
}