#ifndef PROARRAY_H
#define PROARRAY_H

#include <iostream>
#include "Property.h"

class ProArray
{
public:
	ProArray(int n_size)
	:table(new Property*[n_size]), size(n_size) 
	{
		for(int i = 0; i < size; ++i)
		{
			table[i] = new Property;
		}
	}
	
	~ProArray()
	{
		for (int i = 0; i < size; ++i)
		{
			delete table[i];
		}
		delete table;
	}

	void set(int index,const Property& to_copy)
	{
		delete table[index];
		table[index] = to_copy.getProperty();
	}

	void printAll() const
	{
		std::cout << "{";
		std::cout << *table[0];

		for (int i = 1; i < size; ++i)
		{
			std::cout << ", " << *table[i];
		}

		std::cout << "}\n";
	}

private:
	Property** table;
	int size;
	
};

#endif