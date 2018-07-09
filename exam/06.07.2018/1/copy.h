#ifndef COPY_H
#define COPY_H

#include <type_traits>
#include <iostream>
#include <vector>

template<typename T, typename U>
void my_copy(T /*start*/, T /*end*/, U /*u_start*/)
{
	if(std::is_pod<typename T::value_type>::value)
	{
		std::cout << "Copying POD objects\n";
	}
	else
	{
		std::cout << "Copying non-POD objects\n";
	}
}

#endif