#include "Kreuzung.h"
#include "Weg.h"
#include <list>
#include "Fahrzeug.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Kreuzung::Kreuzung()
{
}


Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(string nameHin, string nameZurueck, double laenge, Kreuzung * toConnectCross, Weg::Begrenzung limit, bool ueberholverbot)
{
	Weg* weg_hin = new Weg(nameHin, laenge, limit, ueberholverbot);
	Weg* weg_zurueck = new Weg(nameZurueck, laenge, limit, ueberholverbot);
	weg_hin->vSetZugehoerigerWeg(weg_zurueck);
	weg_zurueck->vSetZugehoerigerWeg(weg_hin);
	weg_hin->vSetZielKreuzung(toConnectCross);
	weg_zurueck->vSetZielKreuzung(this);

	this->p_pLeaving.push_back(weg_hin);
	toConnectCross->vAddLeaving(weg_zurueck);
}

void Kreuzung::SetTankstelle(double volumen)
{
	p_dTankstelle = volumen;
}

void Kreuzung::vTanken(Fahrzeug * tankenFzg)
{
	if (p_dTankstelle <=0)
	{
		return;
	}
	double AbzugVolumen = tankenFzg->dTanken();
	p_dTankstelle -= AbzugVolumen;
}

void Kreuzung::vAnnahme (Fahrzeug* fahrzeug, double zeit)
{
	this->vTanken(fahrzeug);
	Weg *weg = this->p_pLeaving.front();
	weg->vAnnahme(fahrzeug, zeit);
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator WegIT;
	for (WegIT=p_pLeaving.begin();WegIT!=p_pLeaving.end(); WegIT++)
	{
		(*WegIT)->vAbfertigung();
	}
}

void Kreuzung::vAddLeaving(Weg * weg)
{
	p_pLeaving.push_back(weg);
}

Weg * Kreuzung::randomWeg(Weg * WegHin)
{
	srand(time(NULL));

	int Anzahl = p_pLeaving.size();
	Weg* weg;

	if (Anzahl == 1)
	{
		list<Weg*>::iterator WegIT = p_pLeaving.begin();
		weg = (*WegIT);
		return weg;
	}
	do
	{
		int Number = rand() % Anzahl;
		list<Weg*>::iterator WegIT = p_pLeaving.begin();
		advance(WegIT, Number);
		weg = (*WegIT);
	} while (weg == WegHin || WegHin->pGetZugehoerigerWeg() == weg);

	return weg;
}
