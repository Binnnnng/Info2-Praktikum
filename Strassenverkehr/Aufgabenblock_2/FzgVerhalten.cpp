#include "stdafx.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"

using namespace std;

FzgVerhalten::FzgVerhalten()
{
}

FzgVerhalten::FzgVerhalten(Weg * weg) :p_pWeg(weg)
{
}

FzgVerhalten::~FzgVerhalten()
{
}

Weg * FzgVerhalten::pGetWeg()
{
	return p_pWeg;
}
