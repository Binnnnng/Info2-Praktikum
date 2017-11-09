#pragma once
#include"Fahrzeug.h"
#include"Weg.h"

class AktivesVO :public Fahrzeug, Weg
{
public:
	AktivesVO();
	virtual ~AktivesVO();
};

