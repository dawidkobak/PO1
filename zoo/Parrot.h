#ifndef PARROT_H
#define PARROT_H

#include "Animal.h"
#include <iostream>
#include <string>

class Parrot : public Animal
{
public:
	Parrot(int n_age, std::string n_name)
	:Animal(n_age), name(n_name)
	{
		std::cout << "Animal with age " << age <<", Parrot: " << name << std::endl;
	}
	
	virtual ~Parrot()
	{
		std::cout << "Bye Parrot\n";
	}

	virtual void saySomething() const
	{
		std::cout << "Parrot: " << name << ". " << name << "!\n";
	}

	virtual void print() const
	{
		std::cout << "Animal with age " << age <<", Parrot: " << name << std::endl;
	}

private:
	std::string name;
	
};

#endif