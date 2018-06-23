#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "Animal.h"
#include <string>

class Zoo
{
public:
	Zoo(std::string n_name, int n_size);

	void print() const;

	~Zoo();

	Animal* insert(int index, Animal* n_animal);

	Animal* insert(Animal* n_animal);

	void reorganize(int n_size);

	Animal* remove(int index);

	int numOfAnimals() const;

private:
	std::string name;
	int size;
	Animal** cages;
	int occupated;
};

#endif