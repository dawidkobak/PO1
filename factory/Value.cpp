#include <iostream> 
#include "Value.h"

void Value::Print() const
{
	std::cout << name << " = " << value << std::endl;
}

Value::Value(std::string n_name, double n_value)
: name(n_name),value(n_value)
{
	std::cout << "Manufacturing value " << value << std::endl;
}


Value::~Value()
{
	std::cout << "Destroying value " << value << std::endl;
}

double Value::GetValue() const 
{
	return value; 
}

std::string Value::GetName() const 
{
	return name; 
}