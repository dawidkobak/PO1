#ifndef CHAIR_H
#define CHAIR_H

#include "Product.h"
#include <iostream>

class Furniture : public Product
{
public:
	Furniture(int n_ID)
	:Product(n_ID) {}
	
	virtual ~Furniture() {}

	void Sit() const
	{
		std::cout << "You sit down on a chair. Nothing happens.\n";		
	}

	virtual void Print() const
	{
		std::cout << "This is chair with ID=" << Id() << std::endl;
	}

	void SetPrice(int n_price)
	{
		Product::SetPrice(n_price);
	}
	
};

#endif