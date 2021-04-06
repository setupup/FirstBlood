#include"Fibonacci.h"

#include<iostream>
using namespace std;
ostream& operator<<(ostream& os, const num_sequence& ns)//resolution
{
	return ns.print(os);
}
inline void display(ostream& os, const num_sequence& ns, int pos)
{
	os << "The element at position"
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}
int main() //occur some problems when we use the overload operator// problem solved
{
	//Fibonacci fib;
	//cout << "fib: beginning at element 1 for 1 element: "
	//	<< fib << endl;

	//Fibonacci fib2(16);
	//cout << "fib2: beginning at element 1 for 16 elements: "
	//	<< fib2 << endl;
	//Fibonacci fib3(8, 12);
	//cout << "fib3: beginning at element 12 for 8 elements: "
	//	<< fib3 << endl;

	const int pos = 8;
	Fibonacci fib;
	display(cout, fib, pos);
}