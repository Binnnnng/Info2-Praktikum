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
	static const string Welt::KREUZUNGSKEY;
	static const string Welt::STRASSENKEY;
	static const string Welt::PKWKEY;
	static const string Welt::FAHRRADKEY;
	void vSimulieren();
	void vEinlesenMitGrafik(ifstream& in);
private:
	list<Kreuzung*> listCross;
	void vParseIfstream(ifstream& ifstreamConfig);
};

