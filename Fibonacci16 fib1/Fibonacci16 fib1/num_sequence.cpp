#include"num_sequence.h"
#include<typeinfo>
using namespace std;
template<int len,int beg_pos>::
elem(int pos) const
{
	if (!check_integrity(pos, _pelems->size()))
		return 0;
	return (*_pelems)[pos - 1];
}
template<int length,int beg_pos>
const char* num_sequence<length,beg_pos>::
what_am_i() const
{
	return typeid(*this).name();
}
template<int length,int beg_pos>
bool num_sequence<length,beg_pos>::
check_integrity(int pos, int size) const
{
	if (pos <= 0 || pos > max_elems())
	{
		cerr << "!! invalid position: " << pos
			<< "Cannot honor request\n";
		return false;
	}
	if (pos > size) gen_elems(pos);
	return true;
}
template<int length,int beg_pos>
ostream& num_sequence<length,beg_pos>::
print(ostream& os) const
{
	int elem_pos = beg_pos - 1;
	int end_pos = elem_pos + length;
	if (!check_integrity(end_pos, _pelems->size()))
		return os;
	os << "("
		<< beg_pos << " , " //here we got to use the parameters
		<< length << ")";
	while (elem_pos < end_pos)
		os << (*_pelems)[elem_pos++] << ' ';
	return os;
}
