#ifndef MAIN_H
#define MAIN_H

#include <cstring>

template<typename T>
struct is_pod
{
	const static bool pod = false;
};

template<typename T, bool pod >
struct Sswap
{
	static void swap(T& a, T& b)
	{
		T temp;
		memcpy(&temp, &a, sizeof(T));
		memcpy(&a, &b, sizeof(T));
		memcpy(&b, &temp, sizeof(T));
	}
};

template<typename T>
struct Sswap<T, false>
{
	static void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
};


template <typename T>
class Vect
{
public:
	Vect(const int n_size)
	:vec_size(n_size), table(nullptr) 
	{
		if(vec_size > 0)
		{
			table = new T[vec_size];
		}
	}

	T& operator [] (const int index)
	{
		return table[index];
	}

	const T& operator [] (const int index) const
	{
		return table[index];
	}

	unsigned int size() const
	{
		return vec_size;
	}

	void buble_sort(bool (*compare)(const T&, const T&))
	{
		for (unsigned int i = 0; i < vec_size; i++ )
 			for (unsigned int j = i+1; j < vec_size; ++j ) 
   				if ( compare(table[i], table[j]) )
        			Sswap<T, is_pod<T>::pod>::swap( table[i], table[j] );
	}

	~Vect()
	{
		delete[] table;
	}

private:
	unsigned int vec_size;
	T* table;

};

#endif //MAIN_H