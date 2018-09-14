#ifndef VARIABLEWITHUNITS_H
#define VARIABLEWITHUNITS_H

#include <string>
#include <iostream>
#include "Variable.h"

template<typename T>
class Variable;

template <typename T>
class VariableWithUnits : public Variable<T>
{
public:
	VariableWithUnits(std::string n_name, T var, std::string n_unit)
	: Variable<T>(n_name, var), unit(n_unit)
	{

	}
	
	~VariableWithUnits() {}

	virtual void Print() const
	{
		std::cout << Variable<T>::type_name << ": " << Variable<T>::var << " [" << unit << "]" << std::endl;
	}

private:
	std::string unit;
	
};



#endif