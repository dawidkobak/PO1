#ifndef VARIABLE_H
#define VARIABLE_H

#include "VariableBaseType.h"
#include <string>
#include <iostream>
#include "VariableWithUnits.h"

template <typename T>
class Variable : public VariableBaseType
{
public:
	Variable(std::string name, T v) : type_name(name), var(v)
	{

	}
	
	virtual ~Variable() {}

	virtual void Print() const
	{
		std::cout << type_name << ": " << var << std::endl;
	}

	void SetValue(T a)
	{
		var = a;
	}

protected:
	std::string type_name;
	T var;
	
};

#endif