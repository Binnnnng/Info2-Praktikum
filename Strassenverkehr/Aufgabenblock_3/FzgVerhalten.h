#pragma once

class Fahrzeug;
class Weg;

class FzgVerhalten
{
public:
	enum type { Fahren = 1, Parken = 2 };
	FzgVerhalten();
	FzgVerhalten(Weg* weg, int Vtype);
	~FzgVerhalten();
	Weg* pGetWeg();
	double virtual dStrecke(Fahrzeug* , double zeit)=0;
	int Vtype;

protected:
	Weg* p_pWeg;
	
};

