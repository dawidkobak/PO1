#ifndef ARRAYOFVARIABLES_H
#define ARRAYOFVARIABLES_H

#include "Variable.h"

using VariableDouble = Variable<double>;
using VariableFloat = Variable<float>;
using VariableInt = Variable<int>;
using VariableChar = Variable<char>;
using VariableBool = Variable<bool>;

class ArrayOfVariables
{
public:
	ArrayOfVariables(unsigned n_size) : size(n_size)
	{
		table = new VariableBaseType*[size];
		for(unsigned i = 0; i < size; ++i)
		{
			table[i] = nullptr;
		}
	}

	~ArrayOfVariables()
	{
		if(table)
		{
			for(unsigned i = 0; i < size; ++i)
			{
				delete table[i];
				table[i] = nullptr;
			}
		}
		delete[] table;
		table = nullptr;
	}

	template <typename T>
	Variable<T>* CreateAndAdd(std::string name, T a)
	{
		Variable<T>* temp = new Variable<T>(name, a);
		table[counter++] = temp;
		return temp;
	}

	void Print() const
	{
		for(unsigned i = 0; i < counter; ++i)
		{
			table[i]->Print();
		}
	}

private:
	unsigned size;
	VariableBaseType** table;
	unsigned counter { 0 };
};

#endif