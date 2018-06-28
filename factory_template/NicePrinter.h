#ifndef NICEPRINTER_H
#define NICEPRINTER_H

#include <iomanip>
#include <iostream>

class NicePrinter
{
public:
	NicePrinter(int n_width)
	:width(n_width)
	{
	}

	~NicePrinter() = default;

	template<typename T>
	void operator()(const T& object) const
	{
		std::cout << std::setw(width) << ++number << ": " << object << std::endl;
	}

private:
	int width;
	static int number;
	
};

#endif