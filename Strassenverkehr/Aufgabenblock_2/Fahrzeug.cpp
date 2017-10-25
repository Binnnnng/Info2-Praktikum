#include "Fahrzeug.h"
#include<iostream>
#include<iomanip>

using namespace std;

int Fahrzeug::p_iMaxID = 1;
extern double dGlobaleZeit;
string klasse;

Fahrzeug::Fahrzeug()
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

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug)
{
	vInitialisierung();
	p_sName = fahrzeug.p_sName;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}

Fahrzeug::Fahrzeug(string namestr)
{
	vInitialisierung();
	p_sName = namestr;
	//cout << "Non-Standard Constructor called" << endl;
	//cout <<namestr<< "   " <<p_iID<< endl;
}

Fahrzeug::Fahrzeug(string namestr, double MaxGeschwindigkeit) 
{
	vInitialisierung();
	p_sName = namestr;
	p_dMaxGeschwindigkeit = MaxGeschwindigkeit;
	//cout << "Non-Standard Constructor called" << endl;
	//cout << namestr << "   " << p_iID << "   " << p_dMaxGeschwindigkeit << endl;
}

void Fahrzeug::vInitialisierung()
{
	p_sName = "";
	p_iID = p_iMaxID;
	p_iMaxID++;
	p_dZeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dGeschwindigkeit = 0;
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
}

void Fahrzeug::vostreamAusgabe(ostream &out)
{
	cout.precision(2);
	cout << fixed;
	cout << resetiosflags(ios::right);
	cout << setiosflags(ios::left);
	cout << setw(6) << p_iID;
	cout << setw(10) << p_sName;
	cout << setw(5) << ":";
	cout << setw(12) << p_dMaxGeschwindigkeit;
	cout << setw(15) << p_dGesamtStrecke;
	cout << setw(13) << p_dGeschwindigkeit;
}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit != dGlobaleZeit)
	{
		double tDifferenz = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += (p_dGeschwindigkeit * tDifferenz);
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double menge)
{
	if (menge==-1) // Volltanken
	{
		return 55.0;
	}
	else if (menge==-2)
	{
		return 0.0;
	}
	else // menge tanken
	{
		return menge;
	}
}

void Fahrzeug::dGeschwindigkeit(string klasse)
{
	if (p_dGesamtStrecke == 0 && dGlobaleZeit == 0)
	{
		p_dGeschwindigkeit = 0;
		return;
	}
	if (klasse=="pkw")
	{

		p_dGeschwindigkeit = p_dMaxGeschwindigkeit;
	}
	else if (klasse=="fahrrad")
	{
		double step = 0.005;
		double abzugkmh = (p_dGesamtStrecke*step)*p_dMaxGeschwindigkeit;
		double neukmh = p_dGeschwindigkeit - abzugkmh;
		if (neukmh<12 && neukmh != 0)
		{
			p_dGeschwindigkeit = 12;
		}
		else
		{
			p_dGeschwindigkeit = p_dMaxGeschwindigkeit - abzugkmh;  //pro KM 0,5% abzug von MaxKMH
		}
	}
	else
	{
		p_dGeschwindigkeit = p_dMaxGeschwindigkeit;
	}
}

ostream& operator<<(ostream& out, Fahrzeug& fahrzeug)
{
	fahrzeug.vostreamAusgabe(out);
	return out;
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
	}
	return *this;
}
