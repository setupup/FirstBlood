#include"Fibonacci.h"
using namespace std;
template<int length, int beg_pos>
vector<int> Fibonacci<length, beg_pos>::_elems;

template<int length,int beg_pos>
void Fibonacci<length, beg_pos>::
gen_elems(int pos) const
{
	if (pos <= 0 || pos > max_elems())
		return;
	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(1);
	}
	if (_elems.size() <= pos)
	{
		int ix = _elems.size();
		int n_2 = _elems[ix - 2],
		n_1 = _elems[ix - 1];
		int elem;
		for (; ix <= pos; ++ix)
		{
			elem = n_2 + n_1;
			_elems.push_back(elem);
			n_2 = n_1;
			n_1 = elem;
		}
	}
		

}