#include <iostream>
#include "Kolo.h"

void Kolo::wypisz(std::ostream& output) const
{
	output << "Kolo o promieniu : " << radius << std::endl;
}

double Kolo::polePow() const
{
	return 3.1415 * radius;
}