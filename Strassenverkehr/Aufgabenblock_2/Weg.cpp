#include "stdafx.h"
#include "Weg.h"
#include"Fahrzeug.h"
#include "FzgParken.h"

using namespace std;

Weg::Weg()
{
}

Weg::Weg(string namestr, double length, Begrenzung eLimit) :AktivesVO(namestr), p_dLength(length), p_eLimt(eLimit)
{
}

Weg::~Weg()
{
}

double Weg::dGetLimit()
{
	return p_eLimt;
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
	list<Fahrzeug*>::iterator iterator = p_pFahrzeug.begin();
	while (iterator != p_pFahrzeug.end()) {
		(*iterator)->vAbfertigung();
		(*iterator)->vAusgabe();
		iterator++;
	}
}

void Weg::vAnnahme(Fahrzeug * fahrzeug)
{
	p_pFahrzeug.push_back(fahrzeug);
}

void Weg::vAnnahme(Fahrzeug * fahrzeug, double dStartZeit)
{
}

void Weg::vAbgabe(Fahrzeug * fahrzeug)
{
}
