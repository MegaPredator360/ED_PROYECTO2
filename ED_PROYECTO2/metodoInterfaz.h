// Archivos
#include "archivos.h"

class metodoInterfaz
{
public:
	// Cambiar el color de la opcíon marcada en el menú
	void color(int _color);

	// Indicará la posición del texto al mostrarse en la consola
	void moverXY(int _x, int _y);

	// Permitirá al usuario solo ingresar números en tiempo real
	string ingresarNumeros();

	// Permitirá al usuario ingresar una hora
	string ingresarHora();

	// Permitirá al usuario ingresar una fecha
	string ingresarFecha();

	// Hará que el usuario pueda seleccionar si desea continuar con la accion o no
	int confirmarDatos(string _texto, int _posicion);

	// Mostrará un cuadro de mensaje cuando una acción se realiza con exito
	void mostrarMensajeExito(string _mensaje);

	// Mostrará un cuadro de mensaje cuando ocurre un error durante la realización de una accion
	void mostrarMensajeFallido(string _mensaje);

	// Se verificará si hay doctores, pacientes y medicamentos registrados
	void verificarVacio(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento);

	// Se encargará de generar un codigo aleatorio que será dado al codigo de citas y recetas medicas
	int generarCodigo();

	// Se encargará de mostrar las horas disponibles de una fecha especifica de la cita
	void mostrarHoraCita(arboles<citas> _arbolCita, doctores* _doctor, string& _fecha, string& _hora);

	// Se encargará de verificar que no se le den más medicamentos a un paciente cuando no hay
	bool verificarCantidadMedicamento(int _inventario, int _cantidad);

	// Se encargará de seleccionar un arbol para obtener otros datos
	int seleccionarArbol(string _opcion, int _posicion);
};

