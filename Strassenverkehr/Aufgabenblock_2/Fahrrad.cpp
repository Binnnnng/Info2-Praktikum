#include"stdafx.h"
#include "Fahrrad.h"
#include <iostream>
#include<iomanip>

extern double dGlobaleZeit;

Fahrrad::Fahrrad() :Fahrzeug()
{
	vInitialisierung();
}

Fahrrad::~Fahrrad()
{

}

Fahrrad::Fahrrad(const Fahrrad& fahrrad) :Fahrzeug(fahrrad.p_sName, fahrrad.p_dMaxGeschwindigkeit)
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



void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(14) << p_dgesVerbrauch;
	cout << setw(14) << p_dTankinhalt;
	cout << resetiosflags(ios::left) << endl;
}

void Fahrrad::vostreamAusgabe(ostream &out)
{
	Fahrzeug::vostreamAusgabe(out);
	cout << setw(14) << p_dgesVerbrauch;
	cout << setw(14) << p_dTankinhalt;
	cout << resetiosflags(ios::left) << endl;
}

void Fahrrad::vAbfertigung()
{
	if (dGlobaleZeit != 0)  
	{
		dGeschwindigkeit();
		Fahrzeug::vAbfertigung();
	}
}

void Fahrrad::vInitialisierung()
{
	p_dVerbrauch = 0.0;
	p_dgesVerbrauch = 0.0;
	p_dTankinhalt = 0.0;
	p_dTankvolumen = 0.0;
}

void Fahrrad::dGeschwindigkeit()
{
	double step = 0.005;
	double abzugkmh = (p_dGesamtStrecke*step)*p_dMaxGeschwindigkeit;
	double neukmh = p_dGeschwindigkeit - abzugkmh;

	if (neukmh<12 && neukmh != 0)
	{
		p_dGeschwindigkeit = 12.0;
	}
	else
	{
		p_dGeschwindigkeit = p_dMaxGeschwindigkeit - abzugkmh;  //pro KM 0,5% abzug von MaxKMH
	}
}