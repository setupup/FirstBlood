#include"Triangular.h"
#include<iostream>
using namespace std;

//Triangular::Triangular(int len, int bp)
//{
//	_length = len > 0 ? len : 1;
//	_beg_pos = bp > 0 ? bp : 1;
//	_next = _beg_pos - 1;
//}
//init list
Triangular::Triangular(const Triangular& rhs)
: _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos),_name("Triangular") //nothing here
{}//is empty here! if need other operation, also could write it here
vector<int> Triangular::_elems;//obvious explicit definition
Triangular::Triangular(int len, int beg_pos)
:_length(len > 0 ? len : 1), _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos - 1;
	int elem_cnt = _beg_pos + _length - 1;
	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}
bool Triangular::is_elem(int value)
{
	if (!_elems.size() ||
		_elems[_elems.size() - 1] < value)
		gen_elems_to_value(value);
	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();
	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}
void Triangular::gen_elems_to_value(int value)
{
	int ix = _elems.size();
	if (!ix)
	{
		_elems.push_back(1);
		ix = 1;
	}
	while (_elems[ix - 1] < value&&ix < _max_elems)
	{
		++ix;
		_elems.push_back(ix*(ix + 1) / 2);
	}
	if (ix == _max_elems)
		cerr << "Triangular Sequence: oops: value too large"
		<< value << "--exceeds max size of" << _max_elems << endl;
}
void Triangular::gen_elements(int length)
{
	if (length<0 || length>_max_elems)
	{
		//error and return
	}
	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size() + 1 : 1;
		for (; ix <= length; ++ix)
		{
			_elems.push_back(ix*(ix + 1) / 2);
		}
	}
}
int main()
{
	char ch;
	bool more = true;

	while (more)
	{
		cout << "Enter value:";
		int ival;
		cin >> ival;

		bool is_elem = Triangular::is_elem(ival);
		cout << ival
			<< (is_elem ? "is" : "is not")
			<< "an element in the Triangular series.\n"
			<< "another value?(y/n)";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			more = false;

	}
}

inline int operator*(const Triangular_iterator& rhs)
{
	rhs.check_integrity();
	return Triangular::_elems[rhs.index()];
}