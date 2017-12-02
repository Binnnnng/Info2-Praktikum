#include "stdafx.h"
#include"AktivesVO.h"


using namespace std;

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