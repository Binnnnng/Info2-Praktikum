#pragma once
#include"AktivesVO.h"
#include<list>

//#include"LazyListe.h"

using namespace std;

class Fahrzeug;

class Weg : public AktivesVO
{
public:
	enum Begrenzung{Innerorts = 50, Landstraﬂe = 100, Autobahn = -1};
	Weg();
	Weg(string namestr, double length, Begrenzung eLimit);
	void virtual vostreamAusgabe(ostream& out);
	void virtual vAbfertigung();
	void vAnnehmen(Fahrzeug* fahrzeug);
	void vAnnehmen(Fahrzeug * fahrzeug, double dStartZeit);
	void vAbgeben(Fahrzeug* fahrzeug);
	virtual ~Weg();
	double dGetLimit();

private:
	double p_dLength;
	double p_eLimt;
	list<Fahrzeug*> p_pFahrzeug;
};

