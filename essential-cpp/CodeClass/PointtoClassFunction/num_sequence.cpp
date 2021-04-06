#include"num_sequence.h"
#include<vector>
using namespace std;
const int num_sequence::num_seq; //have already assigned
vector<vector<int>> num_sequence::seq(num_seq);

num_sequence::PtrType
num_sequence::func_tbl[num_seq] =
{
	0,
	&num_sequence::fibonacci, //the name of each function has become a object, we must use the &to obtain the address, this is different from the non-member(class) funciton
	&num_sequence::pell,
	&num_sequence::lucas,
	&num_sequence::triangular,
	&num_sequence::square,
	&num_sequence::pentagonal //pm=&fibonacci   (ns.*pm)()//must use the object plus () when use
};

int num_sequence::elem(int pos)
{
	if (!check_integrity(pos))
		return 0;
	if (pos > _elem->size())
		(this->*_pmf)(pos);
	return (*_elem)[pos - 1];
}