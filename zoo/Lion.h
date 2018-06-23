#ifndef LION_H
#define LION_H

#include "Animal.h"
#include <iostream>

class Lion : public Animal
{
public:
	Lion(int n_age)
	:Animal(n_age) 
	{
		std::cout << "Animal with age " << age <<", Lion\n";
	}
	
	virtual ~Lion() 
	{
		std::cout << "Bye Lion\n";
	}

	virtual void saySomething() const
	{
		std::cout << "Lion: Aghr!\n";
	}

	virtual void print() const
	{
		std::cout << "Animal with age " << age <<", Lion\n";
	}
	
};

#endif