#include "Fahrzeug.h"
#include<iostream>
#include<iomanip>

using namespace std;

int Fahrzeug::p_iMaxID = 1;

Fahrzeug::Fahrzeug()
{
	vInitialisierung();
	//cout << "Standard Constructor called" << endl;
	//cout <<p_sName <<"   "<<p_iID<< endl;
}


Fahrzeug::~Fahrzeug()
{
	vInitialisierung();
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
	cout << p_iID;
	cout.width(10);
	cout << p_sName;
	cout.width(10);
	cout << ":";
	cout.width(10);
	cout << p_dMaxGeschwindigkeit;
	cout.width(10);
	cout << p_dGesamtStrecke << endl;
}