#include <iostream>
#include "Kwadrat.h"

void Kwadrat::wypisz(std::ostream& output) const
{
	output << "Kwadrat o boku : " << flank << std::endl;
}

double Kwadrat::polePow() const
{
	return static_cast<double>(flank) * flank;
}