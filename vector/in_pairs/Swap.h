#ifndef Swap_h
#define Swap_h

#include <cstring> /// memcpy

/// This file contains SwapStruct that helps
/// to perform swap operation on pointers to 
/// objects of type T. It has two versions - one
/// for POD types that uses memcpy from cstring
/// and other for complex types

/// Struct that constains swap for simple
/// types
template <typename T, bool isPod>
struct SwapStruct
{
	static void swap (T* a, T*b)
	{
		T temp;
		memcpy(&temp, a, sizeof(T));
		memcpy(a, b, sizeof(T));
		memcpy(b, &temp, sizeof(T));
	} 
};

/// Struct that contains swap for complex
/// types
template <typename T>
struct SwapStruct<T, false>
{
	static void swap(T* a, T*b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};

#endif