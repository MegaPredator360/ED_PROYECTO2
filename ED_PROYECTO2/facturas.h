#include "citas.h"

class facturas
{
protected:
	string codigo;
	string fecha;
	pacientes* paciente;
	int monto;

public:
	// Constructor vacio
	facturas(void);

	// Constructor lleno
	facturas(
		string _codigo,
		string _fecha,
		pacientes* _paciente,
		int _monto
	);

	// Destructor
	~facturas();

	// Getters
	string getCodigo();
	string getFecha();
	pacientes* getPaciente();
	int getMonto();

	// Setters
	void setCodigo(string _codigo);
	void setFecha(string _fecha);
	void setPaciente(pacientes* _paciente);
	void setMonto(int _monto);
};

