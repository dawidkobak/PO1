#pragma once

#include <initializer_list>
#include <exception>

// class template creating container vector-type  
template <typename T>
class Vector
{
	using iterator = T * ;
public: // public functions
	// constructor with initializer list
	Vector(std::initializer_list<T> init_list);

	// default constructor
	Vector();

	// destructor, release memory
	~Vector();

	// function returning size of vector
	unsigned int size() const;

	// function returning capacity of vector
	unsigned int capacity() const;

	// operator returning reference to N element of vector
	T& operator [](unsigned int index);

	const T& operator [](unsigned int index) const;

	// function adding object to vector
	void push_back(const T& add_object);

	// function erase last object of vector
	void pop_back();

	// function returning iterator to begin of vector
	iterator begin() const;

	// function returning iterator to end of vector
	iterator end() const;

	// function returning reference to object N element of vector, function can throw exception out_of_range type
	T& at(unsigned int index);

	// function returning constant reference to N element of vector, function can throw exception out_of_range type
	const T& at(unsigned int index) const;

	// function returning reference to first element of vector
	T& front();

	// function returning constant reference to first element of vector
	const T& front() const;

	// function returning reference to last element of vector
	T& back();

	// function returning constant reference to last element of vector
	const T& back() const;

	// function returning true when vector is empty, false when isn't empty
	bool empty() const;

	// function deleting all elements of vector
	void clean();

	// function deleting element send as iterator
	void erase(iterator pos);

private: // private data
	T * table;
	unsigned int vector_size{ 0 };
	unsigned int vector_capacity{ 0 };
};

template <typename T>
Vector<T>::Vector() : vector_capacity{1}, vector_size{0}
{
	table = new T[vector_capacity];
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init_list)
{
	vector_capacity = vector_size = init_list.size();
	table = new T[vector_capacity];
	unsigned int i{ 0 };
	for (auto& el : init_list)
	{
		table[i++] = el;
	}
}

template <typename T>
Vector<T>::~Vector()
{
	clean();
}

template <typename T>
unsigned int Vector<T>::size() const
{
	return vector_size;
}

template <typename T>
unsigned int Vector<T>::capacity() const
{
	return vector_capacity;
}

template <typename T>
T& Vector<T>::operator [](unsigned int index)
{
	return table[index];
}

template <typename T>
const T& Vector<T>::operator [](unsigned int index) const
{
	return table[index];
}

template <typename T>
void Vector<T>::push_back(const T& add_object)
{
	if (vector_size <= vector_capacity)
	{
		table[vector_size++ - 1] = add_object;
	}
	else
	{
		vector_capacity *= 2;
		T* new_table = new T[vector_capacity];

		int i = 0;
		for (iterator it = begin(); it != end(); ++it)
		{
			new_table[i++] = *it;
		}

		delete[] table;
		table = new_table;
		table[size() - 1] = add_object;
	}
}

template <typename T>
void Vector<T>::pop_back()
{
	delete table[size() - 1];
	vector_size--;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() const
{
	return table;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() const
{
	return &table[size()];
}

template <typename T>
T& Vector<T>::at(unsigned int index)
{
	if (vector_size < index)
	{
		std::out_of_range new_exception("Out of range of vector");
		throw new_exception;
	}
	else
	{
		return table[index];
	}
}

template <typename T>
const T& Vector<T>::at(unsigned int index) const
{
	if (vector_size < index)
	{
		std::out_of_range new_exception("Out of range of vector");
		throw new_exception;
	}
	else
	{
		return table[index];
	}
}

template <typename T>
T& Vector<T>::front()
{
	return table[0];
}

template <typename T>
const T& Vector<T>::front() const
{
	return table[0];
}

template <typename T>
T& Vector<T>::back()
{
	return table[size() - 1];
}

template <typename T>
const T& Vector<T>::back() const
{
	return table[size() - 1];
}

template <typename T>
bool Vector<T>::empty() const
{
	if (not vector_size)
		return false;
	else
		return true;
}

template <typename T>
void Vector<T>::clean()
{
	if (table)
	{
		delete[] table;
		table = nullptr;
	}
}

template <typename T>
void Vector<T>::erase(iterator pos)
{
	delete *pos;
	size_t index = pos - begin();
	for (iterator it = pos; it != end(); ++it)
	{
		table[index] = table[index + 1];
		index++;
	}
	delete table[index]; // maybe [index + 1]
	vector_size--;
}