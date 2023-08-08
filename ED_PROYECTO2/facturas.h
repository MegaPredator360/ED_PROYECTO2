#include "citas.h"

class facturas
{
protected:
	int numeroFactura;
	string fecha;
	citas cita;
	float monto;

public:
	// Constructor vacio
	facturas(void);

	// Constructor lleno
	facturas(
		int _numeroFactura,
		string _fecha,
		citas _cita,
		float _monto
	);

	// Destructor
	~facturas();

	// Getters
	int getNumeroFactura();
	string getFecha();
	citas getCita();
	float getMonto();

	// Setters
	void setNumeroFactura(int _numeroFactura);
	void setFecha(string _fecha);
	void setCita(citas _cita);
	void setMonto(float _monto);
};

