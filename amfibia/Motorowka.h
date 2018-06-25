#ifndef MOTOROWKA_H
#define MOTOROWKA_H

#include "Pojazd.h"
#include "PredkoscMaksymalna.h"

class Motorowka: public virtual Pojazd
{
public:
	Motorowka(const PredkoscMaksymalna& n_vmax)
	:vmax(n_vmax) {}

	~Motorowka() {}

	virtual int predkoscMaksymalna() const
	{
		return vmax.v_max;
	}

	virtual std::string rodzaj() const
	{
		std::string type = "Motorowka";
		return type;
	}

protected:
	PredkoscMaksymalna vmax;
	
};

#endif