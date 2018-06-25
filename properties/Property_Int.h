#ifndef PROPERTY_INT_H
#define PROPERTY_INT_H

#include <iostream>
#include "Property.h"

class Property_Int : public Property
{
public:
	Property_Int(int n_value)
	:value(n_value) {}

	virtual ~Property_Int() {}

	void modulo(int mod)
	{
		value %= mod;
	}

	virtual std::ostream& print(std::ostream& output) const
	{
		output << value << "i";
		return output;
	} 

	virtual Property_Int* getProperty() const
	{
		return new Property_Int(value);
	}

private:
	int value;
	
};

#endif