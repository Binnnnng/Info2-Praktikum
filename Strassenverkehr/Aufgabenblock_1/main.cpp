#include<iostream>
#include"Fahrzeug.h"
#include<string>

using namespace std;
string name;

void vAufgabe_1() {
	Fahrzeug();
	Fahrzeug("test");
	Fahrzeug* ps1;
	ps1 = new Fahrzeug();
	cin >> name;
}

int main(void) {
	vAufgabe_1();
	return 0;
}

