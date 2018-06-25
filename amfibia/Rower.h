#ifndef ROWER_H
#define ROWER_H

#include <iostream>
#include "PojazdLadowy.h"

class Rower: public PojazdLadowy
{
public:
	Rower() {}

	~Rower() {} 

	virtual std::string rodzaj() const
	{
		std::string type = "Rower";
		return type;
	}
};

#endif