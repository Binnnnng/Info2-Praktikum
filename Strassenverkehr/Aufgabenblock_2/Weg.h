#pragma once
#include"AktivesVO.h"
#include<list>
#include"LazyListe.h"

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
	void vAnnahme(Fahrzeug* fahrzeug);
	void vAnnahme(Fahrzeug* fahrzeug, double dStartZeit);
	void vAbgabe (Fahrzeug* fahrzeug);
	virtual ~Weg();
	double dGetLimit();
	double dGetLength();

private:
	double p_dLength;
	double p_eLimit;
	LazyListe<Fahrzeug*> p_pFahrzeug;
};

