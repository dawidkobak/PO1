#include <type_traits> 
#include "copy.h"
#include <vector>
#include <deque>

struct A {};
struct A_{virtual ~A_ () {}};

int main()
{
	std::integral_constant<bool, true> tA = std::is_pod<A>::type();
	std::integral_constant<bool, false> tA_ = std::is_pod<A_>::type();

	std::deque<A> vA1;
	std::vector<A> vA2;
	my_copy(vA1.begin(), vA1.end(), vA2.begin());

	std::vector<A_> vA_1;
	std::deque<A_> vA_2;
	my_copy(vA_1.begin(), vA_1.end(), vA_2.begin());
}
