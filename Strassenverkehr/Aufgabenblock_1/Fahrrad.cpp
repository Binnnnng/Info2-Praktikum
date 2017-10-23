#include "Fahrrad.h"
#include <iostream>
#include<iomanip>

extern string klasse;

Fahrrad::Fahrrad() :Fahrzeug()
{
	vInitialisierung();
}

Fahrrad::Fahrrad(string namestr) :Fahrzeug(namestr)
{
	vInitialisierung();
}

Fahrrad::Fahrrad(string namestr, double MaxGeschwindigkeit) :Fahrzeug(namestr, MaxGeschwindigkeit)
{
	vInitialisierung();
}

Fahrrad::~Fahrrad()
{
}

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(14) << p_dgesVerbrauch;
	cout << setw(14) << p_dTankinhalt;
	cout << resetiosflags(ios::left) << endl;
}

void Fahrrad::vAbfertigung()
{
	Fahrzeug::dGeschwindigkeit(klasse);
	Fahrzeug::vAbfertigung();
}

void Fahrrad::vInitialisierung()
{
	p_dVerbrauch = 0.0;
	p_dgesVerbrauch = 0.0;
	p_dTankinhalt = 0.0;
	p_dTankvolumen = 0.0;
	klasse = "fahrrad";
}

double Fahrrad::dTanken(double menge)
{
	p_dTankinhalt = Fahrzeug::dTanken(-2);  //<-----------------------------------
	return 0;
}