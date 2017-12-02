#include"stdafx.h"
#include "Fahrzeug.h"
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "Weg.h"

using namespace std;

//int Fahrzeug::p_iMaxID = 1;
extern double dGlobaleZeit;

Fahrzeug::Fahrzeug() :AktivesVO()
{
	vInitialisierung();
	//cout << "Standard Constructor called" << endl;
	//cout <<p_sName <<"   "<<p_iID<< endl;
}

Fahrzeug::~Fahrzeug()
{
	//cout << "Destructor called" << endl;
	//cout <<p_sName<< "   " <<p_iID<< endl;
}

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug) :AktivesVO(fahrzeug.p_sName)
{
	vInitialisierung();
	//p_sName = fahrzeug.p_sName;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

Fahrzeug::Fahrzeug(string namestr) :AktivesVO(namestr)
{
	vInitialisierung();
	//p_sName = namestr;
	//cout << "Non-Standard Constructor called" << endl;
	//cout <<namestr<< "   " <<p_iID<< endl;
}

Fahrzeug::Fahrzeug(string namestr, double MaxGeschwindigkeit)  :AktivesVO(namestr)
{
	vInitialisierung();
	//p_sName = namestr;
	p_dMaxGeschwindigkeit = MaxGeschwindigkeit;
	//cout << "Non-Standard Constructor called" << endl;
	//cout << namestr << "   " << p_iID << "   " << p_dMaxGeschwindigkeit << endl;
}

void Fahrzeug::vInitialisierung()
{
	/*
	p_sName = "";
	p_iID = p_iMaxID;
	p_iMaxID++;
	*/
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
	//out << setw(6) << p_iID;
	//out << setw(10) << p_sName;
	//out << setw(5) << ":";
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
		p_dGesamtStrecke += (p_dGeschwindigkeit * tDifferenz);
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double menge) 
{
	if (menge<0)
	{
		return 55.0;
	}
	else
	{
		return menge;
	}
}
/*
ostream& operator<<(ostream& out, Fahrzeug& fahrzeug)
{
	fahrzeug.vostreamAusgabe(out);
	return out;
}
*/
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
		//p_iID = cpyfahrzeug.p_iID;
		p_dAbschnittStrecke = cpyfahrzeug.p_dAbschnittStrecke;
		p_pVerhalten = cpyfahrzeug.p_pVerhalten;
		p_pAktuelleStrecke = cpyfahrzeug.p_pAktuelleStrecke;
	}
	return *this;
}


void Fahrzeug::vSetVerhalten(FzgVerhalten * pVerhalten)
{
	p_pVerhalten = pVerhalten;
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
	if (weg->dGetLimit() == -1) // NULL Pointer
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
