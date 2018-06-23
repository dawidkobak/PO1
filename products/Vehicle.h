#ifndef VEHICLE_H
#define VEHICLE_H

#include "Product.h"

class Vehicle : public Product
{
public:
	Vehicle(int n_ID):
	Product(n_ID), max_speed() {}
	
	virtual ~Vehicle() {}

	void SetMaxSpeed(int n_max_speed)
	{
		max_speed = n_max_speed;
	}

	virtual void Print() const
	{
		std::cout << "This is a vehicle with max speed of " << max_speed << std::endl;	
	}

	void SetPrice(int n_price)
	{
		std::cout << n_price <<" is the new cost of the vehicle" << std::endl;
		Product::SetPrice(n_price);
	}

	virtual void Move() const
	{
		std:: cout << "Moving with speed " << max_speed << std::endl;
	}

protected:
	int max_speed;
	
};

#endif