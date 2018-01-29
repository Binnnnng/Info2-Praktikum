#pragma once
#include"AktivesVO.h"
#include<list>
#include"LazyListe.h"

using namespace std;

class Fahrzeug;
class Kreuzung;

class Weg : public AktivesVO
{
public:
	enum Begrenzung{Innerorts = 50, Landstraﬂe = 100, Autobahn = -1};
	Weg();
	Weg(string namestr, double length, Begrenzung eLimit, bool ueberholverbot = true);
	void virtual vostreamAusgabe(ostream& out);
	void virtual vAbfertigung();
	void vAnnahme(Fahrzeug* fahrzeug);
	void vAnnahme(Fahrzeug* fahrzeug, double dStartZeit);
	void vAbgabe (Fahrzeug* fahrzeug);
	virtual ~Weg();
	double dGetLimit();
	double dGetLength();
	bool br_ueberholverbot();
	Fahrzeug* p_lastexecuted;
	static Weg::Begrenzung nextSpeedLimit(double);
	Weg* pGetZugehoerigerWeg();
	Kreuzung* pGetZielKreuzung();
	void vSetZugehoerigerWeg(Weg* weg);
	void vSetZielKreuzung(Kreuzung* cross);
	const string type = "Weg";

private:
	double p_dLength;
	double p_eLimit;
	bool p_bueberholverbot = true;
	LazyListe<Fahrzeug*> p_pFahrzeug;
	Weg* p_pZugehoerigerWeg;
	Kreuzung* p_pZielKreuzung;
};

