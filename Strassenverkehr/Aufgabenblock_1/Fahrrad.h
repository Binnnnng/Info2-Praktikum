#pragma once
#include"Fahrzeug.h"
#include"PKW.h"

class Fahrrad :public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string namestr);
	Fahrrad(string namestr, double MaxGeschwindigkeit);
	virtual ~Fahrrad();
	void virtual vAusgabe();
	double dTanken(double menge);
	void virtual vAbfertigung();

private:
	void vInitialisierung();
	string klasse;

protected:
	double p_dgesVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
	double p_dVerbrauch;
};


