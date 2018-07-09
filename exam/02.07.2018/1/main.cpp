#include "conv.h"

int main()
{
	Derived1 d1;
	Derived3 d3;
	Derived2 d2 = d3;
	//Derived1 __error1 = d2;

	std::vector<Base*> v {&d1, &d2, &d3};
	//std::vector<Base> __error2 {d1,d2, d3};
	std::cout << *v.front() << "\n";
	std::cout << v;

	return 0;
}

/*
output:
virtual std::ostream& Derived1::print(std::ostream&) const
[
virtual std::ostream& Derived1::print(std::ostream&) const,
virtual std::ostream& Derived2::print(std::ostream&) const,
virtual std::ostream& Derived3::print(std::ostream&) const,
]

*/