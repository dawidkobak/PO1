#include <iostream>
#include <cmath>
#include "Trojkat.h"

void Trojkat::wypisz(std::ostream& output) const
{
	output << "Trojkat o bokach : " << a << " " << b << " " << c << std::endl;
}

double Trojkat::polePow() const
{
	double x = (a + b + c) / 2.0;
	return sqrt(x * (x - a) * (x - b) * (x - c));
}