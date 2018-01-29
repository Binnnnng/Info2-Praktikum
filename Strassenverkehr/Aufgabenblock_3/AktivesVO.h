#pragma once
#include<string>
#include<iomanip>
#include<iostream>
#include <map>
#include <list>

using namespace std;

class AktivesVO 
{
public:
	AktivesVO();
	AktivesVO(string namestr);
	const string type = "AVO";
	istream virtual & istreamInput(istream& in);
	static AktivesVO* ptObject(string sName);
	static void vAddPtObject(AktivesVO* Object);
	static void vAddPtObjects(list<AktivesVO*> listObjects);
	static bool NameValidation(string);
	virtual ~AktivesVO();
	void virtual vostreamAusgabe(ostream& out);
	void vInitialization();
	string returnName();
	bool operator==(const AktivesVO& aVO);

private:
	static int p_iMaxID;
	static map <string, AktivesVO*> mapAllObjects;

protected:
	string p_sName;
	int p_iID;
	double lokaleZeit;
};

ostream& operator <<(ostream& out, AktivesVO&x);
istream& operator >>(istream& in, AktivesVO& x);