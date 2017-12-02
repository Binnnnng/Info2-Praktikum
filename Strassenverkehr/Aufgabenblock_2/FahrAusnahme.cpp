#include "stdafx.h"
#include "FahrAusnahme.h"
#include <iostream>

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
	cout << "FahrAusnahme ++++++++++++++++++++++++++++++++++++++" << endl;
	cout << *p_pFahrzeug << endl;
	cout << *p_pWeg << endl;
}
