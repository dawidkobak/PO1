#ifndef Vect_h
#define Vect_h

#include "IsPod.h"
#include "Swap.h"

/// Class template that generates
/// vector that stores data of type T.
/// This vector handles memory allocation
/// by itself - there is no need from
/// user to manually allocate memory
template <typename T>
class Vect
{
public:
	/// Constructor, is allocates memory for data
	/// stored in vector. Its argument represent 
	/// number of elements in vector.
	Vect(unsigned numberOfElements = 0);

	/// Overloaded operator [] - return reference
	/// to object stored in vector - it allows
	/// user to assign values (it is not const)
	T& operator[] (const unsigned index)
	{
		return m_data[index];
	}

	/// Overloaded read-only (const) operator []
	const T& operator[] (const unsigned index) const
	{
		return m_data[index];
	}

	/// Returns size (number of elements) of vector
	unsigned size() const
	{
		return m_numberOfElements;
	}

	/// Simple bubble sort implementation. Its argument is a pointer
	/// to function that compares two elements of type T
	/// It calls swap that is optimized to work differently
	/// for Pod and non-Pod types
	void buble_sort(bool (*compare)(const T& a, const T& b));

	/// Destructor that frees allocated memory using 
	/// delete [] operator - there is no need from
	/// user to free memory by himself
	~Vect();

private: 

	/// Helper method that calls swap from
	/// SwapStruct - it chooses which implementation
	/// to use according to is_pod output
	void swap(T* a, T*b);

	/// Data stored in vector
	T* m_data;

	/// Number of elements stored in vector 
	unsigned m_numberOfElements;
};


/// Method implementations

template <typename T>
Vect<T>::Vect(unsigned numberOfElements) : 
		m_data(nullptr), m_numberOfElements(numberOfElements)
{
	if (m_numberOfElements > 0)
		m_data = new T [m_numberOfElements];
}


template <typename T>
void Vect<T>::buble_sort(bool (*compare)(const T& a, const T& b))
{
	for (unsigned i = 0; i < m_numberOfElements; ++i)
	{
		for (unsigned j = i+1; j < m_numberOfElements; ++j)
		{
			if (compare(m_data[i], m_data[j]))
				swap (&m_data[i], &m_data[j]);
		}
	}
}


template <typename T>
Vect<T>::~Vect()
{
	if (m_data)
		delete [] m_data;
}


template <typename T>
void Vect<T>::swap(T* a, T*b)
{
	SwapStruct<T, is_pod<T>::pod>::swap(a, b);
}


#endif