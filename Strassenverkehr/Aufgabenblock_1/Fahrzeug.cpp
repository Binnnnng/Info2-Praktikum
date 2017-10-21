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

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit != dGlobaleZeit)
	{
		double tDifferenz = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += (p_dGeschwindigkeit * tDifferenz);
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double menge, double inhalt, double tvolumen)  /////////////////////////////////////////////////////////////////////////////////////////
{
	if (menge==-1 && inhalt>0) // Volltanken
	{
		double tanken = menge + inhalt + 1;
		if (tanken<=tvolumen)
		{
			return tanken;
		}
		else
		{
			return 0;
		}
	}
	else if (menge==-2) // Nicht betankbar
	{
		return -2;
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
