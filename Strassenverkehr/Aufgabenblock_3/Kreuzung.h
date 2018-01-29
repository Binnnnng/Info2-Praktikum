#pragma once
#include "AktivesVO.h"
#include "Weg.h"
#include <list>
#include <string>

using namespace std;

class Fahrzeug;

class Kreuzung : public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string namestr);
	const string type = "Kreuzung";
	virtual ~Kreuzung();
	void vVerbinde(string nameHin, string nameZurueck, double laenge, Kreuzung* toConnectCross,Weg::Begrenzung limit ,bool ueberholverbot);
	void SetTankstelle(double volumen);
	void vTanken(Fahrzeug* tankenFzg);
	void vAnnahme(Fahrzeug* fahrzeug, double);
	void virtual vAbfertigung();
	void vAddLeaving(Weg* weg);
	Weg* randomWeg(Weg*);
	double rtFillLevel();
	istream virtual & istreamInput(istream& in);

private:
	list<Weg*> p_pLeaving;
	double p_dTankstelle;
};

