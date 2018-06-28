#ifndef LICZNIK_POZIOMOW_H
#define LICZNIK_POZIOMOW_H

#include <iostream>

class LicznikPoziomow
{
public:
	LicznikPoziomow()
	{
		poziom++;
		aktualny_poziom = poziom;
		std::cout << "Rozpoczynamy poziom numer " << aktualny_poziom << "." << std::endl;
	}

	~LicznikPoziomow()
	{
		std::cout << "Konczymy poziom numer " << aktualny_poziom << "." << std::endl;
	}

private:
	static int poziom;
	int aktualny_poziom;
	
};

#endif