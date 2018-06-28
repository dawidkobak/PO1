#ifndef CALC_ERROR_H
#define CALC_ERROR_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Calc_error : public std::runtime_error
{
public:
	Calc_error(std::runtime_error* err = nullptr, const char* n_opis = "" ,const char* n_plik = "", const int n_linia = 0)
	: std::runtime_error(n_opis), error(err), plik(n_plik), linia(n_linia)
	{

	}

	~Calc_error() = default;

	static void handler();

private:
	std::runtime_error* error;
	const char* plik;
	const int linia;
};

#endif