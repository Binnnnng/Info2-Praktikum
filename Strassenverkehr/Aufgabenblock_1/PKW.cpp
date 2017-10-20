#include "PKW.h"
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;
extern double tInkrement;

PKW::PKW() :Fahrzeug()
{
	vPKWInitialisierung();
}


PKW::~PKW()
{
}

void PKW::vPKWInitialisierung()
{
	p_dVerbrauch=0.0;
	p_dgesVerbrauch = 0.0;
	p_dTankinhalt=27.5;
	p_dTankvolumen=55.0;
}

PKW::PKW(string namestr, double MaxGeschwindigkeit, double verbrauch) :Fahrzeug(namestr, MaxGeschwindigkeit)
{
	vPKWInitialisierung();
	p_dVerbrauch = verbrauch;
}

PKW::PKW(string namestr, double MaxGeschwindigkeit, double verbrauch, double volumen) :Fahrzeug(namestr, MaxGeschwindigkeit)
{
	vPKWInitialisierung();
	p_dVerbrauch = verbrauch;
	p_dTankvolumen = volumen;
}

void PKW::dVerbrauch()
{
	double p_verbauch_kmeter = p_dVerbrauch / 100;
	p_dgesVerbrauch = p_dGesamtStrecke*p_verbauch_kmeter;
}

void PKW::vPKWAusgabe()
{
	vAusgabe();
	cout << setw(14) << p_dgesVerbrauch;
	cout << setw(14) << p_dTankinhalt << endl;
	cout << resetiosflags(ios::left);
}

void PKW::vPKWAbfertigung()
{
	double tverbrauch = ((tInkrement*p_dMaxGeschwindigkeit)*p_dVerbrauch / 100);
	if (tverbrauch<=p_dTankinhalt)
	{
		vAbfertigung();
		dVerbrauch();
		if (p_dGesamtStrecke > 0)
		{
			p_dTankinhalt -= tverbrauch;
		}
	}
	else if (p_dTankinhalt<tverbrauch && p_dTankinhalt>0)
	{
		p_dTankinhalt = tverbrauch;
		vAbfertigung();
		dVerbrauch();	
	}
	else if (p_dTankinhalt<=0)
	{
		p_dTankinhalt = 0;
		p_dTankinhalt=dTanken(p_dTankvolumen-p_dTankinhalt,p_dTankinhalt,p_dTankvolumen);

	}
}