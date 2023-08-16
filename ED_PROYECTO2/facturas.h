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
	virtual ~facturas();

	// Getters
	virtual string getCodigo();
	virtual string getFecha();
	virtual pacientes* getPaciente();
	virtual int getMonto();

	// Setters
	void setCodigo(string _codigo);
	void setFecha(string _fecha);
	void setPaciente(pacientes* _paciente);
	void setMonto(int _monto);
};

