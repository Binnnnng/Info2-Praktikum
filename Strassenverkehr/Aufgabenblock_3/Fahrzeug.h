#pragma once
#include<string>
#include"AktivesVO.h"
#include "Weg.h"
#include "FzgVerhalten.h"
#include "FzgFahren.h"

using namespace std;

class Fahrzeug :public AktivesVO
{
public:
	Fahrzeug();
	Fahrzeug(string namestr);
	Fahrzeug(string namestr, double MaxGeschwindigkeit);
	Fahrzeug(const Fahrzeug& fahrzeug);
	virtual ~Fahrzeug();
	void virtual vostreamAusgabe(ostream &out);
	void virtual vAusgabe();
	void virtual vAbfertigung();
	double virtual dTanken(double menge);
	bool operator<(const Fahrzeug& comp);
	Fahrzeug& operator=(const Fahrzeug& cpyfahrzeug);
	void vSetVerhalten(FzgVerhalten* pVerhalten);
	void vNeueStrecke(Weg * weg);
	double virtual dGeschwindigkeit();
	void virtual vZeichnen(Weg* pWeg);
	double dGetAbschnittStrecke();

private:
	void vInitialisierung();

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dGeschwindigkeit;
	double p_dAbschnittStrecke;
	FzgVerhalten *p_pVerhalten;
	Weg *p_pAktuelleStrecke;
	double dGetPos();
};
