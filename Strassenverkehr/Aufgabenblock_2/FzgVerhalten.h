#pragma once

class Fahrzeug;
class Weg;

class FzgVerhalten
{
public:
	FzgVerhalten();
	FzgVerhalten(Weg* weg);
	~FzgVerhalten();
	Weg* pGetWeg();
	double virtual dStrecke(Fahrzeug* , double zeit);
protected:
	Weg* p_pWeg;
};

