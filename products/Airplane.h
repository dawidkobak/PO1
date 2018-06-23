#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "Vehicle.h"

class Airplane : public Vehicle
{
public:
	Airplane(int n_ID)
	:Vehicle(n_ID)
	{
		SetMaxSpeed(100);
	}
	
	virtual ~Airplane() {}

	void SetPrice(int n_price)
	{
		std::cout << "The plane price is changed\n";
		Product::SetPrice(n_price);
	}

	void SetWingspan(int n_wing_span)
	{
		wing_span = n_wing_span;
	}

	void Fly() const
	{
		std::cout << "Flying the airplane with ID=" << Id() << std::endl;
	}

	virtual void Print() const
	{
		std::cout << "A vehicle with ID=" << Id() << " is an airplane with max speed of "
		<< max_speed << " and wignspan " << wing_span << std::endl;
	}

	virtual void Move() const
	{
		std::cout << "Flying the airplane with ID=" << Id() << std::endl;	
	}

private:
	int wing_span;
	
};

#endif