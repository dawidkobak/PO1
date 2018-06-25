#ifndef PROPERTY_FLOAT_H
#define PROPERTY_FLOAT_H

#include <iostream>
#include "Property.h"

class Property_Float : public Property
{
public:
	Property_Float(float n_value)
	:value(n_value) {}
	
	virtual ~Property_Float() {}

	virtual std::ostream& print(std::ostream& output) const
	{
		output << value << "f";
		return output;
	} 

	void inverse()
	{
		value = 1.0 / value;
	}

	virtual Property_Float* getProperty() const
	{
		return new Property_Float(value);
	}

private:
	float value;
	
};

#endif