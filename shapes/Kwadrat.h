#ifndef KWADRAT_H
#define KWADRAT_H

#include "Ksztalt.h"
#include <iostream>

class Kwadrat: public Ksztalt
{
public:
	Kwadrat(int n_flank)
	:flank(n_flank) {}
	
	virtual ~Kwadrat() {}

	virtual void wypisz(std::ostream& output) const;

	virtual double polePow() const;

private:
	int flank;
	
};

#endif