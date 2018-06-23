#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"
#include <iostream>

class Sheep : public Animal
{
public:
	Sheep(int n_age)
	:Animal(n_age) 
	{
		std::cout << "Animal with age " << age <<", Sheep\n";
	}
	
	virtual ~Sheep() 
	{
		std::cout << "Bye Sheep\n";
	}

	virtual void saySomething() const
	{
		std::cout << "Sima ziomeczki\n";
	}

	virtual void print() const
	{
		std::cout << "Animal with age " << age <<", Sheep\n";
	}
	
};

#endif