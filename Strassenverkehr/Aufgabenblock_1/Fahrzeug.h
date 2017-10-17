#pragma once
#include<string>

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(string namestr);
	Fahrzeug(string namestr, double MaxGeschwindigkeit);
	virtual ~Fahrzeug();
	void virtual vAusgabe();
	void virtual vAbfertigung();

private:
	int p_iID;
	static int p_iMaxID;
	string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	void vInitialisierung();

};

