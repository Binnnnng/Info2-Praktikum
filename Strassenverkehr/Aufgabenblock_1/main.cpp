#include<iostream>
#include"Fahrzeug.h"
#include<string>
#include<iomanip>

using namespace std;

void createTable()
{
	resetiosflags(ios::right);
	cout << setiosflags(ios::right) << "ID#" << setw(8) ;
	cout << setiosflags(ios::right) << "Name" << setw(8);
	cout << setiosflags(ios::right) << ":" << setw(10) ;
	cout << setiosflags(ios::right) << "MaxKmh" << setw(18);
	cout << setiosflags(ios::right) << " GesamtStrecke" << setw(18) << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vAufgabe_1() 
{
	Fahrzeug statictest1;
	Fahrzeug statictest2("test");
	string name1;
	//cout << "Enter Teststring" << endl;
	//getline(cin, name1);
	Fahrzeug* dynamictest1 = new Fahrzeug();
	Fahrzeug* dynamictest2 = new Fahrzeug(name1);
	createTable();
	statictest1.vAusgabe();
	statictest2.vAusgabe();
	//dynamictest1.vAusgabe;
	//dynamictest2.vAusgabe;
	delete dynamictest2;
	delete dynamictest1;
	cout << "FINISH" << endl;

}

int main(void) 
{
	vAufgabe_1();
	return 0;
}

