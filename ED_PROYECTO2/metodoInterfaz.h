// Archivos
#include "archivos.h"

class metodoInterfaz
{
public:
	// Cambiar el color de la opc�on marcada en el men�
	void color(int _color);

	// Indicar� la posici�n del texto al mostrarse en la consola
	void moverXY(int _x, int _y);

	// Permitir� al usuario solo ingresar n�meros en tiempo real
	string ingresarNumeros();

	// Permitir� al usuario ingresar una hora
	string ingresarHora();

	// Permitir� al usuario ingresar una fecha
	string ingresarFecha();

	// Har� que el usuario pueda seleccionar si desea continuar con la accion o no
	int confirmarDatos(string _texto, int _posicion);

	// Mostrar� un cuadro de mensaje cuando una acci�n se realiza con exito
	void mostrarMensajeExito(string _mensaje);

	// Mostrar� un cuadro de mensaje cuando ocurre un error durante la realizaci�n de una accion
	void mostrarMensajeFallido(string _mensaje);

	// Se verificar� si hay doctores, pacientes y medicamentos registrados
	void verificarVacio(arboles<doctores> _arbolDoctor, arboles<pacientes> _arbolPaciente, arboles<medicamentos> _arbolMedicamento);

	// Se encargar� de generar un codigo aleatorio que ser� dado al codigo de citas y recetas medicas
	int generarCodigo();

	// Se encargar� de mostrar las horas disponibles de una fecha especifica de la cita
	void mostrarHoraCita(arboles<citas> _arbolCita, doctores* _doctor, string& _fecha, string& _hora);

	// Se encargar� de verificar que no se le den m�s medicamentos a un paciente cuando no hay
	bool verificarCantidadMedicamento(int _inventario, int _cantidad);

	// Se encargar� de seleccionar un arbol para obtener otros datos
	int seleccionarArbol(string _opcion, int _posicion);
};

