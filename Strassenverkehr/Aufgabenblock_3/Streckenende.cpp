#include "Streckenende.h"
#include <iostream>
#include "stdafx.h"
#include "Kreuzung.h"

using namespace std;
extern double dGlobaleZeit;

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
	Weg* pNeuerWeg = p_pWeg->pGetZielKreuzung()->ptZufaelligerWeg(this->p_pWeg);
	pNeuerWeg->vAnnahme(this->p_pFahrzeug);
	cout << "ZEIT     :" << dGlobaleZeit << endl;
	cout << "KREUZUNG :" << p_pWeg->pGetZielKreuzung()->returnName()<<"   "<< p_pWeg->pGetZielKreuzung()->rtFillLevel() << endl;
	cout << "WECHSEL  :" << p_pWeg->returnName() <<"-->"<< pNeuerWeg->returnName() << endl;
	cout << "FAHRZEUG :" << *p_pFahrzeug << endl;
}
