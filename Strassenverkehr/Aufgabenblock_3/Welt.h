#pragma once
#include <iostream>
#include "AktivesVO.h"
#include <list>
#include <map>
#include "Kreuzung.h"


class Welt
{
public:
	Welt();
	virtual ~Welt();
	static const string KREUZUNGSTAG;
	static const string STRASSENTAG;
	static const string PKWTAG;
	static const string FAHRRADTAG;
	void vSimulieren();
	void vEinlesenMitGrafik(ifstream& in);
	void vEinlesen(ifstream& in);
private:
	list<Kreuzung*> listCross;
	void vParseIfstream(ifstream& ifstreamConfig);
};

