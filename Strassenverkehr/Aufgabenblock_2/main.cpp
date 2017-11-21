#include"stdafx.h"
#include<iostream>
#include"Fahrzeug.h"
#include"Pkw.h"
#include"Fahrrad.h"
#include<string>
#include<iomanip>
#include<vector>
#include"Weg.h"
#include"SimuClient.h"
//#include"LazyListe.h"

using namespace std;
double dGlobaleZeit = 0.0;
double tInkrement = 0.3;

void createTable()
{
	cout << resetiosflags(ios::right);
	cout << setiosflags(ios::left);
	cout << setw(6) << "ID#" ;
	cout << setw(10) << "Name" ;
	cout << setw(4) << ":" ;
	cout << setw(10) << "MaxKmh" ;
	cout << setw(18) << "GesamtStrecke";
	cout << setw(10) << "Km/h";
	cout << setw(13) << "Abschnitt";
	cout << setw(15) << "GesVerbrauch";
	cout << setw(15) << "Tankinhalt" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::left);
}

void vAufgabe_4()
{
	Weg* weg = new Weg("Weg1", 20, Weg::Innerorts);
	cout << *weg << endl;
}

void vAufgabe_3()
{
	dGlobaleZeit = 1.0;
	cout << dGlobaleZeit << endl;
	PKW* pkw = new PKW("PKW",80,8.0);
	pkw->vAbfertigung();
	PKW* cpypkw = new PKW(*pkw);
	cout << dGlobaleZeit << endl;
	createTable();
	cout << *pkw << *cpypkw << endl << endl;

	Fahrrad* bike = new Fahrrad("Bike",20);
	bike->vAbfertigung();
	Fahrrad* cpybike = new Fahrrad(*bike);
	cout << dGlobaleZeit << endl;
	createTable();
	cout << *bike << *cpybike << endl << endl;

	PKW* pkw2 = new PKW("X",0,0);
	*pkw2 = *pkw;
	cout << dGlobaleZeit << endl;
	createTable();
	cout << *pkw << *pkw2 << endl << endl;

	cout << "Return 0 ==> 'cpybike Strecke < bike Strecke'" << endl;
	cout << (*bike < *cpybike) << endl << endl;

	delete pkw;
	delete pkw2;
	delete cpypkw;
	delete bike;
	delete cpybike;

	cout << "FINISH" << endl;
}

void vAufgabe_2()
{
	int num = 0,prev=0;
	vector<Fahrzeug*> fahrzeugvec;
	cout << "Wieviele Fahrraeder konstruieren?" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		Fahrrad* fahrrad = new Fahrrad("Fahrrad"+to_string(i), 20);
		fahrzeugvec.push_back(fahrrad);
	}
	cout << num <<" "<< "Fahrrad/Fahhraeder konstruiert!" << endl;
	cout << "Wieviele PKW konstruieren?" << endl;
	cin >> num;
	for (int i = prev+1; i <=num+prev; i++)
	{
		PKW* pkw = new PKW("PKW"+to_string(i), 80, 7.5);
		fahrzeugvec.push_back(pkw);
	}
	cout << num << " " << "PKW/PKW's konstruiert!" << endl;
	bool tanken = true;
	while (dGlobaleZeit <= 5.0)
	{
		if (dGlobaleZeit > 3.0 && tanken == true)
		{
			vector<Fahrzeug*>::iterator fahrzeugIT = fahrzeugvec.begin();
			while (fahrzeugIT != fahrzeugvec.end()) {
				(*fahrzeugIT)->dTanken(-1);
				fahrzeugIT++;
			}
			tanken = false;
		}
		cout << dGlobaleZeit << endl;
		createTable();
		vector<Fahrzeug*>::iterator fahrzeugIT = fahrzeugvec.begin();
		while (fahrzeugIT != fahrzeugvec.end())
		{
			(*fahrzeugIT)->vAbfertigung();
			(*fahrzeugIT)->vAusgabe();
			fahrzeugIT++;
		}
		cout << endl;
		dGlobaleZeit += tInkrement;
	}

	cout << "" << endl;
	cout << "FINISH" << endl;
}

void vAufgabe_1_deb()
{
	Fahrzeug* car1 = new Fahrzeug("PKW1", 5);
	Fahrzeug* car2 = new Fahrzeug("PKW2", 15);
	Fahrzeug* car3 = new Fahrzeug("PKW3", 30);
	Fahrzeug* car4 = new Fahrzeug("PKW4", 50);

	vector<Fahrzeug*> vehiclevec;
	vehiclevec.push_back(car1);
	vehiclevec.push_back(car2);
	vehiclevec.push_back(car3);
	vehiclevec.push_back(car4);

	vehiclevec[2] = 0;

	createTable();
	while (dGlobaleZeit <= 24.0)
	{
		for (int veccount = 0;veccount < 4; veccount++)
		{
			vehiclevec[veccount]->vAbfertigung();
		}
		for (int veccount = 0; veccount < 4; veccount++)
		{
			vehiclevec[veccount]->vAusgabe();
		}
		dGlobaleZeit += tInkrement;
	}
	
	delete car4;
	delete car3;
	delete car2;
	delete car1;

	cout << "" << endl;
	cout << "FINISH" << endl;
}

void vAufgabe_1() 
{
	/*
	Fahrzeug statictest1;
	Fahrzeug statictest2("test");
	string name1;
	cout << "Enter Testname" << endl;
	getline(cin, name1);
	cout << "" << endl;
	Fahrzeug* dynamictest1 = new Fahrzeug();
	Fahrzeug* dynamictest2 = new Fahrzeug(name1);
	*/
	Fahrrad staticbike("Bike", 25);
	PKW staticpkw("Pkw", 30,8.5);
	createTable();
	/*
	statictest1.vAusgabe();
	statictest2.vAusgabe();
	dynamictest1->vAusgabe();
	dynamictest2->vAusgabe();
	delete dynamictest2;
	delete dynamictest1;
	static1.vAusgabe();
	static2.vAusgabe();
	*/
	while (dGlobaleZeit < 24.0)
	{
		staticbike.vAbfertigung();
		staticbike.vAusgabe();
		staticpkw.vAbfertigung();
		staticpkw.vAusgabe();
		dGlobaleZeit += tInkrement;
	}
	cout << "" << endl;
	cout << "FINISH" << endl;

}

int main(void) 
{
	vAufgabe_2();
	return 0;
}

