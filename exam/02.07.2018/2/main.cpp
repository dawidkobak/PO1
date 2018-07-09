#include "fifo.h"

namespace std 
{ 
	class queue{}; 
}

int main()
{
	fifo<> f;
	for(int i: {0,1,2,3,4})
	f.push(i);

	fifo<int, std::deque> ff = f;

	std::cout << f.get() << std::endl;
	std::cout << f.size() << std::endl;

	for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
		std::cout << *i << ",";
}

/*
fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
0
4
1,2,3,4,
*/