#include "stdafx.h"
#include "FahrAusnahme.h"
#include <iostream>
#include<iomanip>

extern double dGlobaleZeit;
using namespace std;

FahrAusnahme::FahrAusnahme()
{
}

FahrAusnahme::FahrAusnahme(Fahrzeug * pFahrzeug, Weg * pWeg) : p_pFahrzeug(pFahrzeug), p_pWeg(pWeg)
{
}


FahrAusnahme::~FahrAusnahme()
{
}

void FahrAusnahme::vBearbeiten()
{
	/*
	cout << "-------------------------------------------- Exception ----------------------------------------------" << endl;
	createtable();
	cout << *p_pFahrzeug << endl;
	cout << *p_pWeg << endl;
	*/
}

void FahrAusnahme::createtable()
{
	cout <<"Simulation Time:"<< dGlobaleZeit << endl << endl;
	cout << resetiosflags(ios::right);
	cout << setiosflags(ios::left);
	cout << setw(6) << "ID#";
	cout << setw(10) << "Name";
	cout << setw(4) << ":";
	cout << setw(10) << "MaxKmh";
	cout << setw(18) << "GesamtStrecke";
	cout << setw(10) << "Km/h";
	cout << setw(13) << "Abschnitt";
	cout << setw(15) << "GesVerbrauch";
	cout << setw(15) << "Tankinhalt" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
