#pragma once
#include"Fahrzeug.h"
#include"PKW.h"

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(const Fahrrad& fahrrad);
	Fahrrad(string namestr);
	Fahrrad(string namestr, double MaxGeschwindigkeit);
	virtual ~Fahrrad();
	void virtual vAusgabe();
	void virtual vostreamAusgabe(ostream &out);
	void virtual vZeichnen(Weg* pWeg);
	double virtual dGeschwindigkeit();

private:
	void vInitialisierung();

protected:
	double p_dgesVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
	double p_dVerbrauch;
	
};


