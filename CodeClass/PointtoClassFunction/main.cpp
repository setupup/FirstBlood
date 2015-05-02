#include<iostream>
#include"num_sequence.h"
using namespace std;
int main()
{
	num_sequence ns; //common sequence class
	const int pos = 8;
	for (int ix = 1; ix < num_sequence::num_of_sequence(); ++ix)
	{
		ns.set_sequence(num_sequence::ns_type(ix));
		int elem_val = ns.elem(pos);
		display(cout, ns, pos, elem_val);
	}
	//typedef void (num_sequence::*PtrType)(int);
	//PtrType pm = 0; easy define the function pointer
}