namespace std { class auto_ptr{}; class unique_ptr{}; class shared_ptr{}; }
#include "ptr.h"
#include <iostream>

struct A{int i = 1;};

int main()
{
	const ptr<A> a(new A);
	const ptr<A> b;
	ptr<A> c(new A);

	// ptr<A> _b_error = new A;
	// a = a;
	// const ptr<A> _c_error = a;

	std::cout << ((*a).i, a->i) << " " << ++c->i << " ";
	std::cout << (a == ptr<A>()) << " " << (a != b) << "\n";
}