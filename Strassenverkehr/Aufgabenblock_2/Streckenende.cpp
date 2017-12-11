#include "Streckenende.h"
#include <iostream>
#include "stdafx.h"

using namespace std;


Streckenende::Streckenende()
{
}

Streckenende::Streckenende(Fahrzeug * pFahrzeug, Weg * pWeg) : FahrAusnahme(pFahrzeug, pWeg)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << "------------------------------------------ Streckenende --------------------------------------------" << endl;
	createtable();
	cout << *p_pFahrzeug << endl;
	cout << *p_pWeg << endl << endl << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
}
