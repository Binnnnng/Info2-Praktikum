#pragma once
//#include<string>
#include"AktivesVO.h"

using namespace std;

class Fahrzeug : public AktivesVO
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

private:
	//static int p_iMaxID;
	void vInitialisierung();

protected:
	//int p_iID;
	//string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dGeschwindigkeit;
	double p_dAbschnittStrecke;
	FzgVerhalten *p_pVerhalten;
	Weg *p_pAktuelleStrecke;
};

//ostream& operator <<(ostream& out, Fahrzeug&fahrzeug);