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
	cout << setw(14) << "0.00";
	cout << setw(14) << "0.00";
	cout << resetiosflags(ios::left) << endl;
}

void Fahrrad::vAbfertigung()
{
	dGeschwindigkeit(klasse);
	Fahrzeug::vAbfertigung();
}

void Fahrrad::vInitialisierung()
{
	klasse = "fahrrad";
}