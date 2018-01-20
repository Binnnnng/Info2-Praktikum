#include "stdafx.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"


using namespace std;

FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg, int Vtype) :p_pWeg(weg), Vtype(Vtype)
{
}

FzgVerhalten::~FzgVerhalten()
{
}

Weg * FzgVerhalten::pGetWeg()
{
	return p_pWeg;
}
