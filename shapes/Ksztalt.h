#ifndef KSZTALT_H
#define KSZTALT_H

#include <iostream>

class Ksztalt
{
public:
	virtual ~Ksztalt() {}

	virtual void wypisz(std::ostream&) const = 0;

	virtual double polePow() const = 0;
	
};

void wypisz(const Ksztalt& to_print);

#endif