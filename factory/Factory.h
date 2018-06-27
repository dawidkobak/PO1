#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include "Value.h"
class OutOfRange;

//klasa reprezentujaca obiekt sluzacy do tworzenia wartosci
class Factory
{
public:
	friend std::ostream& operator << (std::ostream& output, const OutOfRange& model);
	//konstruktor ustawiajacy przedzial z ktorego moga byc wartosci
	Factory(double n_lower, double n_upper);
	//destruktor czyszczacy tablice
	~Factory();
	// funkcja dodajaca wartosc do tablicy, wyrzuca wyjatek gdy punkt nie nalezy do przedzialu
	Value* PrepareValue(const std::string& name, double value); 
	//getter zwracajacy dolna wartosc zakresu
	int GetLower() const;
	//getter zwracajacy gorna warotsc zakesu
	int GetUpper() const;
	//funkcja czyszczaca tablice
	void Clean();
	
private:
	//wektor(tablica) wskaznikow na wartosci
	std::vector<Value*> table;
	//dolna granica przedzialu
	double lower;
	//gorna granica przedzialu
	double upper;
};

#endif
