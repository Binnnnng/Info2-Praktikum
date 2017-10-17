#include<iostream>
#include"Fahrzeug.h"
#include<string>

using namespace std;
string name;

void vAufgabe_1() {
	Fahrzeug ts;
	Fahrzeug("test");
	Fahrzeug* tt;
	Fahrzeug* t2;
	tt = new Fahrzeug();
	t2 = new Fahrzeug("test2");
	delete tt;
	delete t2;
	cout << "FINISH" << endl;

}

int main(void) {
	vAufgabe_1();
	return 0;
}

