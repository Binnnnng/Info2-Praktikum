#include "Fahrzeug.h"
#include<iostream>
using namespace std;

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug()
{
	p_sName = "";
	p_iID = p_iMaxID;
	p_iMaxID++;
	cout << "Standard Contructor called" << endl;
	cout <<p_sName <<"   "<<p_iID<< endl;
}


Fahrzeug::~Fahrzeug()
{
	cout << "Desructor called" << endl;
	cout <<p_sName<< "   " <<p_iID<< endl;
}

Fahrzeug::Fahrzeug(string namestr)
{
	p_sName = "";
	p_iID = p_iMaxID;
	p_iMaxID++;
	p_sName = namestr;
	cout << "Non-Standard Contructor called" << endl;
	cout <<namestr<< "   " <<p_iID<< endl;
}
