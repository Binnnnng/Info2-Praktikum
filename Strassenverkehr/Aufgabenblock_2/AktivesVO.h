#pragma once
#include"Fahrzeug.h"
#include"Weg.h"
class AktivesVO :public Fahrzeug, public Weg
{
public:
	AktivesVO();
	virtual ~AktivesVO();
};

