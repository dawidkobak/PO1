#ifndef KOLO_H
#define KOLO_H

#include "Ksztalt.h"
#include <iostream>

class Kolo: public Ksztalt
{
public:
	Kolo(int n_radius)
	:radius(n_radius) {}
	
	virtual ~Kolo() {}

	virtual void wypisz(std::ostream& output) const;

	virtual double polePow() const;

private:
	int radius;
	
};

#endif