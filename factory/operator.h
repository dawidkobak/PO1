#ifndef OPERATOR
#define OPERATOR

#include <iostream>
#include "OutOfRange.h"

//globalny operator wypisujacy informacje o wyjatku

std::ostream& operator << (std::ostream& output, const OutOfRange& model);

#endif