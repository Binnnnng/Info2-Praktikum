#include "PKW.h"
#include <iostream>
#include <iomanip>

using namespace std;
extern double dGlobaleZeit;
extern double tInkrement;
extern string klasse;

PKW::PKW() :Fahrzeug()
{
	vInitialisierung();
}


PKW::~PKW()
{
}

void PKW::vInitialisierung()
{
	p_dVerbrauch=0.0;
	p_dgesVerbrauch = 0.0;
	p_dTankinhalt=27.5;
	p_dTankvolumen=55.0;
	klasse = "pkw";
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

void PKW::vAbfertigung()
{
	double tverbrauch = ((tInkrement*p_dMaxGeschwindigkeit)*p_dVerbrauch / 100);
	if (tverbrauch<=p_dTankinhalt)
	{
		dGeschwindigkeit(klasse);
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
		dGeschwindigkeit(klasse);
		Fahrzeug::vAbfertigung();
		dVerbrauch();	
	}
	else if (p_dTankinhalt<=0)
	{
		p_dTankinhalt = 0;
		p_dGeschwindigkeit = 0;
		p_dTankinhalt=dTanken(p_dTankvolumen-p_dTankinhalt,p_dTankinhalt,p_dTankvolumen);

	}
}
