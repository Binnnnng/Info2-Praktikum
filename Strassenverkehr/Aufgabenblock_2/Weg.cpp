#include "stdafx.h"
#include "Weg.h"
#include <list>
#include "Fahrzeug.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"
#include "LazyListe.h"

using namespace std;

Weg::Weg()
{
}

Weg::Weg(string namestr, double length, Begrenzung eLimit) :AktivesVO(namestr), p_dLength(length), p_eLimit(eLimit)
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

void Weg::vostreamAusgabe(ostream & out)
{
	AktivesVO::vostreamAusgabe(out);
	out.precision(2);
	out << fixed;
	out << resetiosflags(ios::right);
	out << setiosflags(ios::left);
	out << p_dLength;
	out << " ( ";
	list<Fahrzeug*>::iterator iterator = p_pFahrzeug.begin();
	while (iterator != p_pFahrzeug.end())
	{
		out << (*iterator)-> returnName() << " ";
		iterator++;
	}
	out << ")";
}

void Weg::vAbfertigung()
{
	list<Fahrzeug*>::iterator pFahrzeugIt = p_pFahrzeug.begin();
	while (pFahrzeugIt != p_pFahrzeug.end())
	{
		try
		{
			(*pFahrzeugIt)->vAbfertigung();
		}
		catch (FahrAusnahme& exception)
		{
			exception.vBearbeiten();
		}

		(*pFahrzeugIt)->vZeichnen(this);
		pFahrzeugIt++;
	}
	p_pFahrzeug.vAktualisieren();
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
