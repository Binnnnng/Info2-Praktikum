#pragma once
#include"Fahrzeug.h"
using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW();
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch);
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch, double volumen);
	void virtual vPKWAusgabe();
	void virtual dVerbrauch();
	void virtual vPKWAbfertigung();
	virtual ~PKW();

private:
	void vPKWInitialisierung();
	double p_dgesVerbrauch;
	double p_dTankinhalt;
	double p_dVerbrauch;
	double p_dTankvolumen;

};

