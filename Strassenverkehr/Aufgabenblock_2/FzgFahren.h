#pragma once
#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren();
	FzgFahren(Weg* weg);
	~FzgFahren();

	double virtual dStrecke(Fahrzeug*, double zeit);
};

