#include "Losfahren.h"
#include <iostream>
#include "stdafx.h"

using namespace std;


Losfahren::Losfahren()
{
}

Losfahren::Losfahren(Fahrzeug * pFahrzeug, Weg * pWeg) : FahrAusnahme(pFahrzeug, pWeg)
{
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << "-------------------------------------------- Losfahren ---------------------------------------------" << endl;
	createtable();
	cout << *p_pFahrzeug << endl;
	cout << *p_pWeg << endl << endl << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
	p_pWeg->vAnnahme(p_pFahrzeug);
}