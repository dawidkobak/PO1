#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>

class Property
{
public:
	Property() 
	{

	}

	virtual ~Property() {}

	virtual std::ostream& print(std::ostream& output) const
	{
		output << "EMPTY";
		return output;
	} 

	virtual Property* getProperty() const
	{
		return new Property();
	}
	
};

std::ostream& operator << (std::ostream& output, const Property& to_print)
{
	return to_print.print(output);
}

#endif