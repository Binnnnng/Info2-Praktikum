#include "stdafx.h"
#include "FzgFahren.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "dmath.h"
#include "Streckenende.h"

using namespace std;

FzgFahren::FzgFahren()
{
}

FzgFahren::FzgFahren(Weg * weg) : FzgVerhalten(weg)
{
}


FzgFahren::~FzgFahren()
{
}

double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double zeit)
{
	double dIntStrecke = fahrzeug->dGeschwindigkeit() * zeit;
	double dWegPlatz = p_pWeg->dGetLength() - fahrzeug->dGetAbschnittStrecke();

	if (dmath::nearly_equal(dWegPlatz, 0))
	{
		throw Streckenende(fahrzeug, p_pWeg);
	}

	if (dWegPlatz < dIntStrecke)
	{
		return dWegPlatz;
	}
	return dIntStrecke;
}
