#include<iostream>
#include"Fahrzeug.h"
#include"Pkw.h"
#include"Fahrrad.h"
#include<string>
#include<iomanip>
#include<vector>

using namespace std;
double dGlobaleZeit = 0.0;
double tInkrement = 4.0;

void createTable()
{
	cout << resetiosflags(ios::right);
	cout << setiosflags(ios::left);
	cout << setw(6) << "ID#" ;
	cout << setw(10) << "Name" ;
	cout << setw(4) << ":" ;
	cout << setw(10) << "MaxKmh" ;
	cout << setw(15) << "GesamtStrecke";
	cout << setw(15) << "GesVerbrauch";
	cout << setw(15) << "Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::left);
	
	
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

	//vehiclevec[2] = 0;

	createTable();
	double tInkrement = 4.0;
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
	PKW staticpkw("PKW", 40,7.0);
	PKW staticpkw2("AUTO3", 30,8.5);
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
		staticpkw.vPKWAbfertigung();
		staticpkw2.vPKWAbfertigung();
		staticpkw.vPKWAusgabe();
		staticpkw2.vPKWAusgabe();
		dGlobaleZeit += tInkrement;
	}
	cout << "" << endl;
	cout << "FINISH" << endl;

}

int main(void) 
{
	vAufgabe_1();
	return 0;
}

