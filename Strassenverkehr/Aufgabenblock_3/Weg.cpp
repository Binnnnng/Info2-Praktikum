#include "stdafx.h"
#include "Weg.h"
#include <list>
#include "Fahrzeug.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"
#include "LazyListe.h"
#include "tmpDataHolder.h"

using namespace std;

Weg::Weg()
{
}

Weg::Weg(string namestr, double length, Begrenzung eLimit, bool ueberholverbot) :AktivesVO(namestr), p_dLength(length), p_eLimit(eLimit), p_bueberholverbot(ueberholverbot)
{
}

Weg::~Weg()
{
}

double Weg::dGetLimit()
{
	return p_eLimit;
}

double Weg::dGetLength()
{
	return p_dLength;
}

bool Weg::br_ueberholverbot()
{
	return p_bueberholverbot;
}

Weg::Begrenzung Weg::nextSpeedLimit(double speed)
{
	if (speed == 1) {
		return Weg::Innerorts;
	}
	else if (speed == 2)
	{
		return Weg::Landstraﬂe;
	}
	else if (speed == 3)
	{
		return Weg::Autobahn;
	}
	else
	{
		throw "ERROR: Wrong Speed Limit!";
	}
}

Weg * Weg::pGetZugehoerigerWeg()
{
	return p_pZugehoerigerWeg;
}

Kreuzung * Weg::pGetZielKreuzung()
{
	return p_pZielKreuzung;
}

void Weg::vSetZugehoerigerWeg(Weg * weg)
{
	p_pZugehoerigerWeg = weg;
}

void Weg::vSetZielKreuzung(Kreuzung * cross)
{
	p_pZielKreuzung = cross;
}

void Weg::vostreamAusgabe(ostream & out)
{
	AktivesVO::vostreamAusgabe(out);
	out.precision(2);
	out << fixed;
	out << resetiosflags(ios::right);
	out << setiosflags(ios::left);
	out << p_dLength;
	out << " (Fahrzeuge: ";
	list<Fahrzeug*>::iterator iterator = p_pFahrzeug.begin();
	while (iterator != p_pFahrzeug.end())
	{
		out << (*iterator)-> returnName() << "|-|";
		iterator++;
	}
	out << ")";
}

void Weg::vAbfertigung()
{
	
	Fahrzeug* tmpData = new tmpDataHolder();
	tmpData->SetAbschnittStrecke(this->p_dLength);
	this->p_lastexecuted = tmpData;

	list<Fahrzeug*>::iterator pFahrzeugIt = p_pFahrzeug.begin();
	while (pFahrzeugIt != p_pFahrzeug.end())
	{
		try
		{
			(*pFahrzeugIt)->vAbfertigung();
			if ((*pFahrzeugIt)->activeObject())
			{
				this->p_lastexecuted = (*pFahrzeugIt);
			}
		}
		catch (FahrAusnahme& Ausnahme)
		{
			Ausnahme.vBearbeiten();
		}

		(*pFahrzeugIt)->vZeichnen(this);
		pFahrzeugIt++;
	}
	p_pFahrzeug.vAktualisieren();
	delete tmpData;
}

void Weg::vAnnahme(Fahrzeug * fahrzeug)
{
	p_pFahrzeug.push_back(fahrzeug);
	fahrzeug->vNeueStrecke(this);
	fahrzeug->vSetVerhalten(new FzgFahren(this));
}

void Weg::vAnnahme(Fahrzeug * fahrzeug, double dStartZeit)
{
	p_pFahrzeug.push_front(fahrzeug);
	fahrzeug->vNeueStrecke(this);
	fahrzeug->vSetVerhalten(new FzgParken(this, dStartZeit));
}

void Weg::vAbgabe(Fahrzeug * fahrzeug)
{
	LazyListe<Fahrzeug*>::iterator it = find(p_pFahrzeug.begin(), p_pFahrzeug.end(), fahrzeug);
	p_pFahrzeug.erase(it);
}
