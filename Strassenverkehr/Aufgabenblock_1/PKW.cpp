#include "PKW.h"
#include <iostream>

using namespace std;
extern double dGlobaleZeit;


PKW::PKW() :Fahrzeug()
{
	vPKWInitialisierung();
}


PKW::~PKW()
{
}

void PKW::vPKWInitialisierung()
{
	double p_dVerbrauch=0.0;
	double p_dTankinhalt=27.5;
	double p_dTankvolumen=55.0;
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

}

void PKW::dTanken(double menge)
{

}