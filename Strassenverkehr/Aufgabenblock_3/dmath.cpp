#include "stdafx.h"
#include "dmath.h"
#include <algorithm>
#include <cmath>

using namespace std;

dmath::dmath()
{
}


dmath::~dmath()
{
}

bool dmath::nearly_equal(double a, double b)
{
	bool neq = false;
	neq = fabs(a - b) <= max(fabs(a), fabs(b)) * numeric_limits<double>::epsilon() * 100;
	return neq;
}
