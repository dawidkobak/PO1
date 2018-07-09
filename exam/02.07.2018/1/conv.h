#ifndef CONV_H
#define CONV_H

#include <iostream>
#include <vector>

class Base
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;
};

class Derived1: public Base
{
public:
	virtual std::ostream& print(std::ostream& out) const
	{
		return out << __PRETTY_FUNCTION__;
	}
};

class Derived2: public Base
{
public:
	virtual std::ostream& print(std::ostream& out) const
	{
		return out << __PRETTY_FUNCTION__;
	}
};

class Derived3: public Derived2
{
public:
	virtual std::ostream& print(std::ostream& out) const
	{
		return out << __PRETTY_FUNCTION__;
	}
};

std::ostream& operator <<(std::ostream& out, const Base& model)
{
	return model.print(out);
}

std::ostream& operator <<(std::ostream& out, const std::vector<Base*>& model)
{
	out << "[\n";
	for(unsigned i = 0; i < model.size(); ++i)
	{
		out << *(model[i]) << ",\n";
	}
	out << "]\n";
	return out;
}

#endif // CONV_H