#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

template<typename T>
class DynArray
{
public:
	DynArray(int n_size)
	:array_size(n_size)
	{
		table = new T[array_size];
	}
	
	DynArray(int n_size,const T* table_pointer)
	{
		array_size = n_size;
		table = new T[array_size];

		for (int i = 0; i < n_size; ++i)
		{
			table[i] = table_pointer[i];
		}
	}

	~DynArray()
	{
		delete[] table;
	}

	T& operator[](int index)
	{
		return table[index];
	}

	int size() const
	{
		return array_size;
	}

	friend std::ostream& operator <<(std::ostream& output, const DynArray<T>& object)
	{
		if(object.size() > 0)
		{
			output << "{\"" << object.table[0] << "\"";
			for (int i = 1; i < object.size(); ++i)
			{
				output << ",\"" << object.table[i] << "\"";
			}
			output << "}";
			return output;
		}
		else
		{
			output << "{ }";
			return output;
		}
	}

	class Iterator
	{
	public:
		Iterator(T* n_pointer)
		{
			pointer = n_pointer;
		}

		T* operator ->()
		{
			return pointer;
		}

		void operator++()
		{
			++pointer;
		}

		void append(const std::string& to_sum)
		{
			*pointer += to_sum;
		}

		bool operator !=(const T& second)
		{
			if(pointer != second)
				return true;
			else
				return false;
		}

		const T& operator *() const
		{
			return *pointer;
		}

		operator T*() const
		{
			return pointer;
		}

	private:
		T* pointer;
	};

	Iterator begin() const
	{
		return table;
	}

	Iterator end() const
	{
		return &table[array_size];
	}

private:
	int array_size;
	T* table;
	
};



#endif