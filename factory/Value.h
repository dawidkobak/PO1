#ifndef VALUE_H
#define VALUE_H

#include <string>

//klasa przechowujaca wartosc i jej nazwe
class Value
{
public:
	//konstruktor przyjmujacy nazwe i warosc
	Value(std::string n_name, double n_value);
	//destruktor
	~Value();
	//funkcja wypisujaca informacje o punkcie
	void Print() const;
	//getter zwracajacy nazwe punktu
	std::string GetName() const;
	//getter zwracajacy wartosc punktu
	double GetValue() const;
	
private:
	//nazwa punktu
	std::string name;
	//wartosc
	double value;
};

#endif
