#include "medicamentos.h"

class citas
{
protected:
	string codigo;
	string fecha;
	string hora;
	doctores doctor;
	pacientes paciente;

public:
	// Constructor vacio
	citas(void);

	// Constructor lleno
	citas(
		string _codigo,
		string _fecha,
		string _hora,
		doctores _doctor,
		pacientes _paciente
	);

	//Destructor
	~citas();

	// Getters
	string getCodigo();
	string getFecha();
	string getHora();
	doctores getDoctor();
	pacientes getPaciente();

	// Setters
	void setCodigo(string _codigo);
	void setFecha(string _fecha);
	void setHora(string _hora);
	void setDoctor(doctores _doctor);
	void setPaciente(pacientes _pacientes);
};

