#include "stdafx.h"
#include "FzgParken.h"
#include "Weg.h"
#include "dmath.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

using namespace std;

FzgParken::FzgParken()
{
}

FzgParken::FzgParken(Weg* weg, double dStartZeit) : FzgVerhalten(weg, FzgVerhalten::Parken), p_dStartZeit(dStartZeit)
{
}


FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug* fahrzeug, double zeit)
{
	if (dGlobaleZeit >= p_dStartZeit)
	{
		throw Losfahren(fahrzeug, p_pWeg);
	}
	return 0;
}