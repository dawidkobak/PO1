#ifndef OUTOFRANGE_H
#define OUTOFRANGE_H

#include "Factory.h"
#include "Value.h"

//klasa reprezentujaca obiekt ktory bedzie wyrzucany jako wyjatek
class OutOfRange
{
public:
	//operator wypisania
	friend std::ostream& operator << (std::ostream& output, const OutOfRange& model);
	//konstuktor przyjmujacy wskaznik na fabryke i wartosc
	OutOfRange(Factory* factory);
	//dektruktor
	~OutOfRange() {}
	//funkcja czyszczaca tablice w klasie Factory
	void CleanFactory();
	//wskaznik na Fabryke
	Factory* factory_pointer;

};

#endif
