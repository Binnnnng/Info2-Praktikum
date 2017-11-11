#pragma once
#include"AktivesVO.h"
#include"LazyListe.h"

using namespace std;

class Weg : public AktivesVO
{
public:
	enum Begrenzung{Innerorts = 50, Landstraﬂe = 100, Autobahn = -1};
	Weg();
	Weg(string namestr, double length, Begrenzung eLimit);
	void virtual vostreamAusgabe(ostream& out);
	void virtual vAbfertigung();
	virtual ~Weg();
	

private:
	double p_dLength;
	double p_eLimt;
	LazyListe<Fahrzeug*> p_pFahrzeug;
};

