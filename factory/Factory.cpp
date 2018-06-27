#include <iostream> 
#include "Factory.h"
#include "OutOfRange.h"


Value* Factory::PrepareValue(const std::string& name, double value)
{
	Value* tempvalue = new Value(name, value);
	table.push_back(tempvalue);
	if (value >= lower && value <= upper)
	{
		return tempvalue;
	}
	else
	{
		OutOfRange exception (this);
		throw exception;
	}
	
}

Factory::Factory(double n_lower, double n_upper)
: lower(n_lower), upper(n_upper) 
{
	std::cout << "Build factory with range [" << lower << ", " << upper << "]\n";
}

Factory::~Factory()
{
	Clean();

	std::cout << "Factory destroyed.\n";
}

void Factory::Clean()
{
	for(unsigned int i = 0; i < table.size(); i++)
	{
		if(table[i])
		{
			delete table[i];
			table[i] = nullptr;
		}
	}
}

int Factory::GetLower() const 
{
	return lower; 
}

int Factory::GetUpper() const 
{ 
	return upper; 
}