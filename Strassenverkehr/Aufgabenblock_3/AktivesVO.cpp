#include "stdafx.h"
#include"AktivesVO.h"
#include <iostream>
#include <list>
#include <map>
#include <string>
#include "ExceptionHandler.h"

using namespace std;
map <string, AktivesVO*> AktivesVO::mapAllObjects;
extern double dGlobaleZeit;
int AktivesVO::p_iMaxID = 1;

AktivesVO::AktivesVO() : p_sName(""), lokaleZeit(0)
{
	vInitialization();
}

AktivesVO::AktivesVO(string namestr) : p_sName(namestr), lokaleZeit(0)
{
	vInitialization();
}

istream & AktivesVO::istreamInput(istream & in)
{
	if (this->p_sName != "")
	{
		ExceptionHandler(3,"Only empty Objects can be filled");
	}
	in >> this->p_sName;
	return in;
}

AktivesVO * AktivesVO::ptObject(string sName)
{
	if (AktivesVO::NameValidation(sName))
	{
		return AktivesVO::mapAllObjects[sName];
	}
	else
	{
		ExceptionHandler(1,sName + "is not existing");
	}
}

void AktivesVO::vAddPtObject(AktivesVO * Object)
{
	if (AktivesVO::NameValidation(Object->p_sName))
	{
		ExceptionHandler(1,"Object " + Object->p_sName + " already existing");
	}
	else
	{
		AktivesVO::mapAllObjects[Object->p_sName] = Object;
		cout << Object->p_sName << " was added" << endl;
	}
}

void AktivesVO::vAddPtObjects(list<AktivesVO*> listObjects)
{
	list<AktivesVO*>::iterator it;
	for (it = listObjects.begin(); it != listObjects.end(); it++)
	{
		AktivesVO::vAddPtObject((*it));
	}
}

bool AktivesVO::NameValidation(string name)
{
	if (AktivesVO::mapAllObjects.count(name) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


AktivesVO::~AktivesVO()
{
}

void AktivesVO::vostreamAusgabe(ostream & out)
{
	out.precision(2);
	out << fixed;
	out << resetiosflags(ios::right);
	out << setiosflags(ios::left);
	out << setw(6) << p_iID;
	out << setw(10) << p_sName;
	out << setw(5) << ":";
}

void AktivesVO::vInitialization()
{
	p_iID = p_iMaxID;
	p_iMaxID++;
}

string AktivesVO::returnName()
{
	return p_sName;
}

ostream& operator <<(ostream& out, AktivesVO& fahrzeug)
{
	fahrzeug.vostreamAusgabe(out);
	return out;
}

bool AktivesVO::operator==(const AktivesVO& aVO)
{
	return p_iID == aVO.p_iID;
}


istream & operator>>(istream & in, AktivesVO & x)
{
	x.istreamInput(in);
	return in;
}