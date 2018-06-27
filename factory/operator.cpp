#include <iostream>
#include "OutOfRange.h"

std::ostream& operator << (std::ostream& output, const OutOfRange& model)
{
	output<< "Value named: " << (model.factory_pointer->table[(model.factory_pointer->table.size() - 1)]) ->GetName()
	<< " has value " << (model.factory_pointer->table[(model.factory_pointer->table.size() - 1)]) ->GetValue()
	<< " which is outside of the allowed range: ["
	<< model.factory_pointer -> GetLower() << ", "
	<< model.factory_pointer -> GetUpper() << "]";
	return output;
}