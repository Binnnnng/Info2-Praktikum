#pragma once
#include"Fahrzeug.h"
using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW();
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch);
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch, double volumen);
	void virtual vAusgabe();
	void virtual dVerbrauch();
	void virtual vAbfertigung();
	virtual ~PKW();

private:
	void vInitialisierung();
	string klasse;

protected:
	double p_dgesVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
	double p_dVerbrauch;
};

