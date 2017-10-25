#pragma once
#include<string>

using namespace std;

class Fahrzeug 
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
	void virtual dGeschwindigkeit(string klasse);
	double virtual dTanken(double menge);
	bool operator<(const Fahrzeug& comp);
	Fahrzeug& operator=(const Fahrzeug& cpyfahrzeug);

private:
	static int p_iMaxID;

protected:
	int p_iID;
	string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dGeschwindigkeit;
	void vInitialisierung();
};

ostream& operator <<(ostream& out, Fahrzeug&x);