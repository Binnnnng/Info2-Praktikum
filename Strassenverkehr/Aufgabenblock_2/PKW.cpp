#include"stdafx.h"
#include "Pkw.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "SimuClient.h"
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
	if (dGlobaleZeit != 0 && p_dZeit != dGlobaleZeit)
	{
		double d_diff = dGlobaleZeit - p_dZeit;
		double d_teil = p_pVerhalten->dStrecke(this, d_diff);
		double tverbrauch = (p_dVerbrauch/100)* d_teil;
		if (tverbrauch <= p_dTankinhalt)
		{
			dVerbrauch();
			if (p_dGesamtStrecke > 0)
			{
				p_dTankinhalt -= tverbrauch;
			}
			p_dGesamtStrecke += d_teil;
			p_dAbschnittStrecke += d_teil;
			p_dZeit = dGlobaleZeit;
		}
		else if (p_dTankinhalt<tverbrauch && p_dTankinhalt>0)
		{
			p_dTankinhalt = 0;
			p_dTankinhalt = tverbrauch;
			dVerbrauch();
			p_dGesamtStrecke += d_teil;
			p_dAbschnittStrecke += d_teil;
			p_dZeit = dGlobaleZeit;
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

PKW & PKW::operator=(const PKW & cpypkw)
{
	if (this != &cpypkw) {
		p_dGesamtZeit = cpypkw.p_dGesamtZeit;
		p_dGesamtStrecke = cpypkw.p_dGesamtStrecke;
		p_dMaxGeschwindigkeit = cpypkw.p_dMaxGeschwindigkeit;
		p_dZeit = cpypkw.p_dZeit;
		p_sName = cpypkw.p_sName;
		p_dTankinhalt = cpypkw.p_dTankinhalt;
		p_dTankvolumen = cpypkw.p_dTankvolumen;
		p_dgesVerbrauch = cpypkw.p_dgesVerbrauch;
		p_dTankinhalt = cpypkw.p_dTankinhalt;
		p_dTankvolumen = cpypkw.p_dTankvolumen;
		p_dVerbrauch = cpypkw.p_dVerbrauch;
		p_dAbschnittStrecke = cpypkw.p_dAbschnittStrecke;
		p_pVerhalten = cpypkw.p_pVerhalten;
		p_pAktuelleStrecke = cpypkw.p_pAktuelleStrecke;
	}
	return *this;
}

void PKW::vZeichnen(Weg * pWeg)
{
	bZeichnePKW(p_sName, pWeg->returnName(),dGetPos(), dGeschwindigkeit(), p_dTankinhalt);
}
