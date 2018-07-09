#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <deque>

template<class T = int, template <class U = T, class Allocator = std::allocator<T> > class StorageType = std::deque >
class fifo
{
public:
	using storage_type = StorageType<T>;

	fifo()
	{
		std::cout<< __PRETTY_FUNCTION__ << std::endl;
	}

    void push(const T& a)
    {
    	container.push_back(a);
    }

    T get()
    {
        T temp = container.front();
        container.pop_front();
        return temp;
    }
    
    unsigned size() const
    {
        return container.size();
    }    

    typename storage_type::const_iterator begin()
    {
        return container.begin();
    }

    typename storage_type::const_iterator end()
    {
    	return container.end();
    }
    
private:
    StorageType<T> container;
};

#endif // FIFO_H
