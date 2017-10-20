#include "Fahrzeug.h"
#include<iostream>
#include<iomanip>

using namespace std;

int Fahrzeug::p_iMaxID = 1;
extern double dGlobaleZeit;

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
	cout << setw(16) << p_dGesamtStrecke;
}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit != dGlobaleZeit)
	{
		double tDifferenz = dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += (p_dMaxGeschwindigkeit * tDifferenz);
		p_dZeit = dGlobaleZeit;
	}

}

double Fahrzeug::dTanken(double menge, double inhalt, double tvolumen)
{
	if (menge==-1 && inhalt>0) // Volltanken
	{
		double tanken = menge + inhalt;
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
