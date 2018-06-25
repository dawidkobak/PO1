#ifndef POJAZD_H
#define POJAZD_H

#include <string>

class Pojazd
{
public:
	Pojazd() {}
	virtual ~Pojazd() {}

	virtual std::string rodzaj() const = 0;
	
};

#endif