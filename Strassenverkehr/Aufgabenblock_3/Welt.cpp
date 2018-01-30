#include "Welt.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "Pkw.h"
#include "Fahrrad.h"
#include <iostream> 
#include <fstream> 
#include <strstream> 
#include <list>
#include "ExceptionHandler.h"
#include "SimuClient.h"
#include <vector>

const string Welt::KREUZUNGSKEY = "KREUZUNG";
const string Welt::STRASSENKEY = "STRASSE";
const string Welt::PKWKEY = "PKW";
const string Welt::FAHRRADKEY = "FAHRRAD";

Welt::Welt()
{
}


Welt::~Welt()
{
}

void Welt::vSimulieren()
{
	list<Kreuzung*>::iterator it;
	for (it = listCross.begin(); it != listCross.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

void Welt::vEinlesenMitGrafik(ifstream & in)
{
	try
	{
		this->vParseIfstream(in);
	}
	catch (string exceptStr)
	{
		cout << exceptStr <<endl;
	}
}


void Welt::vParseIfstream(ifstream & ifstreamConfig)
{
	list<AktivesVO*> listObjekte;

	string sObjektType;
	ifstreamConfig >> sObjektType;
	while (!ifstreamConfig.eof())
	{
		if (sObjektType == Welt::KREUZUNGSKEY)
		{
			Kreuzung* pnewCross = new Kreuzung();
			ifstreamConfig >> *pnewCross;
			int x;
			int y;

			ifstreamConfig >> x;
			ifstreamConfig >> y;
			AktivesVO::vAddPtObject(pnewCross);
			this->listCross.push_back(pnewCross);

			bZeichneKreuzung(x, y);
		}
		else if (sObjektType == Welt::STRASSENKEY)
		{
			string sNameQ;
			string sNameZ;
			string sNameW1;
			string sNameW2;
			double dLaenge;
			double dGeschw;
			int iUeberholverbot;
			bool bUeberholverbot;
			int iAnzahlkoords;
			ifstreamConfig >> sNameQ;
			ifstreamConfig >> sNameZ;
			ifstreamConfig >> sNameW1;
			ifstreamConfig >> sNameW2;
			ifstreamConfig >> dLaenge;
			ifstreamConfig >> dGeschw;
			ifstreamConfig >> iUeberholverbot;
			if (iUeberholverbot != 0 && iUeberholverbot != 1)
			{
				ExceptionHandler(2,"Is not boolean" +to_string(iUeberholverbot));
			}
			bUeberholverbot = (bool)iUeberholverbot;
			ifstreamConfig >> iAnzahlkoords;

			vector<int> pKoords;
			for (int i = 0; i < iAnzahlkoords; i++)
			{
				int x;
				int y;
				ifstreamConfig >> x;
				ifstreamConfig >> y;
				pKoords.push_back(x);
				pKoords.push_back(y);
			}

			Kreuzung* kr1 = (Kreuzung*)AktivesVO::ptObject(sNameQ);
			Kreuzung* kr2 = (Kreuzung*)AktivesVO::ptObject(sNameZ);
			if (kr2->type == "Kreuzung" && kr1->type == "Kreuzung") {
				kr1->vVerbinde(sNameW1, sNameW2, dLaenge, kr2, Weg::nextSpeedLimit(dGeschw), bUeberholverbot);
				cout << "Strasse " << sNameQ << endl;
			}
			else
			{
				ExceptionHandler(2,sNameZ + " or " + sNameQ + " is no Crossing");
			}

			bZeichneStrasse(sNameW1, sNameW2, dLaenge, iAnzahlkoords, &pKoords[0]);
		}
		else if (sObjektType == Welt::PKWKEY)
		{
			PKW* pNewPkw = new PKW();
			ifstreamConfig >> *pNewPkw;
			string sName;
			double dStart;
			ifstreamConfig >> sName;
			ifstreamConfig >> dStart;
			AktivesVO::vAddPtObject(pNewPkw);
			Kreuzung* kr = (Kreuzung*)AktivesVO::ptObject(sName);
			kr->vAnnahme(pNewPkw, dStart);
		}
		else if (sObjektType == Welt::FAHRRADKEY)
		{
			Fahrrad* pNewBike = new Fahrrad();
			ifstreamConfig >> *pNewBike;
			string sName;
			double dStart;
			ifstreamConfig >> sName;
			ifstreamConfig >> dStart;
			AktivesVO::vAddPtObject(pNewBike);
			Kreuzung* kr = (Kreuzung*)AktivesVO::ptObject(sName);
			kr->vAnnahme(pNewBike, dStart);
		}
		else
		{
			ExceptionHandler(2,sObjektType);
		}
		ifstreamConfig >> sObjektType; //input next Object to create
	}
}
