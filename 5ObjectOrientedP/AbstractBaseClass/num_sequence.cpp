#include"num_sequence.h"

bool num_sequence::check_intergrity(int pos,int size) const
{
	if (pos <= 0 || pos > _max_elems)
	{
		cerr << "!!invalid position: " << pos
			<< "Cannot hornor request\n";
		return false;
	}
	if (pos > size)
		gen_elems(pos);
	return true;
}
