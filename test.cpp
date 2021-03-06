#include <cassert>
#include <cmath>


template<int x,int n = 100>
class const_sqrt
{
public:
static const double value = (const_sqrt<x,n-1>::value + x/const_sqrt<x,n-1>::value)/2 ;
};
template<int x>
class const_sqrt< x , 0 >
{
public:
static const double value = 1;
};

int main()
{
assert(std::abs(const_sqrt<1>::value - std::sqrt(1)) < 0.000000001);
assert(std::abs(const_sqrt<2>::value - std::sqrt(2)) < 0.000000001);
assert(std::abs(const_sqrt<10>::value - std::sqrt(10)) < 0.000000001);
assert(std::abs(const_sqrt<47>::value - std::sqrt(47)) < 0.000000001);
assert(std::abs(const_sqrt<4225>::value - std::sqrt(4225)) < 0.000000001);
return 0;
}
