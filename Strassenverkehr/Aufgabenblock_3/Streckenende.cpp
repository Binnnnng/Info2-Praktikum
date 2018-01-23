#include "Streckenende.h"
#include <iostream>
#include "stdafx.h"
#include "Kreuzung.h"

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
	p_pWeg->pGetZielKreuzung()->vTanken(this->p_pFahrzeug);
	Weg* pNeuerWeg = p_pWeg->pGetZielKreuzung()->randomWeg(this->p_pWeg);
	pNeuerWeg->vAnnahme(this->p_pFahrzeug);
}
