#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include <iostream>
#include "PojazdLadowy.h"
#include "PredkoscMaksymalna.h"

class Samochod: public PojazdLadowy
{
public:
	Samochod(const PredkoscMaksymalna& n_vmax)
	:vmax(n_vmax) {}

	~Samochod() {}

	virtual int predkoscMaksymalna() const
	{
		return vmax.v_max;
	}

	virtual std::string rodzaj() const
	{
		std::string type = "Samochod";
		return type;
	}

protected:
	PredkoscMaksymalna vmax;
	
};

#endif