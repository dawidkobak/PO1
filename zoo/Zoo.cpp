#include <iostream>
#include "Zoo.h"

Zoo::Zoo(std::string n_name, int n_size)
:name(n_name), size(n_size), occupated(0)
{
	cages = new Animal*[size];

	for(int i = 0; i < size; ++i)
	{
		cages[i] = nullptr;
	}
}

void Zoo::print() const
{
	std::cout << "Zoo: " << name << std::endl;
	for (int i = 0; i < size; ++i)
	{
		if(not cages[i])			
			std::cout << "Enclosure " << i << " : empty\n"; 
		else
		{
			std::cout << "Enclosure " << i << " : ";
			cages[i] -> print();
		}
	}
}

Zoo::~Zoo() 
{
	for(int index = 0; index < size; ++index)
	{
		if(cages[index])
		{
			delete cages[index];
			cages[index] = nullptr;		
		}
	}

	std::cout << name << " zoo - closed\n";

	delete[] cages;
	cages = nullptr;
}

Animal* Zoo::insert(int index, Animal* n_animal)
{
	if(not cages[index])
	{
		cages[index] = n_animal;
		occupated++;
	}

	return nullptr;
}

Animal* Zoo::insert(Animal* n_animal)
{
	bool flag = true;

	for(int i = 0; i < size; ++i)
	{
		if(not cages[i])
		{
			cages[i] = n_animal;
			flag = false;
			occupated++;
			break;
		}
	}

	if(flag)
		return n_animal;
	else
		return nullptr;
}

void Zoo::reorganize(int n_size)
{
	if(n_size < occupated)
	{
		std::cout << "There is more than " << n_size << " animals in zoo, resize imposible\n";
	}
	else
	{
		std:: cout << name << " zoo : new size = " << n_size << std::endl;
		Animal** temp = new Animal*[n_size];
		for(int i = 0; i < n_size; ++i)
		{
			temp[i] = nullptr;
		}

		for(int i = 0, j = 0; i < n_size; ++i, ++j)
		{
			if (j < size)
			{
				while(not cages[j])
					++j;
				temp[i] = cages[j];
			}
		}

		delete[] cages;
		cages = temp;
		size = n_size;
		int n_occupated = 0;
		for(int i = 0; i < size; ++i)
		{
			if(not cages[i])
				n_occupated++;
		}
	
		occupated = n_occupated;
	}
}

Animal* Zoo::remove(int index)
{
	if(cages[index])
	{
		Animal* temp = cages[index];
		cages[index] = nullptr;
		occupated--;
		return temp;
	}
	else
		return nullptr;
}

int Zoo::numOfAnimals() const
{
	return occupated;
}