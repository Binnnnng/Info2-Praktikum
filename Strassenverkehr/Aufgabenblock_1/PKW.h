#pragma once
#include"Fahrzeug.h"
using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW();
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch);
	PKW(string namestr, double MaxGeschwindigkeit, double verbrauch, double volumen);
	virtual ~PKW();
	

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
	void dVerbrauch();
	void dTanken(double menge=-1);
	void vPKWInitialisierung();

};

