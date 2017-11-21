#include "stdafx.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"

FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg) :p_pWeg(weg)
{
}


FzgVerhalten::~FzgVerhalten()
{
}

double FzgVerhalten::dStrecke(Fahrzeug * , double zeit)
{
	return  Fahrzeug::p_dGeschwindigkeit * zeit;
}

Weg * FzgVerhalten::pGetWeg()
{
	return p_pWeg;
}
