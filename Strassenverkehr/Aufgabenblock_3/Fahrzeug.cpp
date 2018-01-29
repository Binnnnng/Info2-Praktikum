#include"stdafx.h"
#include "Fahrzeug.h"
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "Weg.h"

using namespace std;

extern double dGlobaleZeit;

Fahrzeug::Fahrzeug() :AktivesVO()
{
	vInitialisierung();
}

Fahrzeug::~Fahrzeug()
{
}

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug) :AktivesVO(fahrzeug.p_sName)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

Fahrzeug::Fahrzeug(string namestr) :AktivesVO(namestr)
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string namestr, double MaxGeschwindigkeit)  :AktivesVO(namestr)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = MaxGeschwindigkeit;
}

void Fahrzeug::vInitialisierung()
{
	p_dZeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dGeschwindigkeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = NULL;
	p_pAktuelleStrecke = NULL;
}

double Fahrzeug::dGetPos()
{
	double dlength = p_pAktuelleStrecke->dGetLength();
	return p_dAbschnittStrecke / dlength;
}

void Fahrzeug::vAusgabe()
{
	cout.precision(2);
	cout << fixed;
	cout << resetiosflags(ios::right);
	cout << setiosflags(ios::left);
	cout << setw(6) << p_iID ;
	cout << setw(10) << p_sName;
	cout << setw(5) << ":";
	cout << setw(12) << p_dMaxGeschwindigkeit ;
	cout << setw(15) << p_dGesamtStrecke;
	cout << setw(13) << p_dGeschwindigkeit;
	cout << setw(13) << p_dAbschnittStrecke;
}

void Fahrzeug::vostreamAusgabe(ostream &out)
{
	AktivesVO::vostreamAusgabe(out);
	out.precision(2);
	out << fixed;
	out << resetiosflags(ios::right);
	out << setiosflags(ios::left);
	out << setw(12) << p_dMaxGeschwindigkeit;
	out << setw(15) << p_dGesamtStrecke;
	out << setw(13) << p_dGeschwindigkeit;
	out << setw(13) << p_dAbschnittStrecke;
}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit != dGlobaleZeit)
	{
		double tDifferenz = dGlobaleZeit - p_dZeit;
		p_dAbschnittStrecke += p_pVerhalten->dStrecke(this, tDifferenz);
		p_dGesamtStrecke += p_pVerhalten->dStrecke(this, tDifferenz);
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double menge) 
{
	return 0.0;
}

bool Fahrzeug::operator<(const Fahrzeug& comp)
{
	if (p_dGesamtStrecke<comp.p_dGesamtStrecke)
	{
		return true;
	}
	return false;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& cpyfahrzeug)
{
	if (this != &cpyfahrzeug)
	{
		p_dGesamtZeit = cpyfahrzeug.p_dGesamtZeit;
		p_dGesamtStrecke = cpyfahrzeug.p_dGesamtStrecke;
		p_dMaxGeschwindigkeit = cpyfahrzeug.p_dMaxGeschwindigkeit;
		p_dZeit = cpyfahrzeug.p_dZeit;
		p_sName = cpyfahrzeug.p_sName;
		p_dAbschnittStrecke = cpyfahrzeug.p_dAbschnittStrecke;
		p_pVerhalten = cpyfahrzeug.p_pVerhalten;
		p_pAktuelleStrecke = cpyfahrzeug.p_pAktuelleStrecke;
	}
	return *this;
}


void Fahrzeug::vSetVerhalten(FzgVerhalten * Verhalten)
{
	p_pVerhalten = Verhalten;
}

void Fahrzeug::vNeueStrecke(Weg * weg)
{
	p_pAktuelleStrecke = weg;
	delete p_pVerhalten;
	p_pVerhalten = new FzgFahren(weg);
	p_dAbschnittStrecke = 0;
}

double Fahrzeug::dGeschwindigkeit()
{
	Weg * weg = p_pVerhalten->pGetWeg();
	if (weg->dGetLimit() == -1)
	{
		return p_dMaxGeschwindigkeit;
	}
	if (weg->dGetLimit() < p_dMaxGeschwindigkeit)
	{
		return weg->dGetLimit();
	}
	return p_dMaxGeschwindigkeit;
}

void Fahrzeug::vZeichnen(Weg * pWeg)
{
}

double Fahrzeug::dGetAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}

double Fahrzeug::dGetSpeed()
{
	return p_dGeschwindigkeit;
}

void Fahrzeug::SetSpeed(double speed)
{
	p_dMaxGeschwindigkeit = speed;
}

void Fahrzeug::SetAbschnittStrecke(double strecke)
{
	p_dAbschnittStrecke = strecke;
}

bool Fahrzeug::activeObject()
{
	if (this->p_pVerhalten->Vtype == FzgVerhalten::Fahren)
	{
		return true;
	}
	return false;
}

istream & Fahrzeug::istreamInput(istream & in)
{
	AktivesVO::istreamInput(in);
	in >> this->p_dMaxGeschwindigkeit;

	return in;
}