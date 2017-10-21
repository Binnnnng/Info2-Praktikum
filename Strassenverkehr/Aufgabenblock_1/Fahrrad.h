#pragma once
#include"Fahrzeug.h"
#include"PKW.h"

class Fahrrad :public Fahrzeug, public PKW
{
public:
	Fahrrad();
	Fahrrad(string namestr);
	Fahrrad(string namestr, double MaxGeschwindigkeit);
	virtual ~Fahrrad();
	void virtual vAusgabe();
	void virtual vAbfertigung();

private:
	void vInitialisierung();
	string klasse;
};


