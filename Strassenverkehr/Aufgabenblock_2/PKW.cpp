#include"stdafx.h"
#include "PKW.h"
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;
extern double tInkrement;


PKW::PKW()
{
	vInitialisierung();
}


PKW::~PKW()
{
}

PKW::PKW(const PKW& pkw) :Fahrzeug(pkw.p_sName,pkw.p_dMaxGeschwindigkeit)
{
	vInitialisierung();
}

PKW::PKW(string namestr, double MaxGeschwindigkeit, double verbrauch) :Fahrzeug(namestr, MaxGeschwindigkeit)
{
	vInitialisierung();
	p_dVerbrauch = verbrauch;
}

PKW::PKW(string namestr, double MaxGeschwindigkeit, double verbrauch, double volumen) :Fahrzeug(namestr, MaxGeschwindigkeit)
{
	vInitialisierung();
	p_dVerbrauch = verbrauch;
	p_dTankvolumen = volumen;
}

void PKW::vInitialisierung()
{
	p_dVerbrauch = 0.0;
	p_dgesVerbrauch = 0.0;
	p_dTankvolumen = 55.0;
	p_dTankinhalt = p_dTankvolumen/2.0;
}

void PKW::dVerbrauch()
{
	double p_verbauch_kmeter = p_dVerbrauch / 100;
	p_dgesVerbrauch = p_dGesamtStrecke*p_verbauch_kmeter;
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(14) << p_dgesVerbrauch;
	cout << setw(14) << p_dTankinhalt;
	cout << resetiosflags(ios::left) << endl;
}

void PKW::vostreamAusgabe(ostream &out)
{
	Fahrzeug::vostreamAusgabe(out);
	out << setw(14) << p_dgesVerbrauch;
	out << setw(14) << p_dTankinhalt;
	out << resetiosflags(ios::left) << endl;
}



void PKW::vAbfertigung()
{
	if (dGlobaleZeit != 0)
	{
		p_dGeschwindigkeit = p_dMaxGeschwindigkeit;
		double tverbrauch = ((tInkrement*p_dMaxGeschwindigkeit)*p_dVerbrauch / 100);
		if (tverbrauch <= p_dTankinhalt)
		{
			Fahrzeug::vAbfertigung();
			dVerbrauch();
			if (p_dGesamtStrecke > 0)
			{
				p_dTankinhalt -= tverbrauch;
			}
		}
		else if (p_dTankinhalt<tverbrauch && p_dTankinhalt>0)
		{
			p_dTankinhalt = 0;
			p_dTankinhalt = tverbrauch;
			Fahrzeug::vAbfertigung();
			dVerbrauch();
		}
		else if (p_dTankinhalt <= 0)
		{
			p_dTankinhalt = 0;
			p_dGeschwindigkeit = 0;
		}
	}
}

double PKW::dTanken(double menge)
{
	p_dTankinhalt = Fahrzeug::dTanken(menge);
	return 0;
}
