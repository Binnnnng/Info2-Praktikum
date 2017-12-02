#pragma once
#include<string>
#include<iomanip>
#include<iostream>


using namespace std;

class AktivesVO 
{
public:
	AktivesVO();
	AktivesVO(string namestr);
	virtual ~AktivesVO();
	void virtual vostreamAusgabe(ostream& out);
	void vInitialization();
	string returnName();
	bool operator==(const AktivesVO& aVO);

private:
	static int p_iMaxID;

protected:
	string p_sName;
	int p_iID;
	double lokaleZeit;
};

ostream& operator <<(ostream& out, AktivesVO&x);