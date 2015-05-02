#include"num_sequence.h"
#include<typeinfo>
using namespace std;

bool num_sequence::check_intergrity(int pos,int size) const
{
	if (pos <= 0 || pos > max_elems())
	{
		cerr << "!!invalid position: " << pos
			<< "Cannot hornor request\n";
		return false;
	}
	if (pos > size)
		gen_elems(pos);
	return true;
}
inline const char* num_sequence::
what_am_i() const
{
	return typeid(*this).name();
}
