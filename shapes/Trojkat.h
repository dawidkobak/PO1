#ifndef TROJKAT_H
#define TROJKAT_H

#include "Ksztalt.h"
#include <iostream>

class Trojkat: public Ksztalt
{
public:
	Trojkat(int n_a, int n_b, int n_c)
	:a(n_a), b(n_b), c(n_c) {}
	
	virtual ~Trojkat() {}

	virtual void wypisz(std::ostream&) const;

	virtual double polePow() const;

private:
	int a,b,c;
	
};

#endif