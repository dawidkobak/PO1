#ifndef AMFIBIA_H
#define AMFIBIA_H

#include "Samochod.h"
#include "Motorowka.h"
#include "PredkoscMaksymalna.h"

class Amfibia: public Samochod, public Motorowka
{
public:
	Amfibia(const PredkoscMaksymalna& vmax1, const PredkoscMaksymalna& vmax2)
	:Samochod(vmax1), Motorowka(vmax2) {}

	virtual std::string rodzaj() const
	{
		std::string type = "Amfibia";
		return type;
	}
	
	~Amfibia() {}
	
};

#endif