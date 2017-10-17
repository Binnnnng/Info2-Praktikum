#pragma once
#include<string>

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug();
	virtual ~Fahrzeug();
	Fahrzeug(string namestr);
private:
	int p_iID;
	static int p_iMaxID;
	string p_sName;
};

