#include <iostream> 
#include "OutOfRange.h"

using namespace std;

OutOfRange::OutOfRange(Factory* factory)
: factory_pointer(factory)
{
	
}

void OutOfRange::CleanFactory()
{ 
	factory_pointer-> Clean();
	delete factory_pointer; 
	factory_pointer = nullptr;
}