#ifndef COW_H
#define COW_H

#include "Animal.h"
#include <iostream>

class Cow : public Animal
{
public:
	Cow(int n_age)
	:Animal(n_age)
	{
		std::cout << "Animal with age " << age <<", Cow\n";
	}
	
	virtual ~Cow()
	{
		std::cout << "Bye Cow\n";
	}

	virtual void saySomething() const
	{
		std::cout << "Cow: Muuu...\n";
	}

	virtual void print() const
	{
		std::cout << "Animal with age " << age <<", Cow\n";
	}
	
};

#endif